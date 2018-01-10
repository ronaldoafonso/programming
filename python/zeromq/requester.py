
import zmq


def main():
    """ Create a ZeroMQ requester. """
    context = zmq.Context()
    socket = context.socket(zmq.REQ)
    socket.connect("tcp://localhost:5555")

    for request in range(10):
        print("Sending request %s …" % request)
        socket.send(b"Hello")
        message = socket.recv()
        print("Received reply %s [ %s ]" % (request, message))

    socket.send(b"Bye")

    socket.close()
    context.destroy()


if __name__ == '__main__':
    main()
