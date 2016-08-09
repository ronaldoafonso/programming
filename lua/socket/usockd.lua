
local socket = require("socket")
local unix = require("socket.unix")

local usock = unix()
local path = "/tmp/usock"

usock:bind(path)
usock:listen(5)

while true do
    local conn, err = usock:accept()
    if not err then
        local data = conn:receive()
        print("Received: "..tostring(data))
        conn:close()
    else
        print("Error: "..tostring(err))
    end
end
