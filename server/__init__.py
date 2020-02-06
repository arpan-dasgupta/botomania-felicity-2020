from app import app
import sys

if len(sys.argv) == 1:
    print("Please provide the port on which the app should run")
    exit()

port = sys.argv[1]

if __name__=="__main__":
    app.run(host="0.0.0.0", port=port, ssl_context=("cert.pem", "key.pem"))
