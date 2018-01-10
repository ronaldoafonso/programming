
import zmq
import time


def main():
    """ Create a ZeroMQ publisher. """
    context = zmq.Context()
    socket = context.socket(zmq.PUB)
    socket.bind("tcp://*:5556")

    while True:
        command = input("Command: ")
        if command == "quit":
            break
        socket.send_string(command)
        time.sleep(1)

    socket .close()
    context.destroy()

if __name__ == '__main__':
    main()
