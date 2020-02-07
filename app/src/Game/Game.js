import React from 'react';
import './Game.css';
import Board from './Board'

export default class Game extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      boardState: Array(100).fill(0),
      turn: 0,
      winner: 0,
    }

    this.apiUrl = `https://threads.iiit.ac.in:${props.port}`;
    this.board = null;
    this.timer = null; // timer for polling the backend
    this.pollInterval = 3000; // interval for polling
  }

  poll = async () => {
    try {
      let response = await fetch(`${this.apiUrl}/game/get_status`, {
        method: "GET",
        headers: {
          "Content-Type": "application/json"
        }
      });
      let data = await response.json();
      if (response.ok) {
        this.setState({
          boardState: data["state"],
          turn: data["turn"],
          winner: data["winner"]
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
      <div className="container">
        <div className="row justify-content-center">
          <Board squares={this.state.boardState} turn={this.state.turn} />
        </div>
        <div className="row justify-content-center mt-3">
          {parseInt(this.state.winner) !== 0 &&
            <h2>
              Winner:
            </h2>
          }
          {parseInt(this.state.winner) === 1 &&
            <svg height="3em" width="3em">
              <circle cx="1.5em" cy="1.5em" r="1em" fill="#111"></circle>
            </svg>
          }
          {parseInt(this.state.winner) === 2 &&
            <svg height="3em" width="3em">
              <circle cx="1.5em" cy="1.5em" r="1em" stroke="#111" strokeWidth="2" fill="#eee"></circle>
            </svg>
          }
        </div>
        <div className="row justify-content-center mt-3">
          <h2>Next Player:
          </h2>
          {parseInt(this.state.turn) === 1 &&
            <svg height="3em" width="3em">
              <circle cx="1.5em" cy="1.5em" r="1em" fill="#111"></circle>
            </svg>
          }
          {parseInt(this.state.turn) === 2 &&
            <svg height="3em" width="3em">
              <circle cx="1.5em" cy="1.5em" r="1em" stroke="#111" strokeWidth="2" fill="#eee"></circle>
            </svg>
          }
        </div>
      </div>
    );
  }
}
