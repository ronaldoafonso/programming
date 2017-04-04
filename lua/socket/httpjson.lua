
local http = require("socket.http")
local json = require("json")

local url = "http://localhost:8080/sensor"
local data = json.encode({hostname = "hostname",
                          mac = "11:11:11:11:11:11",
                          time = os.time()})

local ok, code, headers = http.request(url, data)
if ok and code == 200 then
    print(ok)
    print(code)
    for k, v in pairs(headers) do
        print(k, v)
    end
    print("Data: " .. data)
end
