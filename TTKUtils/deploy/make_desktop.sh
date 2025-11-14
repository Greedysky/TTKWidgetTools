#!/bin/sh

dirpath=`dirname $0`
tmp="${dirpath#?}"

if [ "${dirpath%${tmp}}" != "/" ]; then
  dirpath=$PWD/${dirpath}
fi

username=`logname`
if [ "${username}" = "root" ]; then
  homepath=/root
else
  homepath=/home/${username}
fi

packpath=${dirpath}/TTKWidgetTools.desktop
userpath=${homepath}/.local/share/applications
iconpath="${dirpath}/share/pixmaps/ttkwidgettools.png"
execpath="${dirpath}/../3.1.0.0/TTKWidgetTools.sh"

sh ${dirpath}/make_desktop_raw.sh ${packpath} ${iconpath} ${execpath}

mv -fv ${packpath} ${userpath}
chmod +x ${userpath}
