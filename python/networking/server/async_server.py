
import asyncio


days = {b'Day one?'  : b'1.',
        b'Day two?'  : b'2.',
        b'Day three?': b'3.'}

@asyncio.coroutine
def handle_client(reader, writer):
    qday = b''
    data = b''
    while not qday.endswith(b'?'):
        data = yield from reader.read(1024)
        qday += data
    print('Question: [{}].'.format(qday.decode('ascii')))
    number = days.get(qday, b'0.')
    writer.write(number)
    yield from writer.drain()
    writer.close()


if __name__ == '__main__':
    loop = asyncio.get_event_loop()
    server = asyncio.start_server(handle_client, '127.0.0.1', 1024)
    print('Running server ...')
    loop.run_until_complete(server)
    loop.run_forever()
    loop.close()
    print('Finished!')
