#!/bin/sh

dirpath=`dirname $0`
tmp="${dirpath#?}"

if [ "${dirpath%${tmp}}" != "/" ]; then
  dirpath=$PWD/${dirpath}
fi

deskpath=${dirpath}/share/applications
if [ ! -d ${deskpath} ]; then
  mkdir -p ${deskpath}
fi

username=`logname`
if [ "${username}" = "root" ]; then
  homepath=/root
else
  homepath=/home/${username}
fi

packvern=3.1.0.0
packpath=${deskpath}/TTKWidgetTools.desktop
userpath=${homepath}/.local/share/applications
iconpath="${dirpath}/share/pixmaps/ttkwidgettools.png"
execpath="${dirpath}/../${packvern}/TTKWidgetTools.sh"

echo -n "[Desktop Entry]
Type=Application
Version=${packvern}
Name=TTKWidgetTools
Name[zh_CN]=QWidget自定义控件集合
Name[zh_TW]=QWidget自定義控件集合
GenericName=TTKWidgetTools
GenericName[zh_CN]=QWidget自定义控件集合
GenericName[zh_TW]=QWidget自定義控件集合
Comment=TTKWidgetTools
Comment[zh_CN]=QWidget自定义控件集合
Comment[zh_TW]=QWidget自定義控件集合
Icon=${iconpath}
Exec=${execpath}
Terminal=false
Keywords=widget;
Categories=widget;Qt;
MimeType=
X-KDE-StartupNotify=false\n" > ${packpath}

cp -rv ${packpath} ${userpath}
chmod +x ${userpath}
