a=list(map(int,input().split(' ')))
print(*[[1,1,2,2,2,8][i]-a[i]for i in range(6)])