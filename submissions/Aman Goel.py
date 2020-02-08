# include<stdio.h>
def make_move(board_rep, player_num):
    #
    # YOUR LOGIC GOES HERE
    #

    U = 1
    T = 2
    finalans = [-1, -1]
    ans = 0
    pieces = 0
    for i in range(0, 10, 1):
        for j in range(0, 10, 1):
            if(board_rep[i][j] == 1 or board_rep[i][j] == 2):
                pieces += 1
    for i in range(0, 10, 1):
        for j in range(0, 10, 1):
            besth = horizontal(board_rep, player_num, i, j)
            besthrl = horizontalrl(board_rep, player_num, i, j)
            bestv = vertical(board_rep, player_num, i, j)
            bestv2 = vertical2(board_rep, player_num, i, j)
            bestd1 = diag1(board_rep, player_num, i, j)
            bestd2 = diag2(board_rep, player_num, i, j)
            if(besth[2] > ans):
                finalans = besth
                ans = besth[2]
            if(bestv[2] > ans):
                finalans = bestv
                ans = bestv[2]
            if(bestd1[2] > ans):
                finalans = bestd1
                ans = bestd1[2]
            if(bestd2[2] > ans):
                finalans = bestd2
                ans = bestd2[2]
            if(besthrl[2] > ans):
                finalans = besthrl
                ans = besthrl[2]
            if(bestv2[2] > ans):
                finalans = bestv2
                ans = bestv2[2]

    return (finalans[0], finalans[1])


def horizontal(board_rep, player_num, x, y):
    if(player_num == 1):
        U = 1
        T = 2
    else:
        U = 2
        T = 1
    count = 0
    best = 0
    ansx = -1
    ansy = -1
    for j in range(10):
        if(board_rep[x][j] == U):
            count += 1
        elif(board_rep[x][j] == T):
            # print(board_rep[x][j+1])
            # print(count)
            if(count > best and board_rep[x][j+1] == 0):
                best = count+1
                ansx = x
                ansy = j+1
                count = 0
                # print(count)

    return [ansx, ansy, best]


def horizontalrl(board_rep, player_num, x, y):
    if(player_num == 1):
        U = 1
        T = 2
    else:
        U = 2
        T = 1
    count = 0
    best = 0
    ansx = -1
    ansy = -1
    for j in range(9, 0, -1):
        if(board_rep[x][j] == U):
            count += 1
        elif(board_rep[x][j] == T):
            # print(board_rep[x][j+1])
            # print(count)
            if(count > best and board_rep[x][j-1] == 0):
                best = count+1
                ansx = x
                ansy = j-1
                count = 0
                # print(count)

    return [ansx, ansy, best]


def vertical(board_rep, player_num, x, y):
    if(player_num == 1):
        U = 1
        T = 2
    else:
        U = 2
        T = 1
    count = 0
    best = 0
    ansx = -1
    ansy = -1
    for i in range(10):
        if(board_rep[x][i] == U):
            count += 1
        elif(board_rep[x][i] == T):
            if(count > best and board_rep[i+1][y] == 0):
                best = count+1
                ansx = x
                ansy = i+1
                count = 0
    return [ansx, ansy, best]


def diag1(board_rep, player_num, x, y):
    if(player_num == 1):
        U = 1
        T = 2
    else:
        U = 2
        T = 1
    count = 0
    best = 0
    ansx = -1
    ansy = -1
    # print(x, " ", y)
    if(x == 9 and y == 9):
        return [-1, -1, 0]
    for i in range(11):
        if(x == 0 or y == 0):
            break
        x -= 1
        y -= 1
    # print(x, " ", y)
    for i in range(0, 10, 1):
        if((x+i) == 9 or (y+i) == 9):
            break
        if(board_rep[x+i][y+i] == U):
            count += 1
        elif(board_rep[x+i][y+i] == T):
            if(count > best and board_rep[x+i+1][y+i+1] == 0):
                best = count+1
                ansx = x+i+1
                ansy = y+i+1
                count = 0
    # print(best)
    return [ansx, ansy, best]


def vertical(board_rep, player_num, x, y):
    if(player_num == 1):
        U = 1
        T = 2
    else:
        U = 2
        T = 1
    count = 0
    best = 0
    ansx = -1
    ansy = -1
    for i in range(10):
        if(board_rep[i][y] == U):
            count += 1
        elif(board_rep[i][y] == T):
            if(count > best and board_rep[i+1][y] == 0):
                best = count+1
                ansx = i+1
                ansy = y
                count = 0
    return [ansx, ansy, best]


def vertical2(board_rep, player_num, x, y):
    if(player_num == 1):
        U = 1
        T = 2
    else:
        U = 2
        T = 1
    count = 0
    best = 0
    ansx = -1
    ansy = -1
    for i in range(9, 0, -1):
        if(board_rep[i][y] == U):
            count += 1
        elif(board_rep[i][y] == T):
            if(count > best and board_rep[i-1][y] == 0):
                best = count+1
                ansx = i-1
                ansy = y
                count = 0
    return [ansx, ansy, best]


def diag1(board_rep, player_num, x, y):
    if(player_num == 1):
        U = 1
        T = 2
    else:
        U = 2
        T = 1
    count = 0
    best = 0
    ansx = -1
    ansy = -1
    # print(x, " ", y)
    if(x == 9 and y == 9):
        return [-1, -1, 0]
    for i in range(11):
        if(x == 0 or y == 0):
            break
        x -= 1
        y -= 1
    # print(x, " ", y)
    for i in range(0, 10, 1):
        if((x+i) == 9 or (y+i) == 9):
            break
        if(board_rep[x+i][y+i] == U):
            count += 1
        elif(board_rep[x+i][y+i] == T):
            if(count > best and board_rep[x+i+1][y+i+1] == 0):
                best = count+1
                ansx = x+i+1
                ansy = y+i+1
                count = 0
    # print(best)
    return [ansx, ansy, best]


def diag2(board_rep, player_num, x, y):
    if(player_num == 1):
        U = 1
        T = 2
    else:
        U = 2
        T = 1
    count = 0
    best = 0
    ansx = -1
    ansy = -1
    # print(x, " ", y)
    for i in range(10):
        if(x == 0 or y == 9):
            break
        x -= 1
        y += 1
    # print(x, " ", y)

    for i in range(0, 10, 1):
        if(x+i == 9 or y-i == 0):
            break
        if(board_rep[x+i][y-i] == U):
            count += 1
        elif(board_rep[x+i][y-i] == T):
            if(count > best and board_rep[x+i+1][y-i-1] == 0):
                best = count+1
                ansx = x+i+1
                ansy = y-i-1
                count = 0
    return [ansx, ansy, best]


