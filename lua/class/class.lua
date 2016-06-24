
Class = {

    x = 0,
    name = 'Class',

    new = function(self)
        local c = {}
        self.__index = self
        return setmetatable(c, self)
    end,

    set = function (self, x)
        self.x = x
    end,

    get = function(self)
        return self.x
    end,
}

obj1 = Class:new()
obj2 = Class:new()
obj1:set(1)
obj2:set(2)
print(obj1:get(), obj2:get())

SubClass = {

    new = function(self)
        local c = Class:new()
        local sc = c:new()
        return sc
    end,

    set = function(self)
        self.x = 0
    end,
}

obj3 = SubClass:new()
obj3:set()
print(obj3:get())
