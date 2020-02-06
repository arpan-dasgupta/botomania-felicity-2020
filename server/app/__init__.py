from flask import Flask, render_template
from flask_sqlalchemy import SQLAlchemy
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

app.config.from_object("config")

app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False

db = SQLAlchemy(app)

@app.route("/", methods=["GET"])
def introduction():
    """
        Path: <root>
        Methods: GET

        Returns the introduction to experiment page
    """
    return render_template("introduction.html", topic="Introduction")


@app.route("/test", methods=["GET"])
def test():
    """
        Path: <root>/test
        Methods: GET

        For testing if the server is alive or not
    """
    return "Success"

from app.game.controllers import mod_game

app.register_blueprint(mod_game)

# build the database
db.create_all()
