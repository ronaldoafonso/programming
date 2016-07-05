
import socket


def server():
    """ UDP server. """
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(('127.0.0.1', 1024))
    while True:
        data, address = sock.recvfrom(65535)
        print('Client {}: {!r}'.format(address, data.decode('ascii')))
        sock.sendto(data, address)


if __name__ == '__main__':
    server()
