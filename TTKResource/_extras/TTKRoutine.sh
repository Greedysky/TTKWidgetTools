#!/bin/sh

appname=$1

if [ -z "${appname}" ]; then
  echo "No Run App Name Input!"
  return
fi

dirpath=`dirname $0`
tmp="${dirpath#?}"

if [ "${dirpath%${tmp}}" != "/" ]; then
  dirpath=$PWD/${dirpath}
fi

dirpath=${dirpath}/../

case "$(uname)" in
  Darwin)
    export DYLD_LIBRARY_PATH="${dirpath}:${dirpath}/lib:${dirpath}/3.1.0.0:$DYLD_LIBRARY_PATH"
    ;;
  *)
    export LD_LIBRARY_PATH="${dirpath}:${dirpath}/lib:${dirpath}/3.1.0.0"
    ;;
esac
export QT_PLUGIN_PATH=${dirpath}/plugins:$QT_PLUGIN_PATH

${appname} "$@"
