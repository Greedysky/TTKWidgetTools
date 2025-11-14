#!/bin/sh

packpath="$1"
iconpath="$2"
execpath="$3"

echo -n "[Desktop Entry]
Type=Application
Version=1.0
Name=TTKWidgetTools
Name[zh_CN]=TTK控件集合
Name[zh_TW]=TTK控件集合
GenericName=TTKWidgetTools
GenericName[zh_CN]=TTK控件集合
GenericName[zh_TW]=TTK控件集合
Comment=TTKWidgetTools
Comment[zh_CN]=QWidget自定义控件集合
Comment[zh_TW]=QWidget自定義控件集合
Icon=${iconpath}
Exec=${execpath}
Terminal=false
Keywords=widget;
Categories=Utility;Qt;
MimeType=
X-KDE-StartupNotify=false\n" > ${packpath}
