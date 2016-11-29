
local uci = require("uci")
local json = require("json")

local cursor = uci.cursor()
local system, timeserver
local interface = {}
local globals

function setsystem(tsystem)
    system = tsystem
end

function settimeserver(ttimeserver)
    timeserver = ttimeserver
end

cursor:foreach("system", "system", setsystem)
cursor:foreach("system", "timeserver", settimeserver)

local system = {system = system,
                timeserver = timeserver}

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

local config = {system = system,
                network = network}
local jconfig = json.encode(config)
print(jconfig)
