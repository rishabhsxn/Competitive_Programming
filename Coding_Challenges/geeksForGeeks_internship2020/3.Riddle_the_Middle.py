# problem ID: 4998
# https://practice.geeksforgeeks.org/contest-problem/002d500b651cb889dbabefe59a0b7871d651ffd8/0

testCases = int(input())


def med(noOfElements, elements):
    median = -1
    
    elements.sort()
    
    if(noOfElements%2==0):
        mid_1 = noOfElements//2
        mid_2 = mid_1 - 1
        median = (int(elements[mid_1]) + int(elements[mid_2]))//2
    else:
        mid = noOfElements//2
        median = elements[mid]

    print(median)
    
    
while(testCases>0):
    noOfElements = int(input())
    
    elementsAsString = input()

    elements = elementsAsString.split()

    elements = list(map(int, elements)) 
    
    med(noOfElements, elements)
    
    testCases = testCases - 1 