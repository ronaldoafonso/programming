#!/bin/sh

DAYS="one two three four"

for DAY in $DAYS
do
    echo -n "Day $DAY?" | nc localhost 1024
done
