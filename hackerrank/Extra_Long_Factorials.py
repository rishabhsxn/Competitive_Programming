# given a number, find it's factorial and handle the large numbers
# Big Integers are used to handle such integers. Python, Java etc handle them automatically but, C/C++ need extra code

n = 4

def extraLongFactorials(n):
    i = 1
    fac = i

    while(i<=n):
        fac = fac * i
        i = i + 1
    
    return fac


print(extraLongFactorials(n))
