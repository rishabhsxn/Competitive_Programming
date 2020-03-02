# this is the 2nd try, 1st try is in C language


scores = [100, 100, 50, 40, 40, 20, 10]
alice = [5, 25, 50, 120]

def climbingLeaderboard(scores, alice):

    # iterating the Alice scores in reverse
    aliceRanks = list()
    for i in range(len(alice)-1, -1, -1):   
        aliceScore = alice[i]
        currentRank = 1

        previousScore = -1
        for index,score in enumerate(scores):
            # print("index:",index)
            if(score <= aliceScore):
                aliceRanks.append(currentRank)
                break
            else:
                if(score!=previousScore):
                    currentRank = currentRank + 1
            previousScore = score
            if(index==len(scores)-1):
                aliceRanks.append(currentRank)

    aliceRanks.reverse()
    return aliceRanks

result = climbingLeaderboard(scores, alice)

print(result)
