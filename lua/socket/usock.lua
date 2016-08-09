
local socket = require("socket")
local unix = require("socket.unix")

local usock = unix()
local path = "/tmp/usock"

local data = "test\n"
usock:connect(path)
usock:send(data)
usock:close()
