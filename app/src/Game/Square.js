import React from 'react';

export default class Square extends React.Component {
  render() {
    return (
      <td className="square p-0" >
        {this.props.value === 1 &&
          <svg height="2.8em" width="2.8em">
            <circle cx="1.5em" cy="1.5em" r="1em" fill="#111"></circle>
          </svg>
        }
        {this.props.value === 2 &&
          <svg height="2.8em" width="2.8em">
            <circle cx="1.5em" cy="1.5em" r="1em" fill="#eee"></circle>
          </svg>
        }
      </td>
    );
  }
}