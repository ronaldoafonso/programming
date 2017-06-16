
local zmq = require("lzmq")
local posix = require("posix")

local context = zmq.init(1)

local socket = context:socket(zmq.PULL)

socket:bind("tcp://*:5555")

while true do
    local req = socket:recv()
    if req then
        print("Received ["..req.."]")
    end
	posix.sleep(1)
end

socket:close()
context:term()
