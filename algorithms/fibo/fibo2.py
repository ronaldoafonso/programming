# Uses python3

def fibo(n):
    f = []
    for i in range(n+1):
        if i <= 1: f.append(i)
        else:      f.append(f[-1] + f[-2])
    f = f[-1]
    return f


for i in range(0, 46):
    f = fibo(i)
    print(f)
#n = int(input())
#f = fibo(n)
#print(f)
