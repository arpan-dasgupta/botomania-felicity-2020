"""
    This module describes the C part of our MVC arch

    this file defines the routes and manages requests to
    the server
"""

from flask import Blueprint, request, jsonify

from app import db
from .models import Game

mod_quiz = Blueprint("quiz", __name__, url_prefix="/quiz")

# the C of CRUD
@mod_quiz.route("/add", methods=["POST"])
def add_question():
    """
        Path: <root>/quiz/add
        Methods: POST

        Adds a question to the database
    """

    question = request.form["question"]
    is_mcq = request.form["is_mcq"]

    if is_mcq == "true":
        opt_a = request.form["opt_a"]
        opt_b = request.form["opt_b"]
        opt_c = request.form["opt_c"]
        opt_d = request.form["opt_d"]

        is_mcq = True
    else:
        opt_a = opt_b = opt_c = opt_d = ""
        is_mcq = False

    answer = request.form["answer"]

    quiz_question = Quiz(question, is_mcq, answer, opt_a, opt_b, opt_c, opt_d)

    db.session.add(quiz_question)
    db.session.commit()

    return jsonify(success=True, question=quiz_question.to_dict())

# the R of CRUD
@mod_quiz.route("/all", methods=["GET"])
def show_all_questions():
    """
        Path: <root>/quiz/all
        Methods: GET

        Returns a json object containing all the questions
    """
    all_questions = Quiz.query.all()

    return jsonify(success=True, questions=[question.to_dict() for question in all_questions])

# the D of CRUD
@mod_quiz.route("/del/<q_id>", methods=["POST"])
def delete_question(q_id):
    """
        Path: <root>/quiz/del/<id>

        Deletes the quesiton [if found] from the database
    """
    question = Quiz.query.filter(Quiz.id == q_id).first()

    if question is None:
        return jsonify(success=False), 404

    db.session.delete(question)
    db.session.commit()

    return jsonify(success=True)
