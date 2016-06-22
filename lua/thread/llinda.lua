
local lanes = require("lanes").configure()
local linda = lanes.linda()

function loop_send(n)
    for i = 1, n do
        print("Sending: "..i)
        linda:send("x", i)
    end
end

function loop_recv(n)
    for i = 1, n do
        local key, val = linda:receive(1.0, "x")
        if val ~= nil then
            print("Received: "..val)
        end
    end
end

local thread_loop_send = lanes.gen("", loop_send)(10)
local thread_loop_recv = lanes.gen("", loop_recv)(10)

thread_loop_send:join()
thread_loop_recv:join()
