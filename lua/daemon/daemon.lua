
local posix = require("posix")

Daemon = {

    new = function(self, name)
        local obj = {}
        setmetatable(obj, self)
        self.__index = self
        if name then self.name = name end
        return obj
    end,

    daemonize = function(self)
        local pid = posix.fork()
        if pid == -1 then
            error("Could not fork")
        elseif pid == 0 then
            if not posix.setpid("s") then
                error("Could not setsid")
            end
            posix.umask("0022")
            posix.chdir("/tmp")
            local devnull = io.open("/dev/null", "w")
            posix.dup2(posix.fileno(devnull), posix.fileno(io.stdin))
            posix.dup2(posix.fileno(devnull), posix.fileno(io.stdout))
            posix.dup2(posix.fileno(devnull), posix.fileno(io.stderr))
            devnull:close()
            posix.openlog("["..self.name.."]")
        else
            os.exit(0)
        end
    end,

    log = function(self, message)
        posix.syslog(posix.LOG_INFO, message)
    end,

    exit = function(self, rc)
        os.exit(rc)
    end,
}

local d = Daemon
d:new("daemon")
d:daemonize()
for i = 1, 5 do
    d:log(i..": I'm running ...")
    os.execute("sleep 2")
end
d:exit(0)
