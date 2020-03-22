# find the minimum cost of converting a Matrix to a magic square - all rows, columns, diagonals add upto same constant n(n2+1)/2 = 15 for 3
# there are 8 possible such arrangements for 3x3 matrix
# mid element will always be 5, corners will always be even numbers and edges will be odd numbers

# idea is to use brute force method to find all possible magic squares -> find cost to convert matrix to these results -> min. one is answer

import sys
import array

ourMatrix = [[4, 8, 2], [4, 5, 7], [6, 1, 6]]

def formMagicSquare(matrix):
    matrixModified = list()      # to store matrix as 1D array

    for row in matrix:
        matrixModified = matrixModified + row

    minimumCost = sys.maxsize

    # find all possible magic sqaures and save them to a list
    allPossibleMagicSquares = list()
    allPossibleMagicSquares.append([8,1,6,3,5,7,4,9,2])
    allPossibleMagicSquares.append([6,1,8,7,5,3,2,9,4])
    allPossibleMagicSquares.append([4,9,2,3,5,7,8,1,6])
    allPossibleMagicSquares.append([2,9,4,7,5,3,6,1,8])
    allPossibleMagicSquares.append([8,3,4,1,5,9,6,7,2])
    allPossibleMagicSquares.append([4,3,8,9,5,1,2,7,6])
    allPossibleMagicSquares.append([6,7,2,1,5,9,8,3,4])
    allPossibleMagicSquares.append([2,7,6,9,5,1,4,3,8])

    # loops through each magic square and find cost, compare to previous minimum cost and assign the minimum value to it
    for magicSquare in allPossibleMagicSquares:
        cost = 0
        for i in range(0, len(magicSquare)):
            cost = cost + abs(magicSquare[i]-matrixModified[i])
            
        if(cost < minimumCost):
            minimumCost = cost

    return minimumCost

result = str(formMagicSquare(ourMatrix))
print(result)