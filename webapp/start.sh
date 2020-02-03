#!/bin/bash

http -f POST :5000/game/start p1=me p2=you ip1=127.0.0.1 ip2=127.0.0.1 board_size=10
