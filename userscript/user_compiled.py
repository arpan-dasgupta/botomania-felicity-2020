import subprocess
import requests
import sys
import time

if __name__ == "__main__":
    URL = "https://threads.iiit.ac.in:5005/game/get_status"
    URL_POST = "https://threads.iiit.ac.in:5005/game/make_move"
    player_id = 1

    # sending get request and saving the response as response object
    while(True):
        r = requests.get(url=URL)
        # extracting data in json format
        data = r.json()

        if data['success'] == True and data['turn'] == player_id:
            # Write data in file
            inp = open('input.in', 'w')
            for i in range(0, 10):
                for j in range(0, 10):
                    inp.write(f"{data['state'][i*10 + j]} ")
                inp.write('\n')
            inp.write(str(player_id))
            inp.close()

            print(data)

            # call user binary here
            try:
                subprocess.run('./a.out', timeout=3)
                out = open('output.out', 'r')
                r_pos = out.readline()[0]
                c_pos = out.readline()[0]
                out.close()
                data = {
                    'r_pos': int(r_pos),
                    'c_pos': int(c_pos)
                }
                print(r_pos, c_pos)
            except subprocess.TimeoutExpired:
                print("Program ran too long")
                data = {'r_pos': -1,
                        'c_pos': -1}

            # sending post request and saving response as response object
            r = requests.post(url=URL_POST, data=data)

            # extracting response text
            pastebin_url = r.text
            print(pastebin_url)
        time.sleep(1)
