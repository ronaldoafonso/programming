
def gcd(a, b):
    if b == 0:
        return a
    aprime = a % b
    return gcd(b, aprime)

s = input()
a = int(s.split(' ')[0])
b = int(s.split(' ')[1])
d = gcd(a, b)
print(d)
