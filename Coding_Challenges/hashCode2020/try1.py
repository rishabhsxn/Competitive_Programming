import array as arr

noOfBooks = 0
noOfLib = 0
noOfDays = 0
daysRemaining = 0

lineCounter=0
libCounter=0

bookScore = list()

libraries = list()

inputFilename = "f_libraries_of_the_world.txt"
outputFilename = "output_f.txt"

try:
    filehandler = open(inputFilename)

except:
    print("Couldn't open the file, in 1st try")

flag = 0
    

for line in filehandler:
    lineCounter = lineCounter + 1
    lineList = line.strip()
    if (len(lineList)!= 0):
        
        lineList = lineList.split(" ")

        if (lineCounter==1):
            noOfBooks = int(lineList[0])
            noOfLib = int(lineList[1])
            noOfDays = int(lineList[2])
            daysRemaining = noOfDays

        elif (lineCounter==2):
            bookScore = lineList

        else:

            if (flag==0):
                flag = 1
                library = list()
                library.append(libCounter)
                libCounter = libCounter + 1
                # print(lineCounter,"lineList: ",lineList[1])
                library.append(lineList[1])
                library.append(lineList[2])
                library.append(lineList[0])
            else:
                flag = 0
                def key_for_books(bookID):
                    bookID = int(bookID)
                    # print("The key for {} book id is {}".format(book, int(bookScore[book])))
                    return int(bookScore[bookID])

                lineList.sort(key=key_for_books, reverse=True)

                library = library + lineList
                libraries.append(library)


# print(libraries)


def my_key(lib):
    priority = (int(lib[2]) - int(lib[1]))
    lib.append(priority)    # this is added to the original library, use this key to extract libraries with same key
    # bookScoreForLib = 0
    # for bookID in range(4, len(lib)):
    #     bookID = int(lib[bookID])
    #     bookScoreForLib = bookScoreForLib + int(bookScore[bookID])

    # finalPriority = priority + bookScoreForLib

    # print("The key is {}".format(finalPriority))
    return priority
    
libraries.sort(key=my_key, reverse=False)  # made this false because we will reverse when adding to listOfLibrariesWithSameKey

# for library in libraries:
#     print(library[len(library)-1])

# take all libraries with same key value in separate lists, sort those lists with maxBookScore of libraries and then merge them
key = None
listOfLibrariesWithSameKey = list()

# print("Before", libraries)

for x in range(len(libraries)-1, 0, -1):          #reverse traversal
    # print("x:",x)
    library = libraries[x]
    # print("library:", library)

    if(key == None):
        newLibraryGroup = list()
        newLibraryGroup.append(library)

    key = library[len(library)-1]
    previousLibrary = libraries[x-1]
    previousKey = previousLibrary[len(previousLibrary)-1]

    if(previousKey == key):
        newLibraryGroup.append(previousLibrary)
    else:
        listOfLibrariesWithSameKey.append(newLibraryGroup)
        newLibraryGroup = list()
        newLibraryGroup.append(previousLibrary)
        
    if(x==1):
        listOfLibrariesWithSameKey.append(newLibraryGroup)

        # newLibraryGroup.clear()
        # key = None

# for libraryGroup in listOfLibrariesWithSameKey:
#     print("New group")
#     for library in libraryGroup:
#         print(library[len(library)-1], end=" ")
#     print("\n")

libraries.clear()

def key_for_Libraries_with_same_priority(lib):
    bookScoreForLib = 0
    for bookID in range(4, len(lib)-1):
        bookID = int(lib[bookID])
        bookScoreForLib = bookScoreForLib + int(bookScore[bookID])
    return bookScoreForLib

# print("listOfLibrariesWithSameKey:",listOfLibrariesWithSameKey)
# print("length of listOfLibrariesWithSameKey:",len(listOfLibrariesWithSameKey))

for libraryGroup in listOfLibrariesWithSameKey:
    libraryGroup.sort(key=key_for_Libraries_with_same_priority, reverse=True)
    libraries = libraries + libraryGroup
    


# print("libraries:",libraries)

#daysRemaining = daysRemaining - int(libraries[0][1])
# print(daysRemaining)

noOfLibSelected = 0
noOfBookSelected = 0

i = 0
while (i<len(libraries) and daysRemaining>0):

    libr = libraries[i]

    daysLeftForLib = daysRemaining - int(libr[1])
    daysRemaining = daysLeftForLib
    # print("Days remaining:",daysRemaining)

    totalBooks = 0
    if(daysLeftForLib > 0):
        noOfLibSelected = noOfLibSelected + 1

        if (daysLeftForLib* int(libr[2]) > int(libr[3])):
            # all books selected
            totalBooks = int(libr[3])
            # print(libr[4:])
        else:
            totalBooks = daysLeftForLib*int(libr[2])
            # print("days left:", daysLeftForLib)
            # print("i:",i,"total books:",totalBooks)
            # print(libr[4:4+totalBooks])

        libraries[i].append(totalBooks)

    i = i+1

# print(libraries[0])


try:
    outputHandler = open(outputFilename, "w+")

except:
    print("Couldnot open file")



print("\n")
print("no. of libs selected = ",noOfLibSelected)
outputHandler.write(str(noOfLibSelected)+"\n")
j=0

while(j<noOfLibSelected):
    librr = libraries[j]
    # print(librr[0], librr[len(librr)-1])
    strr1 = str(librr[0]) +" "+str(librr[len(librr)-1])+ "\n"
    outputHandler.write(strr1)
    # print(librr[4:4+librr[len(librr)-1]])
    strr = ""
    for x in range(4,4+librr[len(librr)-1]):       # make changes here if using last technique 2 instead of 1
        strr = strr + librr[x] + " "
    if (j == noOfLibSelected-1):
        outputHandler.write(strr)
    else:
        outputHandler.write(strr+"\n")

    j = j + 1

outputHandler.close()