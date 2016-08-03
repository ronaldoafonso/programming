
-- Test lud Lua module
local lud = require("lud")

ud = lud.new()
lud.set(10)
n = lud.get()
print("User data: "..tostring(n))
