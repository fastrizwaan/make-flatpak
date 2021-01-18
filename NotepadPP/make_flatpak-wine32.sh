#!/bin/bash
# Script that was used to build this package. Enjoy
# make_flatpak-wine32.sh AppName AppDirectory/ executable.exe # exe from AppDirectory/App.exe

# Icon: 1st install the program using wine 
# then copy the icon to the 
# cp '~/.local/share/icons/hicolor/256x256/apps/0DE1_FontLab 7.0.png' FontLab7/icon.png

# before running this program, also remove Spaces in folder and exe names, 
# example Fontlab\ 7 to Fontlab7 and Fontlab\ 7.exe to Fontlab7.exe
# This wine is i386 with 5.0.3 stable built using 
# install sdk
##flatpak install flathub org.freedesktop.Platform/i386/18.08 org.freedesktop.Sdk/x86_64/18.08
##flatpak install flathub org.freedesktop.Platform/i386/18.08 org.freedesktop.Sdk/i386/18.08
#get json file from 
#https://github.com/johnramsden/pathofexile-flatpak/blob/master/ca.johnramsden.pathofexile.json

#build to create files (wine32 bit)
#flatpak-builder build-dir ca.johnramsden.pathofexile.json
#copy the files directory from build-dir to current directory

#Output
echo "1.  Cleaning up previous target		[x]"

#remove target 
rm -rf ./target/


ARGV="$@" ; #saving program creation as commandline.sh

NAME="$1"; shift ;#PROGRAM Name eg. NotepadPP ('+' symbol in Program name like Notepad++ causes error)
APP="$1"; shift  ;#Program directory NotepadPP/ (copied from installed ~/.wine/...)
EXE="$1"; shift  ;#Exe program notepad++.exe, inside subdirectory of $APP i.e., Notepadpp/

NICE_NAME=$(echo $(echo "$NAME" | sed 's/[A-Z]/ \0/g'))
DOT_NAME=$(echo "$NICE_NAME" | tr " " . )
WINEEXE="/app/bin/wine"
ARCH="i386"
WINEVERSION="wine32-5.0.3"
#WINEVERSION="wine32-6.0.0"

#Output
echo "2.  Creating new target directory	[x]"

mkdir -p target/package/files/bin
mkdir -p target/package/files/lib
mkdir -p target/package/export/share/applications
mkdir -p target/package/export/share/icons/hicolor/48x48/apps/
mkdir -p target/\[flatpak-wine32\]$DOT_NAME

#Output
echo "3.  Creating run.sh script for sandbox	[x]"

cat << EOF > target/package/files/bin/run.sh
#!/bin/bash
mkdir -p /tmp/wine.$$.prefix/
export WINEPREFIX=~/.local/share/flatpak-wine32/$NAME/
export WINEDLLOVERRIDES="mscoree=d;mshtml=d;"
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH:/app/lib:/app/$NAME:/app/lib/wine

export WINEEXE="$WINEEXE"

cd "/app/$(basename "$APP")"

if [ -e flatpak-wine32.md ] ; then
	cat flatpak-wine32.md | sed -e "s|FLATPAKNAME|org.flatpakwine32.$NAME|" -e "s|WINEPREFIX|\$WINEPREFIX|"
fi

if [ -e flatpak-wine32.reg ] ; then
	$WINEEXE regedit /C flatpak-wine32.reg
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
#	touch ~/.local/share/flatpak-wine32/$NAME/dxsetup-done.txt
else
# Enable the lines below if dxsetup openal and vcredist is required or 
# run ./run.sh dxsetup
#	if [ ! -f ~/.local/share/flatpak-wine32/$NAME/dxsetup-done.txt ];
#	   then
#           $WINEEXE /app/$APP/_CommonRedist/DirectX/Jun2010/DXSETUP.exe /SILENT
#	   $WINEEXE /app/$APP/_CommonRedist/vcredist/2010/vcredist_x86.exe /SILENT
#	   $WINEEXE /app/$APP/_CommonRedist/vcredist/2012/vcredist_x86.exe /SILENT
#	   touch ~/.local/share/flatpak-wine32/$NAME/dxsetup-done.txt
#        fi

	$WINEEXE "$EXE" \$@
	exit $?
