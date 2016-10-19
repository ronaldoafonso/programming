
import time


def isFirstElementEven(l):
    return l[0] % 2 == 0


n = []

for i in range(100):
    n.append(i)
    n.reverse()
    t1 = time.time()
    result = isFirstElementEven(n)
    t2 = time.time()
    print("Result: {0}, time: {1}.".format(result, t2 - t1))
