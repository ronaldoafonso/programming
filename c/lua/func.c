
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>

int main(int argc, char *argv[])
{
    lua_State *L = NULL;
    int sum = 0;

    L = luaL_newstate();

    if (L) {
        luaL_openlibs(L);
        /* Load a lua func */
        if (luaL_dofile(L, "./func.lua")) {
            fprintf(stderr, "F: %s\n", lua_tostring(L, -1));
        } else {
            int i;

            for(i = 0; i < 3; i++) {
                lua_getglobal(L, "add");
                lua_pushnumber(L, 10);
                lua_pushnumber(L, 20);
                if (lua_pcall(L, 2, 1, 0)) {
                    fprintf(stderr, "F: %s\n", lua_tostring(L, -1));
                } else {
                    sum = lua_tointeger(L, -1);
                    fprintf(stdout, "Sum: %d.\n", sum);
                    lua_pop(L, 1);
                }
            }
        }
    }

    exit(EXIT_SUCCESS);
}
