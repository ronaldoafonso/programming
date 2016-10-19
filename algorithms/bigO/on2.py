
import time


def containsDuplicate(l):
    for i in range(len(l)):
        for j in range(len(l)):
            if i == j: continue
            if l[i] == l[j]: return True
    return False


n = []

for i in range(100):
    n.append(i)
    t1 = time.time()
    result = containsDuplicate(n)
    t2 = time.time()
    print("Result: {0}, time: {1}.".format(result, t2 - t1))
