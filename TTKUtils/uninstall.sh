#!/bin/sh

username=`logname`
if [ -z "${username}" ]; then
  username=`whoami`
fi

if [ "${username}" = "root" ]; then
  homepath=/root
else
  homepath=/home/${username}
fi

rm -rf /opt/ttk/TTKWidgetTools
rm -f ${homepath}/.local/share/applications/TTKWidgetTools.desktop
rm -f ${homepath}/.local/share/metainfo/ttkwidgettools.metainfo.xml
