
class IterObj:

    def __init__(self, start, stop):
        self.start = start - 1
        self.stop = stop
        self.count = self.start

    def __iter__(self):
        return IterObjIterator(self.start, self.stop)

class IterObjIterator:

    def __init__(self, start, stop):
        self.start = start
        self.stop = stop
        self.position = start

    def __iter__(self):
        return self

    def __next__(self):
        if self.position >= self.stop:
            raise StopIteration
        self.position += 1
        return self.position


for i in IterObj(1, 5):
    print(i, end=" ")
print()

try:
    o = IterObj(1, 5)
    i = iter(o)
    print(i.__next__())
    print(i.__next__())
    print(i.__next__())
    print(i.__next__())
    print(i.__next__())
    print(i.__next__())
except StopIteration:
    print('End of iteration.')
