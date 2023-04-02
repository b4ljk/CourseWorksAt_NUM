def others(choosen, other_element, other_row, other_column):
    return (choosen*other_element-other_row*other_column)/choosen


def column(column_element, choosen):
    return -column_element/choosen


def row(row_element, choosen):
    return row_element/choosen


def reverse(number):
    return 1/number


def Jordan(row, col, matrix=[[]]):
    queue = []
    for rowidx, x in enumerate(matrix):
        for colidx, y in enumerate(x):
            if rowidx == row and colidx == col:
                queue.append(reverse(y))
            elif rowidx == row:
                queue.append(column(y, matrix[row][col]))
            elif colidx == col:
                queue.append(row(y, matrix[row][col]))
            else:
                queue.append(
                    others(matrix[row][col], y, matrix[row][colidx], matrix[rowidx][col]))
