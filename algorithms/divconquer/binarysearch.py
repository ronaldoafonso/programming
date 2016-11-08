
def binsearch(A, low, high, key):
    if high < low:
        return -1
    mid = low + ((high-low)//2)
    if key == A[mid]:
        return mid
    elif key < A[mid]:
        return binsearch(A, low, mid-1, key)
    else:
        return binsearch(A, mid+1, high, key)



l = [x for x in range(0, 101)]

i = binsearch(l, 0, 100, 80)
print("Value of v: {} index: {}.".format(l[i], i))
