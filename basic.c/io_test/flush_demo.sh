#!/bin/bash

# write into 256KB every loop
declare -a sleep_interval=(128 256 512 1024 2048 4096 5120)

for ((i=0; i<${#sleep_interval[@]}; ++i))
do
	date
	echo "--> test block size of ${sleep_interval[$i]}MB start ..."
    ./flush_demo files 500 ${sleep_interval[$i]}
	date
	echo "--> test block size of ${sleep_interval[$i]}MB end."
    df -h
    ls -alrt
	
    rm -f files*
    sleep 5   
done

