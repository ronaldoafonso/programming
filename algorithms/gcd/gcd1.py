
def gcd(a, b):
    d = 0
    for i in range(1, a+b+1):
        if a % i == 0 and b % i == 0:
            d = i
    return d

s = input()
a = int(s.split(' ')[0])
b = int(s.split(' ')[1])
d = gcd(a, b)
print(d)
