
def fibo(n):
    f = []
    for i in range(n+1):
        if i <= 1: f.append(i)
        else:      f.append(f[-1] + f[-2])
    f = f[-1]
    return f


n = int(input())
f = fibo(n)
print(f)
