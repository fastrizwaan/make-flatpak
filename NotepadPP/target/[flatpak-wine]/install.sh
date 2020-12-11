#!/bin/bash
# Installs game bundle for user.
# You can delete everything after installation.

DIR=$(dirname "$0")
set -ex
flatpak --user remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo || true
flatpak --user install -y --app --bundle "$DIR/.flatpak" || echo "Installation failed. Check if you have Flatpak properly configured. See http://flatpak.org/ for more info."
