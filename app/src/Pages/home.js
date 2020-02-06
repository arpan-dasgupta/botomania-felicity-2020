import React from 'react';

export default class Home extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      team1: Array(10).fill("None"),
      team2: Array(10).fill("None"),
    };

    this.apiUrl = "https://threads.iiit.ac.in";
    this.timer = null;
    this.pollInterval = 1000;
  }

  componentDidMount() {
    this.interval = setInterval(this.poll, this.pollInterval);
  }

  componentWillUnmount() {
    clearInterval(this.timer);
  }


  // TODO - Test this function
  poll = async () => {
    let ports = [5000, 5001, 5002, 5003, 5004, 5005, 5006, 5007, 5008, 5009];

    let data = await Promise.all(
      ports.map(async port => {
        try {
          let response = await fetch(`${this.apiUrl}:${port}/game/get_status`, {
            "method": "GET",
            "headers": {
              "Content-Type": "application/json"
            }
          });
          return response.json();
        } catch (err) {
          console.log(err.message);
          console.log(`Error getting the status on port ${port}`);
        }
      })
    );

    data.forEach((game, i) => {
      if (game !== undefined && parseInt(game["turn"]) !== 0) {
        this.setState(prevState => {
          let team1 = prevState.team1.map((team, j) => {
            if (i === j) {
              return game["p1"];
            } else {
              return team;
            }
          });
          let team2 = prevState.team2.map((team, j) => {
            if (i === j) {
              return game["p2"];
            } else {
              return team;
            }
          });

          return {
            "team1": team1,
            "team2": team2,
          }
        });
      } else {
        this.setState(prevState => {
          let team1 = prevState.team1.map((team, j) => {
            if (i === j) {
              return "None";
            } else {
              return team;
            }
          });
          let team2 = prevState.team2.map((team, j) => {
            if (i === j) {
              return "None";
            } else {
              return team;
            }
          });

          return {
            "team1": team1,
            "team2": team2,
          }
        });
      }
    });
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
                <th>Team 1</th>
                <th>Team 2</th>
              </tr>
            </thead>
            <tbody>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5000">
                <th scope="row">1</th>
                <td>{this.state.team1[0]}</td>
                <td>{this.state.team2[0]}</td>
              </Tr>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5001">
                <th scope="row">2</th>
                <td>{this.state.team1[1]}</td>
                <td>{this.state.team2[1]}</td>
              </Tr>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5002">
                <th scope="row">3</th>
                <td>{this.state.team1[2]}</td>
                <td>{this.state.team2[2]}</td>
              </Tr>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5003">
                <th scope="row">4</th>
                <td>{this.state.team1[3]}</td>
                <td>{this.state.team2[3]}</td>
              </Tr>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5004">
                <th scope="row">5</th>
                <td>{this.state.team1[4]}</td>
                <td>{this.state.team2[4]}</td>
              </Tr>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5005">
                <th scope="row">6</th>
                <td>{this.state.team1[5]}</td>
                <td>{this.state.team2[5]}</td>
              </Tr>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5006">
                <th scope="row">7</th>
                <td>{this.state.team1[6]}</td>
                <td>{this.state.team2[6]}</td>
              </Tr>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5007">
                <th scope="row">8</th>
                <td>{this.state.team1[7]}</td>
                <td>{this.state.team2[7]}</td>
              </Tr>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5008">
                <th scope="row">9</th>
                <td>{this.state.team1[8]}</td>
                <td>{this.state.team2[8]}</td>
              </Tr>
              <Tr href="https://threads.iiit.ac.in/botomania/game/5009">
                <th scope="row">10</th>
                <td>{this.state.team1[9]}</td>
                <td>{this.state.team2[9]}</td>
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