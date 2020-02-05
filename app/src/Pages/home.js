import React from 'react';

export default class Home extends React.Component {
  constructor(props) {
    super(props);

    this.apiUrl = null;
    this.timer = null;
    this.pollInterval = 1000;
  }

  componentDidMount() {
    this.interval = setInterval(this.poll, this.pollInterval);
  }

  componentWillUnmount() {
    clearInterval(this.timer);
  }

  poll = () => {
    // TODO
  }

  render() {
    return (
      <section className="d-flex mt-5">
        <div className="container">
          <div className="row justify-content-center mb-5">
            <h1>Current Status</h1>
          </div>
          <table className="table table-bordered table-hover table-responsive-sm">
            <thead>
              <tr>
                <th style={{ width: "7.5%" }}>#</th>
                <th>Player 1</th>
                <th>Player 2</th>
                <th>Winner</th>
              </tr>
            </thead>
            <tbody>
              <Tr href="https://www.google.co.in">
                <th scope="row">1</th>
                <td>Lorem</td>
                <td>Ipsum</td>
                <td>Ipsum</td>
              </Tr>
              <Tr href="https://www.google.co.in">
                <th scope="row">2</th>
                <td>Lorem</td>
                <td>Ipsum</td>
                <td>Ipsum</td>
              </Tr>
              <Tr href="https://www.google.co.in">
                <th scope="row">3</th>
                <td>Lorem</td>
                <td>Ipsum</td>
                <td>Lorem</td>
              </Tr>
              <Tr href="https://www.google.co.in">
                <th scope="row">4</th>
                <td>Lorem</td>
                <td>Ipsum</td>
                <td>In Progess</td>
              </Tr>
            </tbody>
          </table>
        </div>
      </section>
    );
  }
}

class Tr extends React.Component {
  handleClick = () => {
    window.location.href = this.props.href;
  }

  render() {
    return (
      <tr className="table-row" onClick={this.handleClick} style={{ cursor: "pointer" }}>
        {this.props.children}
      </tr>
    );
  }
}