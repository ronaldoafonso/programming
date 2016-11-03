
local uci = require("uci")
local url = require("socket.url")

local cursor = uci.cursor()

function showssid(t)
    for k, v in pairs(t) do
        if k == "ssid" then
            local encv = url.escape(v)
            print("SSID: "..v.." Encoded SSID: "..encv..".")
        end
    end
end

cursor:foreach("wireless", "wifi-iface", showssid)
