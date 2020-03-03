# on 1st day, 5 people were given the ad, floor(5/2) people each will forward it to 3 people on next day
# display total people who have got the ad

import math

n = 3

def viralAdvertising(days):
    initialPeople = 5
    totalPeople = 0

    for day in range(0, days):
        peopleToday = math.floor(initialPeople/2)
        totalPeople = totalPeople + peopleToday
        initialPeople = peopleToday*3

    return totalPeople

result = viralAdvertising(n)

print(result)
