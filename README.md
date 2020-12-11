# flatpak-wine

Remember `[Flatpak-Linux]` bundles with make-flatpak.sh? flatpak-linux bundles required Playonlinux also many libraries like `libpng12.so` is not available with ubuntu and fedora. So, bundling windows apps using flatpak stopped working. Also `org.freedesktop.Platform 1.6` is in end-of-life.

`flatpak-wine` uses 32-bit wine-5.0.3 stable and org.freedesktop.Platform 18.08. Now using `make_flatpak-wine.sh` we can create wine bundles.

the `files` are actually compiled wine 32 bit with  from wine flatpak pathofexile json/yml file.

### Create a wine app bundle
```
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
flatpak install flathub org.freedesktop.Platform/i386/18.08 org.freedesktop.Sdk/i386/18.08
cd flatpak-wine/NotepadPP
sh ./commandline.sh
```
this will create create a directory `target/[flatpak-wine]/Notepadpp/`
```
ls target/\[flatpak-wine\]Notepadpp/
install.sh  Notepadpp.flatpak  run.sh  uninstall.sh
```
just run `./install.sh && ./run.sh` 

### Build wine from sources
if you want to build from sources:
#This wine is i386 with 5.0.3 stable built using 
```
dnf install flatpak-builder ;# use your distro specific package manager for flatpak-builder
flatpak install flathub org.freedesktop.Platform/i386/18.08 org.freedesktop.Sdk/i386/18.08
```
#### get json file from 

```
cd flatpak-wine/build-wine32-5.0.3
flatpak-builder build-dir ca.johnramsden.pathofexile.json
```
After compilation, we can use the `files` directory as `wine` directory of playonlinux.

####copy the files directory from build-dir to current directory
We can delete the `./build-dir/files/lib/debug` to save `100MB` size
```
rm -rf ./build-dir/files/lib/debug
```

#### To build a wine flatpak with (32 bit only)
install the windows installer with local wine, we just need the installed directory from `~/.wine/Program\ Files/<program>`
1st install with wine, then copy the directory and icon to a folder
```
#install program with 32bit wine
WINEARCH=win32 wine npp.7.9.1.Installer.exe

#create a directory to copy files, program direcotry and icon
mkdir ~/flatpak-mybuilds
cd ~/flatpak-mybuilds/

# copy "files directory" (wine)
cp ~/flatpak-wine/files . -r ; 
#or 
cp ~/flatpak-wine/build-wine32-5.0.3/build-dir/files . -r

# Create sub directory
mkdir MyNotepadPP;
cd MyNotepadPP

# copy the windows app
cp ~/.wine/drive_c/Program\ Files/Notepad++/ . -rv

# Renaming/removing spaces and special chars like '+'
mv Notepad++ Notepadpp
mv Notepadpp/notepad++.exe Notepadpp/notepadpp.exe

#copy the icon for flatpak
cp ~/.local/share/icons/hicolor/256x256/apps/1E64_notepad.0.png Notepadpp/icon.png

#copy files (wine) and make_flatpak-wine.sh to make the wine app bundle
cp ~/flatpak-wine/NotepadPP/*.sh . ;#from git repo

#let's build it, will take 7-10 minutes on SSD in i5 5470
./make_flatpak-wine.sh Notepadpp Notepadpp/ notepadpp.exe ;# or sh ./commandline.sh
```

####after it's built (Install flatpak)
```
cd 'target/[flatpak-wine]Notepadpp'
./install.sh
./run.sh
```
And don't forget to create a separate folder for each wine app inside `~/flatpak-mybuilds`; one app one folder.
