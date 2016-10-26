
def is_prime(n):
    prime = 0
    if n < 2: return False
    for i in range(1, n+1):
        if n % i == 0:
            prime = prime + 1
        if prime > 2:
            return False
    return True


for i in range(1, 50):
    if is_prime(i):
        print("{0} is prime.".format(i))
