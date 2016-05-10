
def gen_squares(n):
    for i in range(n):
        yield i ** 2

l = [x ** 2 for x in range(3)]

g = (x ** 2 for x in range(3))


for i in gen_squares(5):
    print(i, end=" ")

print()
print(l)

print(g.__next__())
print(g.__next__())
print(g.__next__())
print(g.__next__())
