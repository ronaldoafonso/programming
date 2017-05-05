
import pika


broker = 'localhost'
queue = 'py-queue'

def get_message(channel, method, properties, body):
    print("Message: %r" % body)

params = pika.ConnectionParameters(broker)
connection = pika.BlockingConnection(params)
channel = connection.channel()
channel.basic_consume(get_message,
                      queue=queue,
                      no_ack=True)
channel.start_consuming()
connection.close()
