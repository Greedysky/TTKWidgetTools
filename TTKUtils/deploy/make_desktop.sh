#!/bin/sh

path=share/applications
if [ ! -d $path ]; then
  mkdir $path
fi

datapath=$path/TTKWidgetTools.desktop
packpath="$PWD/$datapath"
userpath=~/.local/$datapath
iconpath="$PWD/share/pixmaps/ttkwidgettools.png"
execpath="$PWD/../TTKWidgetTools"

echo -n "[Desktop Entry]
Type=Application
Version=3.0.0.0
Name=TTKWidgetTools
Name[zh_CN]=QWidget自定义控件集合
Name[zh_TW]=QWidget自定義控件集合
GenericName=TTKWidgetTools
GenericName[zh_CN]=QWidget自定义控件集合
GenericName[zh_TW]=QWidget自定義控件集合
Comment=TTKWidgetTools
Comment[zh_CN]=QWidget自定义控件集合
Comment[zh_TW]=QWidget自定義控件集合
Icon=$iconpath
Exec=$execpath
Terminal=false
Keywords=widget;
Categories=widget;Qt;
MimeType=
X-KDE-StartupNotify=false\n" > $packpath

cp -rv $packpath $userpath
chmod +x $userpath
