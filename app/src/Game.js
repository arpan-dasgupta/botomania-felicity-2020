import React from 'react';
import './App.css';
import Board from './Board'

export default class Game extends React.Component {
  render() {
    return (
      <section className="game">
        <Board />
      </section>
    );
  }
}
