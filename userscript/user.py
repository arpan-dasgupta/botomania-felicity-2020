
import requests
import time


def sample_move(state, turn):
    return (3, 4)


if __name__ == "__main__":
    URL = "http://0.0.0.0:5000/game/get_status"
    URL_POST = "http://0.0.0.0:5000/game/make_move"
    player_id = 1

    # sending get request and saving the response as response object
    while(True):
        r = requests.get(url=URL)
        # extracting data in json format
        data = r.json()

        if data['success'] == True and data['turn'] == player_id:
            print(data)
            ##########
            # call user function here
            move = sample_move(data['state'], data['turn'])
            ##########
            data = {'r_pos': move[0],
                    'c_pos': move[1]}

            # sending post request and saving response as response object
            r = requests.post(url=URL_POST, data=data)

            # extracting response text
            pastebin_url = r.text
            print(pastebin_url)
        time.sleep(1)

    # print(data)
