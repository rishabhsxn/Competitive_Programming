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
    #print(l)

    largest = None
    for i in range(0,len(l)-1):
        t1 = l[i]
        t2 = l[i+1]

        if largest is None:
            largest = t1[1]
        elif t1[1]>largest:
            largest = t1[1]

        if t2[0] > largest:
            count = count + 1

    print(count)

    n = n-1
