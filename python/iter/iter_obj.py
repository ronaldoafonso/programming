
class IterObj:

    def __init__(self, start, stop):
        self.start = start - 1
        self.stop = stop
        self.count = self.start

    def __iter__(self):
        return self

    def __next__(self):
        if self.count == self.stop:
            raise StopIteration
        self.count += 1
        return self.count


for i in IterObj(1, 5):
    print(i, end=" ")
print()

o = IterObj(1, 5)
i = iter(o)
print(i.__next__())
print(i.__next__())
print(i.__next__())
print(i.__next__())
print(i.__next__())
print(i.__next__())
