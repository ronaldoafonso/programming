
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <json-c/json.h>


int main(int argc, char *argv[])
{
    char *str = "{\"action\": \"add\", \
                  \"username\": \"user1\", \
                  \"userip\": \"1.1.1.1\"}";

    json_object *jobj;

    jobj = json_tokener_parse(str);

    json_object_object_foreach(jobj, key, val) {
        printf("%s -> %s.\n", key, json_object_get_string(val));
    }

    exit(EXIT_SUCCESS);
}
