from board import Board

MAX, MIN = 1000, -1000
true_us = 2

def minimax(depth, g: Board, us, alpha: int, beta: int):
    move_list = g.get_valid_moves(us)
    turn_maximizing = us == true_us

    if depth == 3 or len(move_list) == 0:
        return g.evaluation(us)

    if turn_maximizing:
        best = MIN

        for move in move_list:
            val = minimax(depth + 1, g.simulate_move(move, us), alpha, beta)

            best = max(best, val)
            alpha = max(alpha, best)

            if beta <= alpha:
                break
        return best
    else:
        best = MAX

        for move in move_list:
            val = minimax(depth + 1, g.simulate_move(move, us), alpha, beta)

            best = min(best, val)
            beta = min(beta, best)

            if beta <= alpha:
                break
        return best


if __name__ == "__main__":
    print("The optimal value is :", minimax(0, 0, True, MIN, MAX))
