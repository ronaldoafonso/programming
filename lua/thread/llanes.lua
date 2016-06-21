
local lanes = require("lanes").configure()

function lane1()
    for i = 10, 19 do
        print("Lane 1: ", i)
        os.execute("sleep 0.2")
    end
end

function lane2()
    for i = 20, 29 do
        print("Lane 2: ", i)
        os.execute("sleep 0.1")
    end
end

local thread1 = lanes.gen("*", lane1)()
local thread2 = lanes.gen("*", lane2)()

thread1:join()
thread2:join()
