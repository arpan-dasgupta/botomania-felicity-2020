import React from 'react'
import Square from './Square'

export default class Board extends React.Component {
  renderSquare(i) {
    return (
      <Square
        value={this.props.squares[i]}
      />
    )
  }

  render() {
    const board = [];
    for (let i = 0; i < 10; i++) {
      const temp = []
      for (let j = 0; j < 10; j++) {
        temp.push(this.renderSquare(i * 10 + j));
      }
      board.push(
        <tr>
          {temp}
        </tr>
      );
    }

    return (
      <div className="board">
        <table>
          <tbody>
            {board}
          </tbody>
        </table>
      </div>
    );
  }
}