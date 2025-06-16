#!/bin/sh

SOURCE="$1/_extras"
OUTPUT="$2"

#make output dir
mkdir -p "${OUTPUT}"

#copy
cp -rv "${SOURCE}/TTKWidgetTools.sh" "${OUTPUT}/TTKWidgetTools.sh"
cp -rv "${SOURCE}/TTKRoutine.sh" "${OUTPUT}/TTKRoutine.sh"
cp -rv "${SOURCE}/TTKRoutineCopy.sh" "${OUTPUT}/TTKRoutineCopy.sh"

#chmod
chmod +x "${OUTPUT}/TTKWidgetTools.sh"
chmod +x "${OUTPUT}/TTKRoutine.sh"
chmod +x "${OUTPUT}/TTKRoutineCopy.sh"
