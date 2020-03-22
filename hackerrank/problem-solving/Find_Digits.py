# given an integer, check if it is evenly divisible by its individual digits
# count the no. of digits that are divisor (repetition of digits allowed in count) -> return the count


num = 12

def findDigits(num):
    divisorCount = 0
    numCopy = num
    while(numCopy>0):
        digit = numCopy % 10
        numCopy = numCopy//10

        if(digit == 0):
            continue

        if(num % digit == 0):
            divisorCount = divisorCount + 1
        

    return divisorCount

result = findDigits(num)
print(result)