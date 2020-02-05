import React from 'react'
import Game from '../Game/Game'

export default class GamePage extends React.Component {
  render() {
    return (
      <section>
        <div className="container my-5">
          <Game port={this.props.match.params.port}/>
        </div>
      </section>
    );
  }
}