
import pika


broker = 'localhost'
exchange = 'py-exchange'
key = 'py-key'
message = 'Hello from Python!!!!'

params = pika.ConnectionParameters(broker)
connection = pika.BlockingConnection(params)
channel = connection.channel()
channel.basic_publish(exchange=exchange,
                      routing_key=key,
                      body=message)
connection.close()
