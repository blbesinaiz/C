#!/bin/bash

#command line syntax: who | wc -l | ./script.sh
#Program determines how many users currently login

x=`who | wc -l` #` mark used for system commands
if [ "$x" ]
then
	echo $x
fi
