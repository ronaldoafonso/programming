
Class = {

    x = 0,
    name = 'Class',

    new = function(self, c)
        local c = c or {}
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
print(obj1:get(), obj2:get())

obj1:set(1)
obj2:set(2)
print(obj1:get(), obj2:get())

SubClass = {

    new = function(self)
        return Class:new(self)
    end,

    set = function(self)
        self.x = 3
    end,
}

obj3 = SubClass:new()
print(obj3:get())
obj3:set()
print(obj3:get())
