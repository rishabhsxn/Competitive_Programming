# priosners are sitting in circle with marked positions, candies are to be distributed. starting position is selected by drawing a slip
# start distribution from that position and continue till the candies finish (distribute again in circle if candies are left)
# the last candy is aweful, warn the prisoner who will be receiving that candy

prisoners = 7
candies = 19
startingPosition = 2


def saveThePrisoner(prisoners, candies, startingPosition):

    currentPosition = startingPosition
    while(candies>0):
        candies = candies - 1
        currentPosition = currentPosition + 1

        if(currentPosition == prisoners+1):
            currentPosition = 1

    unluckyPrisoner = -1

    # currentPosition is 1 ahead of unlucky prisoner

    if(currentPosition==1):
        unluckyPrisoner = prisoners   #last prisoner will be unlucky
    else:
        unluckyPrisoner = currentPosition - 1

    return unluckyPrisoner

result = saveThePrisoner(prisoners, candies, startingPosition)
print(result)