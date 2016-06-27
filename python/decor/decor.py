
class Counter:

    def __init__(self, func):
        self.func = func
        self.count = 0

    def __call__(self, arg):
        self.count += 1
        print("{0} has been executed {1} times.".format(self.func.__name__,
                                                        self.count))
        self.func(arg)


@Counter
def function(arg):
    print("Running function with arg: {0}.".format(arg))
