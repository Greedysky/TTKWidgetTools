#!/bin/sh

packname=TTKWidgetTools
packvern=3.2.0.0
rootpath=data/opt
datapath=data/DEBIAN

fullname=$1
if [ $# -eq 0 ]; then
  fullname=${packname}_${packvern}
fi

mkdir -p ${rootpath}
mkdir -p ${datapath}

# create control file
echo -n "Package: ${packname}
Version: ${packvern}
Section: multimedia
Priority: optional
Architecture: amd64
Installed-Size: $(du -s ${packname} | sed -e 's/[ \t].*//')
Maintainer: Greedysky <greedysky@163.com>
Homepage: https://github.com/Greedysky/${packname}
Description: TTK Qt自定义控件集合
 TTKWidgetTools 是基于 Qt 的自定义控件集合，支持Windows和Linux平台.\n" > ${datapath}/control

# create postinst file
echo -n "#!/bin/bash
sh /opt/${packname}/install.sh\n" > ${datapath}/postinst
chmod +x ${datapath}/postinst

# create prerm file
echo -n "#!/bin/bash
sh /opt/${packname}/uninstall.sh\n" > ${datapath}/prerm
chmod +x ${datapath}/prerm

# create data path
mv ${packname} ${rootpath}

# create install package
dpkg -b data ${fullname}.deb
