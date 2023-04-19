print("enter the number of Ai")
col = int(input())
print("enter the numbers for Ai")
cols = []
for i in range(col):
    temp = int(input())
    cols.append(temp)
print("enter the number of Bj")
row = int(input())
print("enter the numbers for Bj")
rows = []
for i in range(row):
    temp = int(input())
    rows.append(temp)
print("enter the matrix")
matrix = []
for i in range(col):
    matrix.append([])
    for j in range(row):
        temp = int(input())
        matrix[i].append(temp)
# zadgai bodlogo
if sum(cols) != sum(rows):
    rows.append(sum(cols) - sum(rows))
    temp = []
    for i in range(col):
        matrix[i].append(0)

result = []
for i in range(len(cols)):
    result.append([])
    for j in range(len(rows)):
        if min(cols[i], rows[j]) == 0:
            result[i].append(-1)
        else:
            temp = min(cols[i], rows[j])
            result[i].append(temp)
            cols[i] -= temp
            rows[j] -= temp
print(result)
