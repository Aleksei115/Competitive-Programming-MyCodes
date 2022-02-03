class QItem:
    def __init__(self, row, col, dist):
        self.row = row
        self.col = col
        self.dist = dist
 
    def __repr__(self):
        return f"QItem({self.row}, {self.col}, {self.dist})"
 
def minDistance(grid):
	source = QItem(0, 0, 0)
	res = []
    # Finding the source to start from
	for row in range(len(grid)):
		for col in range(len(grid[row])):
			if grid[row][col] == 'S':
				source.row = row
				source.col = col
				break
 
    # To maintain location visit status
	visited = [[False for _ in range(len(grid[0]))]
		for _ in range(len(grid))]
     
    # applying BFS on matrix cells starting from source
	queue = []
	queue.append(source)
	visited[source.row][source.col] = True
	while len(queue) != 0:
		op = []
		source = queue.pop(0)
		print(source.row, source.col, source.dist)
        # Destination found;
		if (grid[source.row][source.col] == 'X'):
			return res
 
        # moving up
		if isValid(source.row - 1, source.col, grid, visited):
			queue.append(QItem(source.row - 1, source.col, source.dist + 1))
			visited[source.row - 1][source.col] = True
			op.append('U')

		# moving right
		if isValid(source.row, source.col + 1, grid, visited):
			queue.append(QItem(source.row, source.col + 1, source.dist + 1))
			visited[source.row][source.col + 1] = True
			op.append('R')
 
		# moving left
		if isValid(source.row, source.col - 1, grid, visited):
			queue.append(QItem(source.row, source.col - 1, source.dist + 1))
			visited[source.row][source.col - 1] = True
			op.append('L')

        # moving down
		if isValid(source.row + 1, source.col, grid, visited):
			queue.append(QItem(source.row + 1, source.col, source.dist + 1))
			visited[source.row + 1][source.col] = True
			op.append('D')
 

		if len(op) > 0:
			res.append(op[0])

 
	return -1



 
 
# checking where move is valid or not
def isValid(x, y, grid, visited):
    if ((x >= 0 and y >= 0) and (x < len(grid) and y < len(grid[0])) and (grid[x][y] != '#') and (visited[x][y] == False)):
        return True
    return False

if __name__ == '__main__':
	testCases = int(input())

	mat = []

	for i in range(testCases):
		rows, columns = input().split(' ')
		rows = int(rows)
		columns = int(columns)

		for j in range(rows):
			l = input()
			mat.append(list(l))

		print(minDistance(mat))


# 1
# 4 3
# ##X
# ...
# ..#
# S##