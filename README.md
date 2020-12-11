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
ls
target/\[flatpak-wine\]Notepadpp/
install.sh  Notepadpp.flatpak  run.sh  uninstall.sh
```
just run `./install.sh && ./run.sh` 

### Build wine from sources
if you want to build from sources:
#This wine is i386 with 5.0.3 stable built using 
```
flatpak install flathub org.freedesktop.Platform/i386/18.08 org.freedesktop.Sdk/i386/18.08
```
#### get json file from 
`ca.johnramsden.pathofexile.json` #modified by me for wine 5.0.3

#### build to create files (wine 32 bit)
flatpak-builder build-dir ca.johnramsden.pathofexile.json
#copy the files directory from build-dir to current directory

We can delete the `./build-dir/files/lib/debug` to save `100MB` size

