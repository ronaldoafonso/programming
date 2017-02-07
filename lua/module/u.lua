
local users = require("users")

users:add({username = "user1", ipaddr = "1.1.1.1"})
users:add({username = "user2", ipaddr = "2.2.2.2"})
users:add({username = "user3", ipaddr = "3.3.3.3"})
users:add({username = "user4", ipaddr = "4.4.4.4"})
users:add({username = "user5", ipaddr = "5.5.5.5"})
users:show()

users:del({username = "user3", ipaddr = "3.3.3.3"})
users:show()

us = {"user1", "user2", "user3", "user4", "user5"}
for _, username in pairs(us) do
    user = users:get(username)
    if user then
        print("User: "..user["username"].." IP: "..user["ipaddr"])
    else
        print("User not found.")
    end
end
