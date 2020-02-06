import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import GamePage from './Pages/game';
import Home from './Pages/home'
import * as serviceWorker from './serviceWorker';
import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link,
} from "react-router-dom";

class App extends React.Component {
  render() {
    const basename = "/botomania";
    return (
      <Router basename={basename}>
        <div>
          <nav className="navbar navbar-expand-sm navbar-light bg-light">
            <a className="navbar-brand" href={basename + "/"}>Botomania</a>

            <button className="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarToggler">
              <span className="navbar-toggler-icon"></span>
            </button>

            <div className="collapse navbar-collapse" id="navbarToggler">
              <ul className="navbar-nav ml-auto">
                <li>
                  <Link to="/" className="nav-link active">Home</Link>
                </li>
                <li>
                  <Link to="/instructions" className="nav-link">Instructions</Link>
                </li>
                <li>
                  <Link to="/test" className="nav-link">Test</Link>
                </li>
              </ul>
            </div>
          </nav>

          {/* A <Switch> looks through its children <Route>s and
            renders the first one that matches the current URL. */}
          <Switch>
            <Route exact path="/">
              <Home />
            </Route>
            <Route exact path="/instructions">
            </Route>
            <Route exact path="/test">
            </Route>
            <Route exact path="/game/:port" component={GamePage} />
          </Switch>
        </div>
      </Router>
    );
  }
}

ReactDOM.render(<App />, document.getElementById('root'));

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
serviceWorker.unregister();
