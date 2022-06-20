import socket
import sys
import json

<<<<<<< HEAD
s = socket.socket()

port = 8080

s.connect(('192.168.56.103', port))

data = s.recv(1024)
data = data.decode("utf-8")

s.send(b'Thank you from client!');

dataJ = json.loads(data)

print (type(dataJ))
print(dataJ)

s.close()
=======
mydata = {"id": 505012, "name": "Azizi", "age": "29"}
sendData = json.dumps(mydata)

s = socket.socket()
print("Socket successfully created")

port = 8080

s.bind(('', port))
print("socket binded to " + str(port))

s.listen(5)
print("socket is listening")

while True:
        c, addr = s.accept()
        print("Got connection from" + str(addr))

        c.sendall(bytes(sendData,encoding="utf-8"))
        buffer = c.recv(1024)
        print(buffer)
c.close()
>>>>>>> c7283697c449f4c38eb0389eee301c904d956887
