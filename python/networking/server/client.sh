#!/bin/sh

ask_for_day() {
    DAY="$1"
    RDAY=$(echo -n "Day $DAY?" | nc localhost 1024)
    echo "Day $DAY: $RDAY."
}

DAYS="one two three four"

for DAY in $DAYS
do
    ask_for_day "$DAY" &
done

wait
