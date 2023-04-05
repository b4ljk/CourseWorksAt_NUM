from jordan import Jordan


def remove_duplicates(lst):
    return list(set(lst))


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


def exchangeRowColVal(row, col, rowidx, colidx):
    temp = row[colidx]
    row[colidx] = col[rowidx]
    col[rowidx] = temp


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


def minimumSimplex(col, matrix=[[]], algorithm=1, constantsColumn=None, rows_to_ignore=None):
    print("in CALL : constantsCOlumn", constantsColumn, "col", col)
    result = []
    simplexDictionary = {}
    rowsAdded = False
    # default value
    if constantsColumn == None:
        constantsColumn = len(matrix[0]) - 1
    if rows_to_ignore == None:
        rows_to_ignore = []

    for matind, x in enumerate(matrix):
        if matind == len(matrix) - 1:
            continue
        if matind in rows_to_ignore:
            print("SHIZEr", matind)
            continue
        # print(constantsColumn, "constantsColumn")
        constantval = x[constantsColumn]
        divider = x[col]
        if divider == 0:
            continue
        val = constantval / divider
        if val in simplexDictionary:
            rows_to_ignore.append(matind)
            rows_to_ignore.append(simplexDictionary[val])
            rowsAdded = True

        else:
            simplexDictionary[val] = matind
        if constantsColumn == len(matrix[0]) - 1:
            if val >= 0:
                result.append([val, matind, divider, constantval])
        else:
            result.append([val, matind, divider, constantval])

    if len(rows_to_ignore) > 0 and rowsAdded:
        rows_to_ignore = remove_duplicates(rows_to_ignore)
        real_rows_to_ignore = []
        for idx, x in enumerate(matrix):
            if idx not in rows_to_ignore:
                real_rows_to_ignore.append(idx)
        constantsColumn = constantsColumn-1
        if constantsColumn == col:
            constantsColumn = constantsColumn-1
        if constantsColumn == -1:
            print("No solution")
            return []
        print("constantsColumn", constantsColumn, "col", col)
        return minimumSimplex(col, matrix, algorithm, constantsColumn, real_rows_to_ignore)

    if len(result) == 0:
        return -1
    result.sort(key=lambda x: x[0])
    print(result, "result", result[0][1])

    # hervee simplex 0 bol
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
            negative_element_in_row, matrix, 1)
        Jordan(minimum_simplex, negative_element_in_row, matrix)

        printMatrix(matrix)

        # onovchtoi shiid


def algorithm2(matrix=[[]]):
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
                print("**No solution**")
                return

            minimum_simplex = minimumSimplex(
                positive_elment_index, matrix, 2)
            if minimum_simplex == -1:
                continue

            print(minimum_simplex, "minimum_simplex")
            Jordan(minimum_simplex, positive_elment_index, matrix)
            # huvirgalt hiisen bol ahij busad shiid shalgah shaardlaggui break okay
            break


# matrix = [
#     [-2, -2, -1, -2],
#     [3, -3, 2, 6, ],
#     [3, -3, -2, 6],
#     [0, 1, -1, 1,],
#     [-1, 1, 1, 0,],

# ]
# matrix = [
#     [-2, 1, 6],
#     [-1, 1.5, 9],
#     [-1, 5, 30],
#     [-1, 1, 12,],
#     [2, 4, 0,],

# ]
num_rows = int(input("Enter the number of rows: "))
num_cols = int(input("Enter the number of columns: "))


matrix = []
firstRow = []
firstCol = []
print("Enter the first row:")
for i in range(num_cols):
    firstRow.append((input()))
print("Enter the first col:")
for i in range(num_rows):
    firstCol.append((input()))

for i in range(num_rows):
    a = []
    for j in range(num_cols):
        a.append(float(input()))
    matrix.append(a)


algorithm1(matrix)
algorithm2(matrix)
printMatrix(matrix)
print("Result")
matrixRows = len(matrix)
matrixCols = len(matrix[0])
print(-matrix[matrixRows-1][matrixCols - 1])
