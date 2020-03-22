# an array of no. is given, make sub-arrays in which the absolute difference between any two elements is less than or equal to 1
# return the size of the maximum sub-array possible

givenNumbers = [4, 2, 3, 4, 4, 9, 98, 98, 3, 3, 3, 4, 2, 98, 1, 98, 98, 1, 1, 4, 98, 2, 98, 3, 9, 9, 3, 1, 4, 1, 98, 9, 9, 2, 9, 4, 2, 2, 9, 98, 4, 98, 1, 3, 4, 9, 1, 98, 98, 4, 2, 3, 98, 98, 1, 99, 9, 98, 98, 3, 98, 98, 4, 98, 2, 98, 4, 2, 1, 1, 9, 2, 4]

def pickingNumbers(a):

    # [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    #  9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 99]
    
    a.sort()
    print(a)
    maxLength = 0
    presentLength = 1

    selectedNumber = a[0]
    toBeSelectedNext = None
    toBeFutureLength = 0

    goneToElse = False
   
    for i in range(1, len(a)):
        presentNumber = a[i]

        if(presentNumber == selectedNumber):
            presentLength = presentLength + 1

        elif(presentNumber == selectedNumber+1):
            presentLength = presentLength + 1
            if(toBeSelectedNext == None):
                toBeSelectedNext = presentNumber
                toBeFutureLength = 1
            else:
                toBeFutureLength = toBeFutureLength + 1
    
        else:
            goneToElse = True

            if(presentLength > maxLength):
                maxLength = presentLength
            if(toBeSelectedNext != None):
                selectedNumber = toBeSelectedNext
                presentLength = toBeFutureLength + 1
                toBeSelectedNext = presentNumber
                toBeFutureLength = 1
            else:
                selectedNumber = presentNumber
                presentLength = 1

    if(not goneToElse):
        return presentLength

    return maxLength

print(pickingNumbers(givenNumbers))