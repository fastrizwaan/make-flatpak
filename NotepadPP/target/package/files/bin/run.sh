#!/bin/bash
mkdir -p /tmp/wine.111175.prefix/
export WINEPREFIX=~/.local/share/flatpak-wine/Notepadpp/
export WINEDLLOVERRIDES="mscoree=d;mshtml=d;"
export LD_LIBRARY_PATH=/home/rizvan/.build/flatpak-wine/NotepadPP::/app/lib:/app/Notepadpp:/app/lib/wine

export WINEEXE="/app/bin/wine"

cd "/app/Notepadpp"

if [ -e flatpak-wine.md ] ; then
	cat flatpak-wine.md | sed -e "s|FLATPAKNAME|org.flatpakwine.Notepadpp|" -e "s|WINEPREFIX|$WINEPREFIX|"
fi

if [ -e flatpak-wine.reg ] ; then
	/app/bin/wine regedit /C flatpak-wine.reg
fi


if [ "$1" == "winecfg" ] ; then
	/app/bin/wine winecfg
elif [ "$1" == "regedit" ] ; then
	/app/bin/wine regedit
elif [ -e run.sh ] ; then
	sh run.sh $@
	exit 0
elif [ "$1" == "bash" ] ; then
	bash 
#elif [ "$1" == "dxsetup" ] ; then
#	   /app/bin/wine /app/Notepadpp//_CommonRedist/DirectX/Jun2010/DXSETUP.exe /SILENT
#	   /app/bin/wine /app/Notepadpp//_CommonRedist/vcredist/2010/vcredist_x86.exe /SILENT
#	   /app/bin/wine /app/Notepadpp//_CommonRedist/vcredist/2012/vcredist_x86.exe /SILENT
#
#	touch ~/.local/share/flatpak-wine/Notepadpp/dxsetup-done.txt
else
# Enable the lines below if dxsetup openal and vcredist is required or 
# run ./run.sh dxsetup
#	if [ ! -f ~/.local/share/flatpak-wine/Notepadpp/dxsetup-done.txt ];
#	   then
#           /app/bin/wine /app/Notepadpp//_CommonRedist/DirectX/Jun2010/DXSETUP.exe /SILENT
#	   /app/bin/wine /app/Notepadpp//_CommonRedist/vcredist/2010/vcredist_x86.exe /SILENT
#	   /app/bin/wine /app/Notepadpp//_CommonRedist/vcredist/2012/vcredist_x86.exe /SILENT
#	   touch ~/.local/share/flatpak-wine/Notepadpp/dxsetup-done.txt
#        fi

	/app/bin/wine "notepadpp.exe" $@
	exit 0
fi
