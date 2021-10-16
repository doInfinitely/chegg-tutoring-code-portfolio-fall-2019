import random
import copy
import math

def find_minimum_elevation_difference(grid, starting_row):
    minI = starting_row
    minJ = 0
    minChange = math.inf
    for i,x in enumerate(grid):
        for j,y in enumerate(x):
            if i == starting_row and j == 0:
                continue
            if abs(grid[i][j]-grid[starting_row][0]) < minChange:
                minI = i
                minJ = j
                maxChange = abs(grid[i][j]-grid[starting_row][0])
            elif abs(grid[i][j]-grid[starting_row][0]) == minChange and random.random() > 0.5:
                minI = i
                minJ = j
                minChange = abs(grid[i][j]-grid[starting_row][0])
    return (minI, minJ)

def elevation_change(grid, path):
    cumDelta = 0
    for i,x in enumerate(path[:-1]):
        cumDelta += abs(grid[x[0]][x[1]]-grid[path[i+1][0]][path[i+1][1]])
    return cumDelta

def find_minimum_path(grid, start, end, visited=None):
    if start[0] == end[0] and start[1] == end[1]:
        return [end]
    if not visited:
        visited = set()
    if start in visited:
        return []
    if start[0] < 0 or start[1] < 0:
        return []
    if start[0] >= len(grid) or start[1] >= len(grid[0]):
        return []
    visited.add(start)
    moves = [(0,1), (0,-1), (1,0), (-1,0), (1,1), (-1,-1), (1,-1), (-1,1)]
    minChange = math.inf
    path = []
    for x in moves:
        tentPath = [start] + find_minimum_path(grid, (start[0]+x[0], start[1]+x[1]), end, visited)
        if len(tentPath) and tentPath[-1][0] == end[0] and tentPath[-1][1] == end[1] and elevation_change(grid, tentPath) < minChange:
            minChange = elevation_change(grid, tentPath)
            path = tentPath
    return path

def find_elevation_route_for_starting_row(grid, starting_row):
    end = find_minimum_elevation_difference(grid, starting_row)
    path = find_minimum_path(grid, (starting_row, 0), end)
    bool_grid = [[False for y in x] for x in grid]
    for x in path:
        bool_grid[x[0]][x[1]] = True
    return bool_grid, elevation_change(grid, path)
 
    
    return

if __name__ == '__main__':
    grid = [[0,109],
            [100,107],
            [0,105]]
    print(find_elevation_route_for_starting_row(grid, 1))
