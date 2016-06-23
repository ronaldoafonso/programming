
Class = {

    x = 0,

    new = function()
        local c = {}
        for k, v in pairs(Class) do
            c[k] = v
        end
        return c
    end,

    set = function (self, x)
        self.x = x
    end,

    get = function(self)
        return self.x
    end,
}

obj1 = Class.new()
obj2 = Class.new()

obj1:set(1)
obj2:set(2)

print(obj1:get(), obj2:get())
