
local md5 = require("md5")

local msg1 = "Ronaldo Afonso"
local msg2 = "Ronaldo Afonso"

if md5.sum(msg1) == md5.sum(msg2) then
    print("The same messages.")
else
    print("Different messages.")
end
