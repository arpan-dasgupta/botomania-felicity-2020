"""
This file contains db models for the game
"""

from itertools import islice

from flask_sqlalchemy import SQLAlchemy

from app import db


class Game(db.Model):
    """
        This is the model for game

        Attributes:
            id           : automatically generated primay key
            team1, team2 : Name of the teams who played this match (team1 starts the game)
            winner       : winner of this match
            moves        : position of piece placed on board [0-9a-zA-Z]
            board_size   : size of the board
    """
    __tablename__ = "game"
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)

    team1 = db.Column(db.String(63), nullable=False)
    team2 = db.Column(db.String(63), nullable=False)

    winner = db.Column(db.String(4), nullable=False)
    moves = db.Column(db.String(255), nullable=False)

    board_size = db.Column(db.SmallInteger, nullable=False)

    def __init__(self, team1, team2, board_size):
        """
            The constructor for this class
        """
        self.team1 = team1
        self.team2 = team2

        self.moves = ""
        self.winner = "11"

        self.board_size = board_size

    def __repr__(self):
        """
        This will make print(Game object) look good

        Prints the following:
            - the teams which are playing
            - how the board looks like right now
        """
        rep = self.team1 + " vs " + self.team2 + "\n"

        board = [[" " for i in range(self.board_size)]
                 for i in range(self.board_size)]

        rep += "Game:\n"

        # team1 starts the game
        team = 1

        for (str_row, str_col) in zip(islice(self.moves, 0, None, 2), islice(self.moves, 1, None, 2)):
            row, col = self.get_index(str_row, str_col)
            board[row][col] = team
            team ^= 3

        for i in range(self.board_size):
            for j in range(self.board_size):
                rep += (board[i][j] + " ")
            rep += "\n"

        return rep

    @staticmethod
    def get_index(str_row, str_col):
        """
        This is a helper function which converts string indices to
            row / col numeric ones based on the encoding [0-9a-zA-Z]
        """
        num_digits = 10
        num_lower = 26

        ret = []

        for ch in [str_row, str_col]:
            if ch.isdigit():
                ret.append(int(ch) - ord("0"))
            elif ch.islower():
                ret.append(ord(ch) - ord("a") + num_digits)
            else:
                ret.append(ord(ch) - ord("A") + num_digits + num_lower)

        return ret
