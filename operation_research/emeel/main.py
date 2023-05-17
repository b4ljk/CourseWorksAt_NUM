column = int(input("Enter column: "))
row = int(input("Enter row: "))
matrix = []
for i in range((column)):
    matrix.append([])
    for j in range((row)):
        _input = int(input("Enter value: "))
        matrix[i].append(_input)
        
result_list = []
print("---------------")
for i in matrix:
    row_min = min(i)
    row_idx = ([int(idx) for idx,z in enumerate(i) if z==row_min])
    # print(row_idx)
    for elements in row_idx:
        col_max = max([int(x[elements]) for x in matrix])
        col_idx = [int(x[elements]) for x in matrix].index(col_max)
        if row_min == col_max:
            result_list.append([col_max,elements,col_idx])    
if len(result_list)==0:
    print("No result : ----- XX")
else:
    for x in result_list:
        print("row = ",x[2]+1)
        print("col = ",x[1]+1)
        print("emeel = ",x[0])

# 3   5    6
# 7   8    9
# 10 11 12