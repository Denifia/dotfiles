#!/bin/bash

# https://github.com/jtroo/kanata/discussions/130

# ==============================================================================
# Script to update Kanata config
# ==============================================================================

# CONFIGURATION
#
# REQUIRED: Set the path to your Kanata config relative to $HOME.
# E.g., if your config is at ~/somewhere/my-kanata.kbd, use "somewhere/my-kanata.kbd".
KANATA_CONFIG_REL_PATH=".keyboard/kanata/denifia.kbd"

# System location where the kanata config file will be placed
# (DO NOT EDIT)
SYSTEM_KANATA_CONFIG_DST="/etc/kanata/kanata-config.kbd"

# Dedicated user/group names
KANATA_USER="kanata"
UINPUT_GROUP="uinput"

# FUNCTION TO PRINT MESSAGES
echoinfo() {
    echo "[INFO] $1"
}
echoerror() {
    echo "[ERROR] $1" >&2
}

# CHECK FOR ROOT/SUDO
if [ "$(id -u)" -ne 0 ]; then
  echoerror "This script must be run with sudo or as root."
  exit 1
fi

# DETERMINE SOURCE CONFIG FILE PATH
# Try finding it relative to the current $HOME (might be /root if using sudo)
USER_KANATA_CONFIG_SRC="$HOME/$KANATA_CONFIG_REL_PATH"

# If not found AND we are using sudo, try finding it relative to the original user's $HOME
if [ ! -f "$USER_KANATA_CONFIG_SRC" ] && [ -n "$SUDO_USER" ]; then
    echoinfo "Config not found via current HOME ($HOME), attempting lookup via SUDO_USER ($SUDO_USER)..."
    SUDO_USER_HOME=$(getent passwd "$SUDO_USER" | cut -d: -f6)

    if [ -z "$SUDO_USER_HOME" ]; then
         echoerror "Could not determine home directory for user $SUDO_USER."
         exit 1
    fi

    ALT_CONFIG_PATH="$SUDO_USER_HOME/$KANATA_CONFIG_REL_PATH"
    echoinfo "Checking alternative path: $ALT_CONFIG_PATH"

    if [ -f "$ALT_CONFIG_PATH" ]; then
        echoinfo "Found config file using SUDO_USER: $ALT_CONFIG_PATH"
        # Update the variable to use the correctly found path
        USER_KANATA_CONFIG_SRC="$ALT_CONFIG_PATH"
    else
        # Config not found in either location
        echoerror "Kanata config file not found at initial path: $HOME/$KANATA_CONFIG_REL_PATH"
        echoerror "And also not found at alternative path: $ALT_CONFIG_PATH"
        echoerror "Please ensure the relative path '$KANATA_CONFIG_REL_PATH' exists in your home directory."
        exit 1
    fi
# If not found and not using sudo (or SUDO_USER not set), then it just doesn't exist
elif [ ! -f "$USER_KANATA_CONFIG_SRC" ]; then
    echoerror "Kanata config file not found at: $USER_KANATA_CONFIG_SRC"
    echoerror "Please ensure the relative path '$KANATA_CONFIG_REL_PATH' exists in your home directory ($HOME)."
    exit 1
fi

# If we reach here, USER_KANATA_CONFIG_SRC holds the validated path to the source config file
echoinfo "Using source config file: $USER_KANATA_CONFIG_SRC"

echoinfo "Starting Kanata hardened setup..."

#========================
# STEP 1: Prepare Config Directory & Copy Config
#========================
echoinfo "Creating directory /etc/kanata..."
mkdir -p /etc/kanata

echoinfo "Copying Kanata config from $USER_KANATA_CONFIG_SRC to $SYSTEM_KANATA_CONFIG_DST..."
cp "$USER_KANATA_CONFIG_SRC" "$SYSTEM_KANATA_CONFIG_DST"
if [ $? -ne 0 ]; then
    echoerror "Failed to copy config file. Please check permissions and paths."
    exit 1
fi

#========================
# STEP 2: Set Config Permissions
#========================
echoinfo "Setting permissions on $SYSTEM_KANATA_CONFIG_DST..."
chown root:"$KANATA_USER" "$SYSTEM_KANATA_CONFIG_DST"
chmod 640 "$SYSTEM_KANATA_CONFIG_DST"

echoinfo "-----------------------------------------------------"
echoinfo "Kanata update script finished!"
echoinfo "-----------------------------------------------------"

exit 0
