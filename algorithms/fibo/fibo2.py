
def fibo(n):
    f = 0
    for i in range(n+1):
        f = f + i
    return f


n = int(input())
f = fibo(n)
print(f)
