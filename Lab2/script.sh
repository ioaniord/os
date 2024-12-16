#!/bin/bash
date
current_time=$(date +%s)
echo "Current Time: $current_time"
let current_time2=$current_time*2
echo "Current Time * 2: $current_time2"

for i in {1..20}; do
    echo $i
done
