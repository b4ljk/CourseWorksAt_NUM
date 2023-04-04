from jordan import Jordan


def isPositiveViaCol(matrix=[[]]):
    for idx, x in enumerate(matrix):
        if idx == len(matrix) - 1:
            continue
        if x[len(x) - 1] < 0:
            return False
    return True


def isPositiveInRow(matrix=[[]]):
    for idx, x in enumerate(matrix[len(matrix) - 1]):
        if idx == len(matrix[len(matrix) - 1]) - 1:
            continue
        if x > 0:
            return True
    return False


def printMatrix(matrix=[[]]):
    for x in matrix:
        print(x)
    print("-----------------")


def findNegativeViaCol(matrix=[[]], colidx=None):

    for idx, x in enumerate(matrix):
        if colidx == None:
            colidx = len(x) - 1

        if idx == len(matrix) - 1:
            continue
        if x[colidx] < 0:
            return idx
    return -1


def findPositiveViaCol(matrix=[[]], colidx=None):

    for idx, x in enumerate(matrix):
        if colidx == None:
            colidx = len(x) - 1

        if idx == len(matrix) - 1:
            continue
        if x[colidx] > 0:
            return idx
    return -1


def findNegativeViaRow(matrix=[[]], rowidx=None):
    if rowidx == None:
        rowidx = len(matrix) - 1
    for idx, x in enumerate(matrix[rowidx]):
        if idx == len(matrix[rowidx]) - 1:
            continue
        if x < 0:
            return idx
    return -1


def findPositiveViaRow(matrix=[[]], rowidx=None):
    result = []
    if rowidx == None:
        rowidx = len(matrix) - 1
    for idx, x in enumerate(matrix[rowidx]):
        if idx == len(matrix[rowidx]) - 1:
            continue
        if x > 0:
            result.append(idx)
    return result


def minimumSimplex(col, matrix=[[]], algorithm=1):
    result = []
    column_elements = []
    for matind, x in enumerate(matrix):
        column_elements.append(x[col])
        if matind == len(matrix) - 1:
            continue
        constantval = x[len(x) - 1]
        divider = x[col]
        if divider == 0:
            continue
        val = constantval / divider
        if val >= 0:
            result.append([val, matind, divider])
    if len(result) == 0:
        return -1
    result.sort(key=lambda x: x[0])
    while (len(result) > 0) and (result[0][0] == 0):
        if algorithm == 1:
            result.pop(0)
        else:
            if result[0][2] > 0:
                return result[0][1]
            else:
                result.pop(0)
    if len(result) == 0:
        return -1
    return result[0][1]
    # tulguur shiid


def algorithm1(matrix=[[]]):
    while not isPositiveViaCol(matrix):
        print("algorithm1")
        negative_element_in_column = findNegativeViaCol(matrix)
        if negative_element_in_column == -1:
            break
        negative_element_in_row = findNegativeViaRow(
            matrix, negative_element_in_column)
        if negative_element_in_row == -1:
            print("No solution")
            return
        minimum_simplex = minimumSimplex(
            negative_element_in_row, matrix, algorithm=1)
        Jordan(minimum_simplex, negative_element_in_row, matrix)
        printMatrix(matrix)

        # onovchtoi shiid


def algorithm2(matrix=[[]]):
    id = 0
    while isPositiveInRow(matrix):
        print("algorithm2")
        printMatrix(matrix)

        positiveElm = findPositiveViaRow(matrix)
        print(positiveElm, "positiveElm")
        if len(positiveElm) == 0:
            break
        while len(positiveElm) > 0:
            positive_elment_index = positiveElm.pop()
            print(positive_elment_index, "positive_elment_index")
            positive_index = findPositiveViaCol(matrix, positive_elment_index)
            print(positive_index, "positive_index")
            if positive_index == -1:
                print("No solution")
                return

            minimum_simplex = minimumSimplex(
                positive_elment_index, matrix, algorithm=2)
            if minimum_simplex == -1:
                continue

            print(minimum_simplex, "minimum_simplex")
            Jordan(minimum_simplex, positive_elment_index, matrix)
            break
        id += 1
        if id == 5:
            break


matrix = [
    [2, 1.5, 0.5, 0.5, 6.5],
    [-3, -1, -1, 0, -3],
    [3, -2, 0, 1, 6],
    [-7, -1.5, -1.5, -1.5, -6.5],

]
algorithm1(matrix)
algorithm2(matrix)
printMatrix(matrix)
