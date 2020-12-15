flatpak install flathub org.freedesktop.Sdk/x86_64/18.08
flatpak-builder build-dir --force-clean wine-json.yml 

# Now copy the files (wine64) to your flatpak-wine
mkdir ~/newflatpak -p ; 
cp build-dir/files ~/newflatpak/files64 -rv

