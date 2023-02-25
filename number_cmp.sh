#!/bin/bash

file="input.txt"
log_file="some.log"

num_lines=$(wc -l < "$file")
for i in `seq 0 $(bc<<<$num_lines/4)`; do
    FIRST_LINE=$(bc<<<"$i*4+1")
    SECOND_LINE=$(bc<<<"$i*4+2")
    if [ "$(awk NR==$FIRST_LINE "$file")" == "$(awk NR==$SECOND_LINE "$file")" ];
    then
        echo "some kind of message"
    else
        echo "Lines $FIRST_LINE and $SECOND_LINE do not match" | tee -a "$log_file"
    fi
done
