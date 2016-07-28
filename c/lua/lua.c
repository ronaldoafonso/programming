
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>


static int l_echo_table(lua_State *L)
{
    const char *key = NULL;

    key = luaL_checkstring(L, 1);

    lua_newtable(L);
    lua_pushstring(L, key);
    lua_pushstring(L, "value");
    lua_settable(L, -3);

    return 1;
}

int main(int argc, char *argv[])
{
    char buff[256];
    int error = 0;
    lua_State *L = NULL;
    char name[32];
    int id = 0;
    int sum = 0;

    memset(buff, '\0', 256);
    memset(name, '\0', 32);
    L = luaL_newstate();

    if (L) {
        luaL_openlibs(L);
        lua_pushcfunction(L, l_echo_table);
        lua_setglobal(L, "lecho");

        /* Load variables from a Lua file. */
        if (luaL_loadfile(L, "./variables.lua") || lua_pcall(L, 0, 0, 0)) {
            fprintf(stderr, "V: %s\n", lua_tostring(L, -1));
        } else {
            lua_getglobal(L, "name");
            lua_getglobal(L, "id");
            strncpy(name, lua_tostring(L, -2), strlen(lua_tostring(L, -2)));
            id = lua_tointeger(L, -1);
            fprintf(stdout, "Name: %s ID: %d.\n", name, id);
        }

        /* Execute a Lua function. */ 
        if (luaL_dofile(L, "./func.lua")) {
            fprintf(stderr, "F: %s\n", lua_tostring(L, -1));
        } else {
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

        /* Execute a Lua file. */
        while (fgets(buff, sizeof(buff), stdin) != NULL) {
            error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);
            if (error) {
                fprintf(stderr, "P: %s\n", lua_tostring(L, -1));
                lua_pop(L, 1);
            }
        }
        lua_close(L);
    }

    exit(EXIT_SUCCESS);
}
