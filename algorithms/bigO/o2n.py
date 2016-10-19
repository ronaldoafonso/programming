
import time


def fibonacci(n):
    if n <= 1: return n
    return fibonacci(n - 2) + fibonacci(n - 1)


for i in range(100):
    t1 = time.time()
    result = fibonacci(i)
    t2 = time.time()
    print("Result: {0}, time: {1}.".format(result, t2 - t1))
