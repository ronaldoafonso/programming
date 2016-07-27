
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>


int main(int argc, char *argv[])
{
    char buff[256];
    int error = 0;
    lua_State *L = NULL;

    memset(buff, '\0', 256);
    L = luaL_newstate();

    if (L) {
        luaL_openlibs(L);
        while (fgets(buff, sizeof(buff), stdin) != NULL) {
            error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);
            if (error) {
                fprintf(stderr, "%s\n", lua_tostring(L, -1));
                lua_pop(L, 1);
            }
        }
        lua_close(L);
    }

    exit(EXIT_SUCCESS);
}
