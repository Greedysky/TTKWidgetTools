#!/bin/sh

source="$1/_extras"
output="$2"

#make output dir
mkdir -p "${output}"

#copy
cp -rv "${source}/TTKWidgetTools.sh" "${output}/TTKWidgetTools.sh"
cp -rv "${source}/TTKRoutine.sh" "${output}/TTKRoutine.sh"
cp -rv "${source}/TTKRoutineCopy.sh" "${output}/TTKRoutineCopy.sh"

#chmod
chmod +x "${output}/TTKWidgetTools.sh"
chmod +x "${output}/TTKRoutine.sh"
chmod +x "${output}/TTKRoutineCopy.sh"
