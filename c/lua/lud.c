
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>


/* User Data */
unsigned char *ud = NULL;

static int l_new_userdata(lua_State *L)
{
    ud = (unsigned char *)lua_newuserdata(L, 1);

    if (ud) {
        *ud = 0x00;
    }

    return 1;
}

static int l_set_userdata(lua_State *L)
{
    unsigned char chr = luaL_checkint(L, 1);

    if (ud) {
        *ud = chr;
    }

    return 0;
}

static int l_get_userdata(lua_State *L)
{
    if (ud) {
        lua_pushinteger(L, *ud);
    }

    return 1;
}


static const struct luaL_Reg lud[] = {
    {"new", l_new_userdata},
    {"set", l_set_userdata},
    {"get", l_get_userdata},
    {NULL, NULL}
};

int luaopen_lud(lua_State *L)
{
    luaL_openlib(L, "lud", lud, 0);
    return 1;
}
