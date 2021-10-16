import copy
import time

class Puzzle():
  """A sliding-block puzzle."""
  
  def __init__(self, grid):
    """Instances differ by their number configurations."""
    self.grid = copy.deepcopy(grid) # No aliasing!

  def display(self):
    """Print the puzzle."""
    for row in self.grid:
      for number in row:
        print number,
      print
    print

  # Finds the gap
  def find(self):
    for x in range(3):
      for y in range(3):
        if self.grid[x][y] == ' ':
          return (x, y)

  def convert(self, move):
    converter = dict()
    converter['W'] = (-1, 0)
    converter['E'] = (1,0)
    converter['N'] = (0,-1)
    converter['S'] = (0,1)
    return converter[move]

  def moves(self):
    """Return a list of possible moves given the current configuration."""
    # We take a move to mean movement of the negative space 'the gap'
    m = []
    gap = self.find()
    if gap[0] > 0:
      m.append('W')
    if gap[0] < 2:
      m.append('E')
    if gap[1] > 0:
      m.append('N')
    if gap[1] < 2:
      m.append('S')
    return m

  def neighbor(self, move):
    """Return a Puzzle instance like this one but with one move made."""
    gap = self.find()
    m = self.convert(move)
    puzzle = Puzzle(self.grid)
    temp = puzzle.grid[gap[0]+m[0]][gap[1]+m[1]]
    puzzle.grid[gap[0]+m[0]][gap[1]+m[1]] = ' '
    puzzle.grid[gap[0]][gap[1]] = temp
    return puzzle

  def h(self, goal):
    """Compute the distance heuristic from this instance to the goal."""
    # We use the hamming distance between two puzzles as the heuristic
    distance = 0
    for x in range(3):
      for y in range(3):
        if self.grid[x][y] != goal.grid[x][y]:
          distance += 1
    return distance

  def key(self):
    return tuple([tuple(x) for x in self.grid])



class Agent():
  """Knows how to solve a sliding-block puzzle with A* search."""

  def astar(self, puzzle, goal):
    """Return a list of moves to get the puzzle to match the goal."""
    # initialize a*
    cost = dict()
    parent = dict()
    visited = set()
    current = puzzle.key()
    cost[current] = 0

    # store path traceback
    parent[current] = (None, None)

    p = Puzzle([[y for y in x] for x in current])
    while p.h(goal) != 0:
      p = Puzzle([[y for y in x] for x in current])
      moves = p.moves()
      branch = [p.neighbor(x) for x in moves]
      for i,x in enumerate(branch):
        cost[x.key()] = cost[current]+1
        if x.key() not in parent:
            parent[x.key()] = (current, moves[i])
      candidates = set([x for x in cost]) - visited
      candidates = sorted([(cost[x]+goal.h(Puzzle(x)),x) for x in candidates])
      visited.add(current)
      current = candidates[0][1]

    # recover the path taken to goal and return
    moves = []
    while current != None:
      moves.append(parent[current][1])
      current = parent[current][0]
    moves = moves[:-1]
    moves.reverse()
    return moves



def main():
  """Create a puzzle, solve it with A*, and console-animate."""

  puzzle = Puzzle([[1, 2, 5], [4, 8, 7], [3, 6, ' ']])
  puzzle.display()

  agent = Agent()
  goal = Puzzle([[' ', 1, 2], [3, 4, 5], [6, 7, 8]])
  path = agent.astar(puzzle, goal)

  while path:
    move = path.pop(0)
    puzzle = puzzle.neighbor(move)
    time.sleep(1)
    puzzle.display()

if __name__ == '__main__':
  main()
