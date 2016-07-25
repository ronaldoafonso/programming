
from aiohttp import web
import asyncio


@asyncio.coroutine
def get_user_handler(request):
    host = request.host
    user = request.match_info.get('username', 'all')
    body = 'GET Host: {} - User: {}.\n\r\n\r'.format(host, user)
    return web.Response(body=body.encode())

@asyncio.coroutine
def put_user_handler(request):
    host = request.host
    user = request.match_info.get('username', 'all')
    body = 'PUT Host: {} - User: {}.\n\r\n\r'.format(host, user)
    return web.Response(body=body.encode())

@asyncio.coroutine
def post_user_handler(request):
    host = request.host
    user = request.match_info.get('username', 'all')
    body = 'POST Host: {} - User: {}.\n\r\n\r'.format(host, user)
    return web.Response(body=body.encode())

@asyncio.coroutine
def delete_user_handler(request):
    host = request.host
    user = request.match_info.get('username', 'all')
    body = 'DELETE Host: {} - User: {}.\n\r\n\r'.format(host, user)
    return web.Response(body=body.encode())


if __name__ == '__main__':
    app = web.Application()
    app.router.add_route('GET', '/user/{username}', get_user_handler)
    app.router.add_route('PUT', '/user/{username}', put_user_handler)
    app.router.add_route('POST', '/user/{username}', post_user_handler)
    app.router.add_route('DELETE', '/user/{username}', delete_user_handler)
    web.run_app(app)
