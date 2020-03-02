try: n = int(input())
except: quit()

while(n):
    try: m = int(input())
    except: quit()
    l = list()
    count = 2
    while(m):
        try: x = input()
        except: quit()
        x = x.split()
        x0 = int(x[0])
        x1 = int(x[1])
        tup = x0,x1
        l.append(tup)
        m=m-1
    l.sort()
    print(l)

    for i in range(1,len(k)):
        if k[i]-1 != k[i-1]:
            count = count + 1
    print(count)

    n = n-1
