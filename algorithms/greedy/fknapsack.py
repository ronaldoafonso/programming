# Uses python3

import sys

def get_optimal_value(capacity, weights, values):
    loot = 0.0
    vw = []
    for i in range(0, len(weights)):
        vw.append([values[i]/weights[i], values[i], weights[i]])
    vw.sort()
    for i in vw[::-1]:
        if capacity >= i[2]:
            capacity = capacity - i[2]
            loot = loot + i[1]
        elif capacity < i[2] and capacity:
            frac = capacity / i[2]
            capacity = 0
            loot = loot + (i[1] * frac)
        if capacity == 0: break
    return loot


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values =  [i for i in data[2::2]]
    weights = [i for i in data[3::2]]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.4f}".format(opt_value))
