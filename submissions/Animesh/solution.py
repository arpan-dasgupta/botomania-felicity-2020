import numpy as np
from board import Board

b = Board()

def make_move(board_state, player_num):
    b.update_board(board_state)
    optimal_move, optimal_score = (-1, -1), None
    move_list = b.get_valid_moves(player_num)
    
    if len(move_list) == 0:
        return (-1,-1)
    
    for move in move_list:
        g = b.simulate_move(move, player_num)
        val = g.evaluation(player_num)

        if optimal_score == None or val > optimal_score:
            optimal_score, optimal_move = val, move
    
    return optimal_move

# if __name__ == "__main__":
#     bb =[[0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 2, 1, 0, 0, 0, 0], [0, 0, 0, 0, 2, 2, 0, 0, 0, 0], [0, 0, 0, 1, 2, 1, 1, 1, 1, 1], [0, 0, 0, 0, 2, 2, 0, 1, 0, 0], [0, 0, 0, 1, 2, 2, 0, 0, 1, 0], [0, 0, 0, 0, 2, 0, 2, 0, 0, 1]]
#     us = 2
#     b.state = np.array(bb)
    
#     m = make_move(b.state, us)
#     print(m)

# if __name__ == "__main__":
#     g = Board()
#     us = 2
#     g.show()
