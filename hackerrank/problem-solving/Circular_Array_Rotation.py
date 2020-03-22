# we have to right rotate an array for a given no. of times and then return elements at only some indices
# solution - don't actually rotate the array, for only the required indices find which element will be there after rotation

# 3 2 3
# 1 2 3
# 0
# 1
# 2
elements = [1, 2, 3]
indicesRequired = [0, 1, 2]
rotations = 2

def circularArrayRotation(elements, indicesRequired, rotations):

    resultArray = list()

    for index in indicesRequired:

        oldLocation = index - rotations        # this will be the answer when oldLocation >= 0
        if(oldLocation < 0):
            oldLocation = oldLocation % len(elements)         # this will be the answer if the oldLocation < 0 (just find how much from behind you have to move)

        resultArray.append(elements[oldLocation])

    return resultArray



result = circularArrayRotation(elements, indicesRequired, rotations)
print(result)
