
import os
import time


def child():
    for i in range(5):
        print("I'm running in background and 'init' is my parent!")
        time.sleep(1)

def parent():
    print("I'm the parent, so let me go!!!")
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
