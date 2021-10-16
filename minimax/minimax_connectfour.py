import copy
import time
import abc
import random

class Game(object):
    """A connect four game."""

    def __init__(self, grid):
        """Instances differ by their board."""
        self.grid = copy.deepcopy(grid)  # No aliasing!

    def display(self):
        """Print the game board."""
        for row in self.grid:
            for mark in row:
                print(mark, end='')
            print()
        print()

    def possible_moves(self):
        """Return a list of possible moves given the current board."""
        return [i for i in range(len(self.grid)) if self.grid[0][i] == '-']

    def neighbor(self, col, color):
        """Return a Game instance like this one but with a move made into the specified column."""
        neighbor = Game(self.grid)
        for i in reversed(range(len(self.grid))):
            if self.grid[i][col] == '-':
                neighbor.grid[i][col] = color
                return neighbor
        return None


    def utility(self, c=0):
        """Return the minimax utility value of this game"""
        colors = ['R', 'B']
        win_state = self.winning_state()
        if win_state is not None:
            return win_state
        mini = float('inf')
        for i,x in enumerate(self.possible_moves()):
            util = self.neighbor(x, colors[c]).utility(c=(c+1)%2)
            if util == float('-inf'):
                return util
            if util < mini:
                mini = util
        return mini

    def winning_state(self):
        """Returns float("inf") if Red wins; float("-inf") if Black wins;
           0 if board full; None if not full and no winner"""
        deltas = [(0,1),(1,0),(-1,0),(0,-1),(1,1),(1,-1),(-1,1),(-1,-1)]
        for i in range(len(self.grid)):
            for j in range(len(self.grid[0])):
                for d in deltas:
                    x = i
                    y = j
                    if self.grid[i][j] != '-':
                        for k in range(4):
                            if self.grid[i][j] != self.grid[x][y]:
                                break
                        else:
                            break
                        if grid[i][j] == 'R':
                            return float('inf')
                        else:
                            return float('-inf')
        for x in self.grid[0]:
            if x == '-':
                return None
        return 0


class Agent(object):
    """Abstract class, extended by classes RandomAgent, FirstMoveAgent, MinimaxAgent.
    Do not make an instance of this class."""

    def __init__(self, color):
        """Agents use either RED or BLACK chips."""
        self.color = color

    @abc.abstractmethod
    def move(self, game):
        """Abstract. Must be implemented by a class that extends Agent."""
        pass

class RandomAgent(Agent):
    """Naive agent -- always performs a random move"""

    def move(self, game):
        """Returns a random move"""
        possible = game.possible_moves()
        if len(possible):
            return random.choice(possible)
        return None

class FirstMoveAgent(Agent):
    """Naive agent -- always performs the first move"""

    def move(self, game):
        """Returns the first possible move"""
        possible = game.possible_moves()
        if len(possible):
            return possible[0]
        return None

class MinimaxAgent(Agent):
    """Smart agent -- uses minimax to determine the best move"""

    def move(self, game):
        """Returns the best move using minimax"""
        possible = game.possible_moves()
        if not len(possible):
            return None
        maxi = float('-inf')
        index = -1
        for i,x in enumerate(possible):
            util = game.utility()
            if util == float('inf'):
                return x
            if util > maxi:
                maxi = util
                index = i
        return possible[index]


def tournament(simulations=50):
    """Simulate connect four games, of a minimax agent playing
    against a random agent"""

    redwin, blackwin, tie = 0,0,0
    for i in range(simulations):

        game = single_game(io=False)

        print(i, end=" ")
        if game.winning_state() == float("inf"):
            redwin += 1
        elif game.winning_state() == float("-inf"):
            blackwin += 1
        elif game.winning_state() == 0:
            tie += 1

    print("Red %d (%.0f%%) Black %d (%.0f%%) Tie %d" % (redwin,redwin/simulations*100,blackwin,blackwin/simulations*100,tie))

    return redwin/simulations

def single_game(io=True):
    """Create a game and have two agents play it."""

    game = Game([['-' for i in range(8)] for j in range(8)])   # 8x8 empty board
    if io:
        game.display()

    maxplayer = MinimaxAgent('R')
    minplayer = RandomAgent('B')

    while True:
        m = maxplayer.move(game)
        game = game.neighbor(m, maxplayer.color)
        if io:
            time.sleep(1)
            game.display()

        if game.winning_state() is not None:
            break

        m = minplayer.move(game)
        game = game.neighbor(m, minplayer.color)
        if io:
            time.sleep(1)
            game.display()

        if game.winning_state() is not None:
            break

    if game.winning_state() == float("inf"):
        print("RED WINS!")
    elif game.winning_state() == float("-inf"):
        print("BLACK WINS!")
    elif game.winning_state() == 0:
        print("TIE!")

    return game

if __name__ == '__main__':
    single_game(io=True)
    #tournament(simulations=50)
