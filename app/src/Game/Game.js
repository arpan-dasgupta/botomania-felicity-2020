import React from 'react';
import './Game.css';
import Board from './Board'

export default class Game extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      boardState: Array(100).fill(null),
      turn: 1
    };

    this.apiUrl = "http://0.0.0.0:5000";
    this.board = 0;
    this.timer = 0; // timer for polling the backend
    this.pollInterval = 1000; // interval for polling
  }

  poll = async () => {
    try {
      let response = await fetch("/game/get_status", {
        method: "GET",
        headers: {
          "Content-Type": "application/json"
        }
      });
      let data = await response.json();
      if (response.ok) {
        this.setState({
          boardState: data["state"],
          turn: data["turn"]
        });
      }
      return data["success"];
    } catch (err) {
      console.warn("Error fetching the board");
    }
  };

  componentDidMount() {
    this.timer = setInterval(this.poll, this.pollInterval); // setup polling
  }

  componentWillUnmount() {
    clearInterval(this.timer);
  }

  render() {
    return (
      <section className="game">
        <Board squares={this.state.boardState} turn={this.state.turn} />
      </section>
    );
  }
}
