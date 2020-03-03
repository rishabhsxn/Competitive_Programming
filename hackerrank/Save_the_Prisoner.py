# priosners are sitting in circle with marked positions, candies are to be distributed. starting position is selected by drawing a slip
# start distribution from that position and continue till the candies finish (distribute again in circle if candies are left)
# the last candy is aweful, warn the prisoner who will be receiving that candy

# 999999999 999999999 1
# 352926151 380324688 94730870
# 499999999 999999998 2
# 499999999 999999997 2
# 210041918 328800789 159203369

prisoners = 210041918
candies = 328800789
startingPosition = 159203369


def saveThePrisoner2(prisoners, candies, startingPosition):

    unluckyPrisoner = (candies % prisoners) + (startingPosition - 1)

    if(unluckyPrisoner>prisoners):
        unluckyPrisoner = unluckyPrisoner % prisoners      # because after adding from where we started, the result may become more than no. of prisoners

    if(unluckyPrisoner==0):
        return prisoners
    return unluckyPrisoner

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

result = saveThePrisoner2(prisoners, candies, startingPosition)
print(result)