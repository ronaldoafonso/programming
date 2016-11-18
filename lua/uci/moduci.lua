
local uci = require("uci")

local cursor = uci.cursor()

local ipaddr = cursor:get("network", "lan", "ipaddr")
print("LAN IP address: "..ipaddr)

if ipaddr ~= "192.168.120.1" then 
    ipaddr = "192.168.120.1"
    cursor:set("network", "lan", "ipaddr", ipaddr)
    cursor:commit("network")
    print("Changed IP to "..ipaddr)
end

function show(tinterface)
    for key, value in pairs(tinterface) do
        if key == ".name" then
            print("Interface: "..value)
        end
    end
end

cursor:foreach("network", "interface", show)
