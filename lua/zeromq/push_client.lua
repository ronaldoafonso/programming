
local zmq = require("lzmq")

local context = zmq.init(1)
local socket = context:socket(zmq.PUSH)
socket:connect("tcp://server.ronaldoafonso.com.br:5555")

local n = 0
while true do
    n = n + 1
    print("Sending message"..n)
    socket:send("Message "..n)
end

socket:close()
context:term()
