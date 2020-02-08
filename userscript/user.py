from solution import make_move
import requests
import time
import sys

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Incorrect number of arguments")
        exit(1)

    port = sys.argv[1]
    player_id = sys.argv[2]

    if port > 5009 or port < 5000:
        print("Incorrect port")
        exit(1)

    if player_id < 1 or player_id > 2:
        print("Incorrect player id")
        exit(1)

    URL = f"https://threads.iiit.ac.in:{port}/game/get_status"
    URL_POST = f"https://threads.iiit.ac.in:{port}/game/make_move"

    # sending get request and saving the response as response object
    while(True):
        r = requests.get(url=URL)
        # extracting data in json format
        data = r.json()
        if data['success'] == True and int(data['turn']) == player_id:

            inp_data = []
            for i in range(0, 10):
                temp = []
                for j in range(0, 10):
                    temp.append(int(data['state'][i*10 + j]))
                inp_data.append(temp.copy())
                temp.clear()
            print(inp_data)
            ##########
            # call user function here
            move = make_move(inp_data, player_id)
            ##########
            data = {'r_pos': move[0],
                    'c_pos': move[1]}

            # sending post request and saving response as response object
            r = requests.post(url=URL_POST, data=data)

            print(move)

            # extracting response text
            pastebin_url = r.text
            print(pastebin_url)
        time.sleep(1)

    # print(data)
