#!/bin/sh

username=`logname`
if [ "${username}" = "root" ]; then
  homepath=/root
else
  homepath=/home/${username}
fi

rm -rf /opt/TTKWidgetTools
rm -f ${homepath}/.local/share/applications/TTKWidgetTools.desktop
