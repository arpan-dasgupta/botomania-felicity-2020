import React from 'react';
import './App.css';
import Board from './Board'

export default class Game extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      boardState: Array(100).fill(null),
      turn: 1,
    }

    this.apiUrl = "localhost:5000";
    this.board;
    this.timer; // timer for polling the backend
    this.pollInterval = 1000; // interval for polling
  }

  async poll() {
    try {
      let response = await fetch(`${apiUrl}/game/get_status`);
      if (response.ok) {
        let data = await response.json();
        this.setState({
          boardState: data["state"],
          turn: data["turn"],
        })
      }
      return data["success"];
    } catch {
      console.warn("Error fetching the board");
    }
  }

  componentDidMount() {
    this.timer = setInterval(this.poll, this.pollInterval) // setup polling
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
