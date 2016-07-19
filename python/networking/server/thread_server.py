
import socket
import time
import threading


days = {b'Day one?'  : b'1.',
        b'Day two?'  : b'2.',
        b'Day three?': b'3.'}

def listener(backlog):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(('127.0.0.1', 1024))
    sock.listen(5)
    print('Listening at', sock.getsockname())
    return sock

def server(sock):
    while True:
        sc, sockname = sock.accept()
        print('Accepted connection from: {}.'.format(sockname))
        qday = b''
        data = b''
        try:
            while not qday.endswith(b'?'):
                data = sc.recv(1024)
                if not data:
                    raise IOError('Received {!r} then socket closed'.format(
                                                      qday.decode('ascii')))
                qday += data
        except Exception as e:
            print('Client {} error: {}.'.format(sc, e))
        print('Question: [{}].'.format(qday.decode('ascii')))
        number = days.get(qday, b'0.')
        sc.sendall(number)
        sc.close()


if __name__ == '__main__':
    sock = listener(16)
    for t in range(4):
        threading.Thread(target=server, args=(sock,)).start()
