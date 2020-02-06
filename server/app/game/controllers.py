"""
    This module describes the C part of our MVC arch

    this file defines the routes and manages requests to
    the server
"""

from flask import Blueprint, request, jsonify

from app import db
from .models import Game
import time

mod_game = Blueprint("game", __name__, url_prefix="/game")

player1 = ""
player2 = ""
board_size = 10
game_state = [0 for i in range(board_size**2)]
ip1 = 0
ip2 = 0
turn = 0
winner = 0
gid = 0


def move(player, r_n, c_n):
    global board_size
    global game_state

    print(player, r_n, c_n)
    flag = 0
    p1_c = 0
    p2_c = 0

    for x in game_state:
        if x == 1:
            p1_c += 1
        else:
            p2_c += 1
        if x == 0:
            flag = 1

    if flag == 0:
        if p1_c > p2_c:
            return 1
        if p1_c < p2_c:
            return 2
        return 3

    if r_n < 0 or c_n < 0 or r_n >= board_size or c_n >= board_size:
        return (3-player)

    # print("yo")
    # print(game_state[r_n*board_size + c_n])
    if game_state[r_n*board_size + c_n] != 0:
        return -1

    to_flip = []

    for i in range(r_n+1, board_size):
        if game_state[i*board_size+c_n] == 0:
            break
        if game_state[i*board_size+c_n] == player:
            for j in range(r_n+1, i):
                to_flip.append(j*board_size+c_n)
            break
    for i in range(c_n+1, board_size):
        if game_state[r_n*board_size+i] == 0:
            break
        if game_state[r_n*board_size+i] == player:
            for j in range(c_n+1, i):
                to_flip.append(r_n*board_size+j)
            break
    for i in range(r_n-1, -1, -1):
        if game_state[i*board_size+c_n] == 0:
            break
        if game_state[i*board_size+c_n] == player:
            for j in range(r_n-1, i, -1):
                to_flip.append(j*board_size+c_n)
            break
    for i in range(c_n-1, -1, -1):
        if game_state[r_n*board_size+i] == 0:
            break
        if game_state[r_n*board_size+i] == player:
            for j in range(c_n-1, i, -1):
                to_flip.append(r_n*board_size+j)
            break

    i = r_n+1
    j = c_n+1
    while i < board_size and j < board_size:
        if game_state[i*board_size+j] == 0:
            break
        if game_state[i*board_size+j] == player:
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
        if game_state[i*board_size+j] == 0:
            break
        if game_state[i*board_size+j] == player:
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
        if game_state[i*board_size+j] == 0:
            break
        if game_state[i*board_size+j] == player:
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
        if game_state[i*board_size+j] == 0:
            break
        if game_state[i*board_size+j] == player:
            rr = r_n-1
            cc = c_n+1
            while rr > i and cc < j:
                to_flip.append(rr*board_size+cc)
                rr -= 1
                cc += 1
            break
        i -= 1
        j += 1

    if len(to_flip) == 0:
        return -1
    to_flip.append(r_n*board_size+c_n)
    for e in to_flip:
        game_state[e] = player
    # print("yo")
    return 0

# @mod_game.route("/delete", methods=["POST"])
# def delete():
#     """
#         Path: <root>/game/delete
#         Methods: POST

#         Delete all records from database
#     """
#     db.drop_all()
#     return jsonify(success=True)


@mod_game.route("/display", methods=["GET"])
def delete():
    """
        Path: <root>/game/display
        Methods: POST

        Display all records
    """
    return jsonify(success=True)


@mod_game.route("/start", methods=["POST"])
def start():
    """
        Path: <root>/game/start
        Methods: POST

        Start game and init database
    """
    global winner
    global player1
    global player2
    global game_state
    global board_size
    global ip1
    global ip2
    global turn
    global gid

    player1 = request.form["p1"]
    player2 = request.form["p2"]

    ip1 = request.form["ip1"]
    ip2 = request.form["ip2"]

    new_game = Game(player1, player2, board_size)
    gid = new_game.id

    board_size = int(request.form["board_size"])
    turn = 1
    winner = 0
    game_state = [0 for i in range(board_size**2)]
    p = int((board_size**2) / 2)
    print(p)
    # game_state[p] = 999
    game_state[p - int(board_size/2)] = 1
    game_state[p - int(board_size/2) - 1] = 2
    game_state[p + int(board_size/2)] = 2
    game_state[p + int(board_size/2) - 1] = 1

    db.session.add(new_game)
    db.session.commit()

    return jsonify(success=True)

# the R of CRUD
@mod_game.route("/get_status", methods=["GET"])
def get_status():
    """
        Path: <root>/game/get_status
        Methods: GET

        Returns a json object containing board state
    """
    # all_questions = Game.query.all()
    # if winner != 0:
    return jsonify(success=True, state=game_state, turn=turn, winner=winner, p1=player1, p2=player2)
    # return jsonify(success=True, state=game_state, turn=turn, p1=player1, p2=player2)

# the D of CRUD
@mod_game.route("/make_move", methods=["POST"])
def make_move():
    """
        Path: <root>/game/make_move

        Make a move in the game

    """
    # question = Quiz.query.filter(Quiz.id == q_id).first()

    r_pos = int(request.form["r_pos"])
    c_pos = int(request.form["c_pos"])
    global turn
    global game_state
    global board_size
    global winner
    # print(request.remote_addr)

    if winner != 0:
        return jsonify(success=False)

    if (turn == 1 and request.remote_addr == ip1) or (turn == 2 and request.remote_addr == ip2):
        # game_state[board_size*r_pos+c_pos] = turn
        rv = move(turn, r_pos, c_pos)
        if rv == 0:
            turn ^= 3
            time.sleep(1)
            return jsonify(success=True)
        elif rv == -1:
            winner = (3-turn)
            cg = Game.query.filter_by(id=gid).first()
            cg.winner = str(rv)
            db.session.commit()
            return jsonify(success=False)
        else:
            winner = rv
            cg = Game.query.filter_by(id=gid).first()
            cg.winner = str(rv)
            db.session.commit()
            return jsonify(success=False)

    return jsonify(success=False)
