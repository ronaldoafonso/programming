# Uses python3

def get_change(m):
    change = 0
    coins = [10, 5, 1]
    for i in coins:
        while m >= i:
            m = m - i
            change = change + 1
    return change

if __name__ == '__main__':
    m = int(input())
    print(get_change(m))