fi
EOF


echo "4.  Creating flatpak metadata 		[x]"

cat << EOF >target/package/metadata
[Application]
name=org.flatpakwine32.$NAME
runtime=org.freedesktop.Platform/$ARCH/18.08
command=run.sh

[Context]
features=devel;multiarch;
shared=network;ipc;
sockets=x11;pulseaudio;
devices=all;
filesystems=xdg-documents;~/.local/share/flatpak-wine32/:create
EOF

echo "5.  Creating flatpak install script	[x]"

cat << EOF >target/\[flatpak-wine32\]$DOT_NAME/install.sh
#!/bin/bash
# Installs game bundle for user.
# You can delete everything after installation.

DIR=\$(dirname "\$0")
set -ex
flatpak --user remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo || true
flatpak --user install -y --app --bundle "\$DIR/$NAME.flatpak" || echo "Installation failed. Check if you have Flatpak properly configured. See http://flatpak.org/ for more info."
EOF

echo "6.  Creating flatpak uninstall script	[x]"
cat << EOF >target/\[flatpak-wine32\]$DOT_NAME/uninstall.sh
#!/bin/bash
# You can as well use package manager to uninstall the game
echo You can as well use package manager to uninstall the game

set -ex
flatpak --user uninstall org.flatpakwine32.$NAME
EOF

echo "7.  Creating flatpak run script		[x]"
cat << EOF >target/\[flatpak-wine32\]$DOT_NAME/run.sh
#!/bin/bash
set -ex
flatpak run org.flatpakwine32.$NAME \$@
EOF

echo "8.  Creating desktop shortcut 		[x]"
cat << EOF >target/package/export/share/applications/org.flatpakwine32.$NAME.desktop
[Desktop Entry]
Version=1.0
Name=$NICE_NAME
Exec=run.sh
Icon=org.flatpakwine32.$NAME
StartupNotify=true
Terminal=false
Type=Application
Categories=Game;
EOF

echo "9.  Copying icon file	 		[x]"
# If custom icon.png is provided by the flatpak maker
#set -ex
## adding ImageMagicks's convert for different icon support for non gnome desktops
if [ -e "$APP"/icon.png ]; then 
   cp "$APP"/icon.png \
   target/package/export/share/icons/hicolor/48x48/apps/org.flatpakwine32.$NAME.png;
else
   echo "    Extracting icon from $EXE file"
   # Extract Icon and copy
   # dnf install icoutils ImageMagick
   wrestool -x --output=. -t14 "$APP"/"$EXE" ; #extracts ico file
   convert "*.ico" "hello.png"; #this will get ping files as hello-0...hellol7.png

   #hello-0.png is the highest resolution 256x256 (some has 48x48)
   #so copy hello-0.png as icon
   cp hello-0.png target/package/export/share/icons/\
hicolor/48x48/apps/org.flatpakwine32.$NAME.png;

fi


#remove ico and png files
rm -f hello-?.png $EXE*.ico

echo "10. Copying all files 	 		[x]"
cp -rd "$APP" target/package/files/
#32 bit wine files are copied to 
cp -rf ../$WINEVERSION/* target/package/files

chmod +x target/package/files/bin/run.sh
chmod +x target/\[flatpak-wine32\]$DOT_NAME/install.sh
chmod +x target/\[flatpak-wine32\]$DOT_NAME/uninstall.sh
chmod +x target/\[flatpak-wine32\]$DOT_NAME/run.sh
cp "$0" target/package/files/make_flatpak-wine32.sh
echo "$0" "$ARGV" > target/package/files/commandline.sh

echo "11. Building flatpak 			[x]"
flatpak build-export target/repo target/package
flatpak build-bundle --arch=$ARCH target/repo target/\[flatpak-wine32\]$DOT_NAME/$NAME.flatpak org.flatpakwine32.$NAME

echo "12. Flatpak made! 			[x]"
