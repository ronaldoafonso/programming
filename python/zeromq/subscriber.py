
import sys
import zmq


def main():
    """ Create a ZeroMQ subscriber. """
    context = zmq.Context()
    socket = context.socket(zmq.SUB)
    socket.connect("tcp://localhost:5556")

    filters = ["all"] + sys.argv[1:]
    for flt in filters:
        socket.setsockopt_string(zmq.SUBSCRIBE, flt)

    while True:
        message = socket.recv_string()
        print("%s" % message)
        if message.split()[1] == "quit":
            break

    socket .close()
    context.destroy()


if __name__ == '__main__':
    main()
