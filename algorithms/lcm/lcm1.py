# Uses python3

def gcd(a, b):
    if b == 0:
        return a
    aprime = a % b
    return gcd(b, aprime)

def lcm(a, b):
    l = (a * b) // gcd(a, b)
    return l

s = input()
a = int(s.split(' ')[0])
b = int(s.split(' ')[1])
l = lcm(a, b)
print(l)
