#!/bin/bash
#
#Script to print file
#
if cat $1
then
echo -e "\n\nFile $1 found and succesfully echoed"
else
echo -e  "\n\nFile $1  not found"
fi
