n = int(input())

l = list()
while(n):
    flag=0
    st = input()
    if 'MUJ' in st:
        flag=1
        #print('found')
    if flag == 0:
        l.append('NO')
    else:
        l.append('YES')
    n =n-1

for m in l:
    print(m)
