
import socket


def server():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(('127.0.0.1', 1024))
    sock.listen(1)
    print('Listening at', sock.getsockname())
    while True:
        sc, sockname = sock.accept()
        print('Accepted connection from: {}.'.format(sockname))
        data = b''
        while len(data) < 4:
            more = sc.recv(4 - len(data))
            if more: data += more
        print('Received: {}.'.format(data.decode('ascii')))
        sc.close()


if __name__ == '__main__':
    server()
