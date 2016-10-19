
import time


def containsValue(l, v):
    for e in l:
        if e == v: return True
    return False


n = []

for i in range(100):
    n.append(i)
    v = i
    t1 = time.time()
    result = containsValue(n, v)
    t2 = time.time()
    print("Result: {0}, time: {1}.".format(result, t2 - t1))
