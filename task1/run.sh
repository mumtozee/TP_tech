#!/bin/bash

CURR_LOCATION=$(pwd)

mkdir $(pwd)/$3
DESTINATION=${CURR_LOCATION}/$3

FILE_LIST=$(find $1 -name "*.$2")

counter=""

for file in ${FILE_LIST}
do
  TARGET_NAME=$(basename "$file")

  while [[ -e ${DESTINATION}/"$TARGET_NAME" ]]
  do
    let counter++
    TARGET_NAME=$counter"$TARGET_NAME"
  done

  cp "$file" ${DESTINATION}/"$TARGET_NAME"
done

cd ${CURR_LOCATION}
tar -zcf $4 $3

echo done
