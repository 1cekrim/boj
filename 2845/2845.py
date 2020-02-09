a = list(map(int, input().split(' ')))
b = a[0] * a[1]
print(*map(lambda x: x - b, map(int, input().split(' '))), end=' ')