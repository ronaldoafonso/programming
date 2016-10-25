# Uses python3

def fibo(n):
    if n <= 1:
        return n
    else:
        return fibo(n-1) + fibo(n-2)

n = int(input())
f = fibo(n)
print(f)
