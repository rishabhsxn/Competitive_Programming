# initially e=100 energy level is given, clouds are given, 1=thunderhead=energy decrease by 2 and 0=cumulus=no additional decrement
# character starts from c[0] and jumps to next clouds, jump size is given. For each jump e=e-1
# game finishes when she reaches c[0] again, print the energy level left

# example case
# jumpSize = 2
# clouds = [0, 0, 1, 0, 0, 1, 1, 0]

# sampleCase #0
# jumpSize = 2
# clouds = [0, 0, 1, 0]

# sampleCase #1
jumpSize = 3
clouds = [1, 1, 1, 0, 1, 1, 0, 0, 0, 0]

def jumpingOnClouds(clouds, jumpSize):
    noOfClouds = len(clouds)
    energy = 100
    print("initial Energy:",energy)
    currentCloud = 0
    print("CurrentCloud:", currentCloud)
    print("\n")
    flag = 0     # used to differentiate between 1st time and other

    while(True):
        
        print("At cloud:",currentCloud)
        if(clouds[currentCloud] == 1 and flag!=0):
            print("it is thunderhead")
            energy = energy - 2
            print("energy reduced by 2")
            print("energy becomes:",energy)
            
        
        if(currentCloud==0 and flag!=0):
            print("again reached at start...break")
            break
        else:
            flag = 1
            currentCloud = (currentCloud + jumpSize) % noOfClouds
            print("nextCloud:",currentCloud)

        print("Jumped")
        energy = energy - 1
        print("energy reduced by 1")
        print("energy becomes:",energy)
        print("\n")

    return energy



result = jumpingOnClouds(clouds, jumpSize)
print(result)
