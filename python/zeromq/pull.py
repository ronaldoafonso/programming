
import zmq


def main():
    """ Create a zeromq context and
        receive messages on it. """
    context = zmq.Context()
    socket = context.socket(zmq.PULL)
    socket .bind("tcp://*:5555")

    while True:
        try:
            message =socket .recv()
            print("Received: {}.".format(message))
        except:
            break

    socket .close()
    context.destroy()

if __name__ == '__main__':
    main()
