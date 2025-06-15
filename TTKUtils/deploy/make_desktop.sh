#!/bin/sh

curpath=$PWD/deploy
if [ $# -eq 0 ]; then
  curpath=$PWD
fi

path=$curpath/share/applications
if [ ! -d $path ]; then
  mkdir $path
fi

packpath=$path/TTKWidgetTools.desktop
userpath=~/.local/share/applications
iconpath="$curpath/share/pixmaps/ttkwidgettools.png"
execpath="$curpath/../TTKWidgetTools"

echo -n "[Desktop Entry]
Type=Application
Version=3.1.0.0
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
