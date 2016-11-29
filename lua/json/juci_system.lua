
local uci = require("uci")
local json = require("json")

local cursor = uci.cursor()
local system, timeserver

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

local jsystem = json.encode(system)
print(jsystem)
