
local http = require("socket.http")

local hotspot = "hotspot"
local url = "http://www.ronaldoafonso.com.br/"..hotspot.."/files.md5"

local ok, code, headers = http.request(url)
if ok and code == 200 then
    print(ok)
    print(code)
    for k, v in pairs(headers) do
        print(k, v)
    end
end
