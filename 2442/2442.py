n = int(input())
print('\n'.join([' ' * (n - 1 - i) + '*' * (2 * i + 1) for i in range(n)]))