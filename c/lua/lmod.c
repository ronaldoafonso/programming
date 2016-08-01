
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>


static int l_echo_int(lua_State *L)
{
    int i = 0;

    i = luaL_checknumber(L, 1);
    lua_pushnumber(L, i);

    return 1;
}

static int l_echo_string(lua_State *L)
{
    const char *s = NULL;

    s = luaL_checkstring(L, 1);
    lua_pushstring(L, s);

    return 1;
}

static int l_echo_userdata(lua_State *L)
{
    char *ud = NULL;
    int i;

    ud = (char *)lua_newuserdata(L, 8);
    if (ud) {
        for (i = 0; i < 8; i++) {
            *(ud + i) = 0xFF;
        }
        return 1;
    } else {
        return 0;
    }
}


static const struct luaL_Reg lmod[] = {
    {"echoi", l_echo_int},
    {"echos", l_echo_string},
    {"echoud", l_echo_userdata},
    {NULL, NULL}
};

int luaopen_lmod(lua_State *L)
{
    luaL_openlib(L, "lmod", lmod, 0);
    return 1;
}
