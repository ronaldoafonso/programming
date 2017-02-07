
Users = {

    users = {},

    add = function(self, user)
        self["users"][user["username"]] = user
    end,

    del = function(self, user)
        self["users"][user["username"]] = nil
    end,

    get = function(self, username)
        return self["users"][username]
    end,

    show = function(self)
        for k, user in pairs(self["users"]) do
            print(user["username"], user["ipaddr"])
        end
        print()
    end,
}

return Users

