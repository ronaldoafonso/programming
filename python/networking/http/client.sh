#!/bin/sh

http_method() {
    METHOD="$1"
    curl -i -X "$METHOD" http://localhost:8080/user/username
    echo "-------------------------------------"
}

for i in 10
do
    http_method "GET" &
    http_method "PUT" &
    http_method "POST" &
    http_method "DELETE" &
done
wait
