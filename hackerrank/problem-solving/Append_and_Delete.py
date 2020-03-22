# given 2 strings s and t, convert s into t by Deleting or appending alphabets
# if it is possible in given EXACTLY k moves, print Yes otherwise No
# if there are extra moves, deleting from an empty string will result in an empty string and consume one move - use this

# this usecase should return No, because it is not possible in exactly 2 moves
s = "y"
t = "yu"

k = 2

def appendAndDelete(s, t, stepsLeft):
    sList = list(s)           # converted to list because strings are immutable
    tList = list(t)

    i = 0                 # at start elememt of sList
    z = len(sList) - 1    # at last element of sList
    j = 0                 # at start element of tList

    flag = 0

    while(j<len(t) and stepsLeft>0):

        if(i>=len(sList)):
            sList.append(tList[j])
            stepsLeft = stepsLeft - 1

        if(sList[i] == tList[j]):
            i = i + 1
            j = j + 1
        else:

            nofCharToDelete = len(sList) - i
            if(nofCharToDelete > stepsLeft):
                break

            stepsLeft = stepsLeft - nofCharToDelete
            sList = sList[:i]
            # print("sList becomes:",sList)

    # print("sList:",sList)
    # print("tList:", tList)
    # print("stepsLeft:",stepsLeft)

    if(len(sList)>len(tList) and len(sList)-len(tList) <= stepsLeft):
        sList = sList[:len(tList)]

    if(sList == tList):
        return "Yes"
    else:
        return "No"
    


result = appendAndDelete(s, t, k)
print(result)
