#!/bin/bash
LINE_NO=0
while read l
do
LINE_NO=$((LINE_NO+1))
if [[ $LINE_NO -eq 10 ]]
then
    echo $l;
fi
done < file.txt
