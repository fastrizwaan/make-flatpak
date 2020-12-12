#!/bin/bash
# Script that was used to build this package. Enjoy
# make_flatpak-wine.sh AppName /AppDirectory executable.exe # exe from AppDirectory/App.exe

# Icon: 1st install the program using wine 
# then copy the icon to the 
# cp '~/.local/share/icons/hicolor/256x256/apps/0DE1_FontLab 7.0.png' FontLab7/icon.png

# before running this program, also remove Spaces in folder and exe names, 
# example Fontlab\ 7 to Fontlab7 and Fontlab\ 7.exe to Fontlab7.exe
# This wine is i386 with 5.0.3 stable built using 
# install sdk
##flatpak install flathub org.freedesktop.Platform/i386/18.08 org.freedesktop.Sdk//18.08
##flatpak install flathub org.freedesktop.Platform/i386/18.08 org.freedesktop.Sdk/i386/18.08
#get json file from 
#https://github.com/johnramsden/pathofexile-flatpak/blob/master/ca.johnramsden.pathofexile.json

#build to create files (wine 32 bit)
#flatpak-builder build-dir ca.johnramsden.pathofexile.json
#copy the files directory from build-dir to current directory


NAME="$1"; shift
APP="$1"; shift
EXE="$1"; shift

NICE_NAME=$(echo $(echo "$NAME" | sed 's/[A-Z]/ \0/g'))
DOT_NAME=$(echo "$NICE_NAME" | tr " " . )
WINEEXE="/app/bin/wine"
ARCH="i386"

mkdir -p target/package/files/bin
mkdir -p target/package/files/lib
mkdir -p target/package/export/share/applications
mkdir -p target/package/export/share/icons/hicolor/48x48/apps/
mkdir -p target/\[flatpak-wine\]$DOT_NAME

cat << EOF > target/package/files/bin/run.sh
#!/bin/bash
mkdir -p /tmp/wine.$$.prefix/
export WINEPREFIX=~/.local/share/flatpak-wine/$NAME/
export WINEDLLOVERRIDES="mscoree=d;mshtml=d;"
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH:/app/lib:/app/$NAME:/app/lib/wine

export WINEEXE="$WINEEXE"

cd "/app/$(basename "$APP")"

if [ -e flatpak-wine.md ] ; then
	cat flatpak-wine.md | sed -e "s|FLATPAKNAME|org.flatpakwine.$NAME|" -e "s|WINEPREFIX|\$WINEPREFIX|"
fi

if [ -e flatpak-wine.reg ] ; then
	$WINEEXE regedit /C flatpak-wine.reg
fi


if [ "\$1" == "winecfg" ] ; then
	$WINEEXE winecfg
elif [ "\$1" == "regedit" ] ; then
	$WINEEXE regedit
elif [ -e run.sh ] ; then
	sh run.sh \$@
	exit $?
elif [ "\$1" == "bash" ] ; then
	bash 
#elif [ "\$1" == "dxsetup" ] ; then
#	   $WINEEXE /app/$APP/_CommonRedist/DirectX/Jun2010/DXSETUP.exe /SILENT
#	   $WINEEXE /app/$APP/_CommonRedist/vcredist/2010/vcredist_x86.exe /SILENT
#	   $WINEEXE /app/$APP/_CommonRedist/vcredist/2012/vcredist_x86.exe /SILENT
#
#	touch ~/.local/share/flatpak-wine/$NAME/dxsetup-done.txt
else
# Enable the lines below if dxsetup openal and vcredist is required or 
# run ./run.sh dxsetup
#	if [ ! -f ~/.local/share/flatpak-wine/$NAME/dxsetup-done.txt ];
#	   then
#           $WINEEXE /app/$APP/_CommonRedist/DirectX/Jun2010/DXSETUP.exe /SILENT
#	   $WINEEXE /app/$APP/_CommonRedist/vcredist/2010/vcredist_x86.exe /SILENT
#	   $WINEEXE /app/$APP/_CommonRedist/vcredist/2012/vcredist_x86.exe /SILENT
#	   touch ~/.local/share/flatpak-wine/$NAME/dxsetup-done.txt
#        fi

	$WINEEXE "$EXE" \$@
	exit $?
fi
EOF

cat << EOF >target/package/metadata
[Application]
name=org.flatpakwine.$NAME
runtime=org.freedesktop.Platform/$ARCH/18.08
command=run.sh

[Context]
features=devel;multiarch;
shared=network;ipc;
sockets=x11;pulseaudio;
devices=all;
filesystems=xdg-documents;~/.local/share/flatpak-wine/:create
EOF


cat << EOF >target/\[flatpak-wine\]$DOT_NAME/install.sh
#!/bin/bash
# Installs game bundle for user.
# You can delete everything after installation.

DIR=\$(dirname "\$0")
set -ex
flatpak --user remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo || true
flatpak --user install -y --app --bundle "\$DIR/$NAME.flatpak" || echo "Installation failed. Check if you have Flatpak properly configured. See http://flatpak.org/ for more info."
EOF

cat << EOF >target/\[flatpak-wine\]$DOT_NAME/uninstall.sh
#!/bin/bash
# You can as well use package manager to uninstall the game
echo You can as well use package manager to uninstall the game

set -ex
flatpak --user uninstall org.flatpakwine.$NAME
EOF

cat << EOF >target/\[flatpak-wine\]$DOT_NAME/run.sh
#!/bin/bash
set -ex
flatpak run org.flatpakwine.$NAME \$@
EOF

cat << EOF >target/package/export/share/applications/org.flatpakwine.$NAME.desktop
[Desktop Entry]
Version=1.0
Name=$NICE_NAME
Exec=run.sh
Icon=org.flatpakwine.$NAME
StartupNotify=true
Terminal=false
Type=Application
Categories=Game;
EOF


set -ex
[ -e "$APP"/icon.png ] && cp "$APP"/icon.png target/package/export/share/icons/hicolor/48x48/apps/org.flatpakwine.$NAME.png
cp -rd "$APP" target/package/files/
#cp -r $WINE/bin $WINE/$LIB $WINE/share target/package/files/
cp -rp ../files/ target/package/

chmod +x target/package/files/bin/run.sh
chmod +x target/\[flatpak-wine\]$DOT_NAME/install.sh
chmod +x target/\[flatpak-wine\]$DOT_NAME/uninstall.sh
chmod +x target/\[flatpak-wine\]$DOT_NAME/run.sh
cp "$0" target/package/files/flatpak-make

flatpak build-export target/repo target/package
flatpak build-bundle --arch=$ARCH target/repo target/\[flatpak-wine\]$DOT_NAME/$NAME.flatpak org.flatpakwine.$NAME


