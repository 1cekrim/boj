d=r'..OO|--|/\\/^<<vv>>^'
for i in reversed(list(zip(*([input()for i in '.'*int(input().split()[0])])))):print(''.join(d[d[::2].index(j)*2+1]for j in i))