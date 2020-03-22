# find no. of square numbers between two given numbers, inclusive

# 3 9
# 17 24

import math

a = 35
b = 70

def squares(a, b):

    count = 0
    
    for i in range(1,b):
        square = i*i
        # print("Square:",square)
        if(square>=a and square<=b):
            # print("It is in range")
            count = count + 1

        if(square>b):
            break

    return count


def squares2(a, b):

    return (math.floor(math.sqrt(b)) - math.ceil(math.sqrt(a)) + 1)

result = squares2(a,b)
print(result)