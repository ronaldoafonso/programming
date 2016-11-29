
local uci = require("uci")
local json = require("json")

local cursor = uci.cursor()
local interface = {}
local globals

function setinterface(tinterface)
    table.insert(interface, tinterface)
end

function setglobals(tglobals)
    globals = tglobals
end

cursor:foreach("network", "interface", setinterface)
cursor:foreach("network", "globals", setglobals)

local network = {interface = interface,
                 globals = globals}

local jnetwork = json.encode(network)
print(jnetwork)
