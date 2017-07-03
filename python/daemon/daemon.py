
import os
import time


def child():
    os.setsid()
    pid = os.fork()
    if pid > 0:
        os._exit(1)
    os.umask(0o0022)
    time.sleep(10)

def parent():
    os._exit(0)

def demonize():
    pid = os.fork()
    if pid == 0:
        child()
    elif pid > 0:
        parent()
    else:
        os._exit(1)


if __name__ == '__main__':
    try:
        demonize()
    except:
        print("Unable demonize.")
