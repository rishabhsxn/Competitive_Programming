# see the question

p = [5, 2, 1, 3, 4]

def permutationEquation(p):
    mapping_Element_ElementIndex = [None]*len(p)
    y = list()

    for index,element in enumerate(p):
        mapping_Element_ElementIndex[element-1] = index + 1

    for element,elementIndex in enumerate(mapping_Element_ElementIndex):
        indexElementIndex = mapping_Element_ElementIndex[elementIndex-1]
        y.append(indexElementIndex)

    return y

result = permutationEquation(p)
print(result)