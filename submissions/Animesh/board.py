import numpy as np
import seaborn as sns
from matplotlib import pyplot as plt

SIZE = 10
DIRECTIONS = [
    (1, 0),
    (0, 1),
    (-1, 0),
    (0, -1),
    (1, 1),
    (-1, -1),
    (-1, 1),
    (1, -1)
]
CORNERS = [
    (0, 0), (SIZE-1, 0), (0, SIZE-1), (SIZE-1, SIZE-1)
]
C_X_SQUARES = []


def on_board(x, y):
    return x >= 0 and x < SIZE and y >= 0 and y < SIZE


class Board(object):

    def __init__(self, state=None):
        if state is None:
            self.state = np.zeros(shape=(SIZE, SIZE))
            self.state[4][5] = self.state[5][4] = 1
            self.state[4][4] = self.state[5][5] = 2
        else:
            self.state = state
        self.next_move = None

        for x, y in CORNERS:
            for dx, dy in DIRECTIONS:
                i = x+dx
                j = y+dy

                if on_board(i, j):
                    C_X_SQUARES.append((i, j))

    # returns list of coordinahttp://radagast.se/othello/Help/strategy.htmlhttp://radagast.se/othello/Help/strategy.htmltes of valid moves

    def update_board(self, new_board: list):
        self.state = np.array(new_board)

    def get_valid_moves(self, us):
        they = 3 - us
        move_list = []

        for i in range(SIZE):
            for j in range(SIZE):
                if self.state[i][j]:
                    continue
                
                for dx, dy in DIRECTIONS:
                    x = i + dx
                    y = j + dy
                    steps = 0
                    
                    while on_board(x, y) and self.state[x][y] == they:
                        x += dx
                        y += dy
                        steps += 1
                    
                    if not on_board(x, y):
                        continue
                    
                    # adjacent squares of same color
                    if steps <= 0:
                        continue
                
                    if self.state[x][y] != us:
                        continue

                    move_list.append((i, j))
                    break
        return move_list

    def simulate_move(self, move, us):
        g = Board(np.copy(self.state))
        r, c = move
        g.state[r][c] = us
        they = 3 - us

        for dx, dy in DIRECTIONS:
            x = r+dx
            y = c+dy
            steps = 0

            while on_board(x, y) and self.state[x][y] == they:
                steps += 1
                x += dx
                y += dy

            if not on_board(x, y):
                continue

            # adjacent squares of same color
            if steps <= 0:
                continue

            if self.state[x][y] != us:
                continue

            x = r+dx
            y = c+dy

            while on_board(x, y) and self.state[x][y] == they:
                g.state[x][y] = us
                x += dx
                y += dy

        return g

    def evaluation(self, us: int) -> float:
        they = 3 - us

        move_list_us = self.get_valid_moves(us)
        move_list_they = self.get_valid_moves(they)

        # metric 1 - mobility
        move_cnt_us = len(move_list_us)
        move_cnt_they = len(move_list_they)

        # metric 2 - current captured squares
        us_square_cnt = np.count_nonzero(self.state == us)
        they_square_cnt = np.count_nonzero(self.state == they)

        # metric 3 - current corners
        us_corners = sum([int(self.state[i][j] == us) for i, j in CORNERS])
        they_corners = sum([int(self.state[i][j] == they) for i, j in CORNERS])

        # metric 4 - c or x squares
        us_cx = sum([int(self.state[i][j] == us) for i, j in C_X_SQUARES])
        they_cx = sum([int(self.state[i][j] == they)
                       for i, j in C_X_SQUARES])

        VICTORY = 1000000000
        if move_cnt_us == 0 and move_cnt_they != 0:
            return -VICTORY
        if move_cnt_us > 0 and move_cnt_they == 0:
            return VICTORY
        if move_cnt_they + move_cnt_us == 0:
            return VICTORY if us_square_cnt > they_square_cnt else -VICTORY

        res = (move_cnt_us - move_cnt_they) * 3
        res += (us_corners - they_corners) * 10000
        res += (they_cx - us_cx) * -200
        res += (us_square_cnt - they_square_cnt) * 10

        return res

    def show(self):
        sns.heatmap(self.state)
        plt.show()

