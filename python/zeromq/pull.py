
import zmq


if __name__ == '__main__':
    context = zmq.Context()
    sock = context.socket(zmq.PULL)
    sock.bind("tcp://*:5555")

    while True:
        message = sock.recv()
        print("Received: {}.".format(message))

    sock.close()
    context.destroy()
