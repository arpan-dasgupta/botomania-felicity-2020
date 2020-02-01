import React from 'react'
import Square from './Square'

export default class Board extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      squares: Array(100).fill(null),
      xIsNext: true,
    }
  }

  handleClick = (i) => {
    const squares = this.state.squares.slice();
    squares[i] = this.state.xIsNext ? 'X' : 'O';
    this.setState({
      squares: squares,
      xIsNext: !this.state.xIsNext,
    });
  }

  renderSquare(i) {
    return (
      <Square 
        value={this.state.squares[i]}
        onClick={() => this.handleClick(i)}
      />
    )
  }

  render() {
    const status = 'Next player: ' + (this.state.xIsNext ? 'X' : 'O');
    
    const board = [];
    for (let i = 0; i < 10; i++) {
      const temp = []
      for (let j = 0; j < 10; j++) {
        temp.push(this.renderSquare(i*10+j));
      }
      board.push(
        <div className="board-row">
          {temp}
        </div>
      );
    }

    return (
      <div>
        <div className="status">{status}</div>
        {board}
      </div>
    );
  }
}