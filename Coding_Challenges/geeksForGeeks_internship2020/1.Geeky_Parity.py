# problem ID: 4996
# https://practice.geeksforgeeks.org/contest-problem/fa5dcc919663712c89bb2c15acbb3f49b733ba19/0

def evenOrOdd(n):
    numOfOne = 0
    
    while(1==1):
        remainder = n%2
       # print("remainder:",remainder)
        if(remainder==1):
            numOfOne = numOfOne + 1
        n = int(n/2)
       # print("num:",n)
        if(n==1):
            numOfOne = numOfOne + 1
            break
        
    #print("Num of One:", numOfOne)
    
    if(numOfOne%2==0):
        print("EVEN")
    else:
        print("ODD")
        
    #print("\n")
    
while(testCases>0):
    num = int(input())
    evenOrOdd(num)
    testCases = testCases - 1