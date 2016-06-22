
class Counter:

    def __init__(self, func):
        self.func = func
        self.counter = 0

    def __call__(self, arg):
        self.counter += 1
        self.func(arg)


@Counter
def showName(name):
    print("My name is: {0}.".format(name))
