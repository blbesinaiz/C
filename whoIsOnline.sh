#!/bin/bash

#Description: Program determines if the user name entered 
#	      is currently logged on
#Commandline syntax: ./script.sh s######

r=`who | grep $1`
if [ "$r" ]
then
	echo User $l is logged in.
else
	echo User $l is not logged in.
fi
