#!/bin/sh

appname=$1

if [ -z "$appname" ]; then
  echo "No Run App Name Input!"
  return
fi

dirpath=`dirname $0`
tmp="${dirpath#?}"

if [ "${dirpath%$tmp}" != "/" ]; then
  dirpath=$PWD/$dirpath
fi

export LD_LIBRARY_PATH=$dirpath:$dirpath/lib:$dirpath/3.1.0.0
export QT_PLUGIN_PATH=$dirpath/plugins:$QT_PLUGIN_PATH

$appname "$@"
