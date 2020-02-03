# Botomania2020-sim

# Main routes:
 - [G] `/test`: Check if the server is alive
 - [P] `/game/start`: Starts the game
 - [G] `/game/get_status`: Returns the state of the game
 - [P] `/game/make_move`: Keep a piece at a position on board

## /game/start
Args:
 - p1: Name of team1
 - p2: Name of team2
 - ip1: IP addr of team1
 - ip2: IP addr of team2
 - board\_size: Board dimen

Returns:
 - True

## /game/get\_status
Returns:
 - True

## /game/make\_move
Args:
 - r\_pos: row number
 - c\_pos: col number

Returns:
 - Whether move was valid or not
