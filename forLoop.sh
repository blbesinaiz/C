#Description: Takes parameters from command line and echos back
#/bin/bash

# for i in "$@"; do echo "$i"; done
for i in "$@";
do

	sum=$((sum +$i))
done

echo $sum

