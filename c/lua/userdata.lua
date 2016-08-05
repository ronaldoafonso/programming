
-- Test lud Lua module
local lud = require("lud")

ud = lud.new()
ud:set(10)
print(ud, ud:get())
