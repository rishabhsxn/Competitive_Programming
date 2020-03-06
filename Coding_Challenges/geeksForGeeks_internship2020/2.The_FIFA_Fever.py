# problem ID: 4997
# https://practice.geeksforgeeks.org/contest-problem/d3c8850dcaebd83ac2a8ecde43fb0b42e98d7479/0

testCases = int(input())

def whoHasBall(rId, passes):
    # print("rid:",rId)
    # print("Passes:", passes)
    currentId = rId
    previousId = None
    for passs in passes:
        if(passs == "B"):
            if(previousId != None):
                x = currentId
                currentId = previousId
                previousId = x
        else:
            previousId = currentId
            p = passs.split()
            # print("p:", p)
            # print(type(passs))
            currentId = int(p[1])
        # print("currentId:", currentId)
        # print("previousId:", previousId)
    
    print(currentId)

while (testCases>0):
    firstLineI = input()
    firstLine = firstLineI.split()
    numOfPasses = int(firstLine[0])
    # print("num of pass:", numOfPasses)

    # print(firstLine[1])
    rId = int(firstLine[1])
    
    passes = list()
    
    while(numOfPasses > 0):
        passs = input()
        passes.append(passs)
        numOfPasses = numOfPasses - 1
        
    whoHasBall(rId, passes)
    
    testCases = testCases - 1 