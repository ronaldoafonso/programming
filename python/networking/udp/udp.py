
import socket
import datetime


def client():
    """ UDP client. """
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    data = 'Time: {}.'.format(datetime.datetime.now()).encode('ascii')
    sock.sendto(data, ('127.0.0.1', 1024))
    data, address = sock.recvfrom(65535)
    print('Server {} replied {!r}'.format(address, data.decode('ascii')))


if __name__ == '__main__':
    client()
