
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>


static int l_new_userdata(lua_State *L)
{
    unsigned char *ud = NULL;

    ud = (unsigned char *)lua_newuserdata(L, 1);

    if (ud) {
        *ud = 0x00;
        luaL_getmetatable(L, "UserDataMetaTable");
        lua_setmetatable(L, -2);
        return 1;
    }

    return 0;
}

static int l_set_userdata(lua_State *L)
{
    unsigned char *ud = NULL;
    unsigned char chr;

    ud = (unsigned char *)luaL_checkudata(L, 1, "UserDataMetaTable");
    chr = luaL_checkint(L, 2);

    if (ud) {
        *ud = chr;
    }

    return 0;
}

static int l_get_userdata(lua_State *L)
{
    unsigned char *ud = NULL;

    ud = (unsigned char *)luaL_checkudata(L, 1, "UserDataMetaTable");

    if (ud) {
        lua_pushinteger(L, *ud);
        return 1;
    }

    return 0;
}


static const struct luaL_Reg lud[] = {
    {"new", l_new_userdata},
    {NULL, NULL}
};

int luaopen_lud(lua_State *L)
{
    luaL_newmetatable(L, "UserDataMetaTable");
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    lua_pushcfunction(L, l_set_userdata);
    lua_setfield(L, -2, "set");
    lua_pushcfunction(L, l_get_userdata);
    lua_setfield(L, -2, "get");

    luaL_openlib(L, "lud", lud, 0);
    return 1;
}
