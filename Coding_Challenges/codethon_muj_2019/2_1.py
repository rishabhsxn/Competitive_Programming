# save the in and out time of customers in tuples and save the tuples
# in a list
try: n = int(input())
except: quit()

while(n):
    try: m = int(input())
    except: quit()
    l = list()
    k = list()
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
    #print(max(l))
    maxt = max(l)
    mt = maxt[0]

    for a,b in l:
        if a!= mt:
            k = k + list(range(a,b+1))
        else:
            k.append(a)
    k.sort()

    def remove_dup(k):
        result=list()
        for i in k:
            if i not in result:
                result.append(i)
        return result

    k = remove_dup(k)
    print(k)

    for i in range(1,len(k)):
        if k[i]-1 != k[i-1]:
            count = count + 1
    print(count)
    
    n = n-1
