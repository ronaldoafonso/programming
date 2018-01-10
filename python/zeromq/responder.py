
import time
import zmq


def main():
    """ Create a ZeroMQ responder. """
    context = zmq.Context()
    socket = context.socket(zmq.REP)
    socket.bind("tcp://*:5555")

    while True:
        print("Wait message ...")
        message = socket.recv()
        if message == b"Bye":
            break
        print("Received request: %s" % message)
        time.sleep(1)
        socket.send(b"World")

    socket.close()
    context.destroy()

if __name__ == '__main__':
    main()
