flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
flatpak install flathub org.freedesktop.Platform/i386/18.08 org.freedesktop.Sdk/i386/18.08 -y
flatpak install flathub org.freedesktop.Platform/x86_64/18.08 org.freedesktop.Sdk/x86_64/18.08 -y

wget https://notepad-plus-plus.org/repository/7.x/7.0/npp.7.Installer.x64.exe
WINEARCH=win64 wine npp.7.Installer.x64.exe
cp ~/.wine/drive_c/Program\ Files/Notepad* . -rv 
mv Notepad++/ NotepadPP

#copy icons
cp ~/.local/share/icons/hicolor/256x256/apps/*notepad++*.png NotepadPP/icon.png

./make_flatpak-wine64.sh NotepadPP NotepadPP/ notepad++.exe
cd target/\[flatpak-wine64\]Notepad.P.P/
./install.sh
./run.sh

