testCases = int(input())

def cutRibbon(RibLen, maxLen):
    count = 0
    mul = 2
    i = 1
    statLen = RibLen
    while (True):
        mul = mul*i
        if(mul<=maxLen):
           
            i = i+1

            while(statLen>0):
                statLen = statLen - mul
                if(statLen == mul):
                    count = count + 1
                    # print(count)
                    break
                elif(statLen < mul):
                    count = count + 2#for reverse combo
                    # print(count)
                    break

        else:
            break
    print(count) 

while(testCases>0):

    # RibLen, maxLen = list(map(int,input().strip().split()))
    arr = input()

    RibLen = int(arr[0])
    maxLen = int(arr[1])

    cutRibbon(RibLen, maxLen)

    testCases = testCases - 1