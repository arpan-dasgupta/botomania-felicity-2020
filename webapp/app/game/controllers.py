"""
    This module describes the C part of our MVC arch

    this file defines the routes and manages requests to
    the server
"""

from flask import Blueprint, request, jsonify

from app import db
from .models import Game

mod_game = Blueprint("game", __name__, url_prefix="/game")

board_size = 10
game_state = [0 for i in range(board_size**2)]
ip1 = 0
ip2 = 0
turn = 0

# the C of CRUD


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
    global game_state
    global board_size
    global ip1
    global ip2
    global turn

    player1 = request.form["p1"]
    player2 = request.form["p2"]

    ip1 = request.form["ip1"]
    ip2 = request.form["ip2"]

    new_game = Game(player1, player2, board_size)

    board_size = int(request.form["board_size"])
    turn = 0
    game_state = [0 for i in range(board_size**2)]

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

    return jsonify(success=True, state=game_state, turn=turn)

# the D of CRUD
@mod_game.route("/make_move", methods=["POST"])
def delete_question(q_id):
    """
        Path: <root>/game/make_move

        Make a move in the game

    """
    # question = Quiz.query.filter(Quiz.id == q_id).first()

    r_pos = request.form["r_pos"]
    c_pos = request.form["c_pos"]
    global turn
    global game_state

    if (turn == 0 and request.remote_addr == ip1) or (turn == 1 and request.remote_addr == ip2):
        game_state[board_size*r_pos+c_pos] = turn
        turn = 3 - turn
        return jsonify(success=True)

    return jsonify(success=False)
