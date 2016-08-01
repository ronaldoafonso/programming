
local m = require("lmod")

local t = {
    echoi  = m.echoi(10),
    echos  = m.echos("test"),
    echoud = m.echoud()
}

for k, v in pairs(t) do
    print(k, v)
end
