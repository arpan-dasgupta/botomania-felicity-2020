def make_move(game_state, player):
    board_size = 10
    to_flip = []
    f_r_n = -1
    f_c_n = -1
    for r_n in range(0, 10):
        for c_n in range(0, 10):
            if game_state[r_n][c_n] != 0:
                continue
            to_flip.clear()
            for i in range(r_n+1, board_size):
                if game_state[i][c_n] == 0:
                    break
                if game_state[i][c_n] == player:
                    for j in range(r_n+1, i):
                        to_flip.append(j*board_size+c_n)
                    break
            for i in range(c_n+1, board_size):
                if game_state[r_n][i] == 0:
                    break
                if game_state[r_n][i] == player:
                    for j in range(c_n+1, i):
                        to_flip.append(r_n*board_size+j)
                    break
            for i in range(r_n-1, -1, -1):
                if game_state[i][c_n] == 0:
                    break
                if game_state[i][c_n] == player:
                    for j in range(r_n-1, i, -1):
                        to_flip.append(j*board_size+c_n)
                    break
            for i in range(c_n-1, -1, -1):
                if game_state[r_n][i] == 0:
                    break
                if game_state[r_n][i] == player:
                    for j in range(c_n-1, i, -1):
                        to_flip.append(r_n*board_size+j)
                    break

            i = r_n+1
            j = c_n+1
            while i < board_size and j < board_size:
                if game_state[i][j] == 0:
                    break
                if game_state[i][j] == player:
                    rr = r_n+1
                    cc = c_n+1
                    while rr < i and cc < j:
                        to_flip.append(rr*board_size+cc)
                        rr += 1
                        cc += 1
                    break
                i += 1
                j += 1
            i = r_n - 1
            j = c_n - 1
            while i >= 0 and j >= 0:
                if game_state[i][j] == 0:
                    break
                if game_state[i][j] == player:
                    rr = r_n-1
                    cc = c_n-1
                    while rr > i and cc > j:
                        to_flip.append(rr*board_size+cc)
                        rr -= 1
                        cc -= 1
                    break
                i -= 1
                j -= 1
            i = r_n + 1
            j = c_n - 1
            while i < board_size and j >= 0:
                if game_state[i][j] == 0:
                    break
                if game_state[i][j] == player:
                    rr = r_n+1
                    cc = c_n-1
                    while rr < i and cc > j:
                        to_flip.append(rr*board_size+cc)
                        rr += 1
                        cc -= 1
                    break
                i += 1
                j -= 1
            i = r_n - 1
            j = c_n + 1
            while i >= 0 and j < board_size:
                if game_state[i][j] == 0:
                    break
                if game_state[i][j] == player:
                    rr = r_n-1
                    cc = c_n+1
                    while rr > i and cc < j:
                        to_flip.append(rr*board_size+cc)
                        rr -= 1
                        cc += 1
                    break
                i -= 1
                j += 1

            if len(to_flip) > 0:
                f_c_n = c_n
                f_r_n = r_n

    return (f_r_n, f_c_n)