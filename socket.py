import socket
# for client
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.conect(('www.baidu.com',80))
s.send('GET / HTTP/1.1\r\nHost: www.baidu.com.cn\r\nConnection: close\r\n\r\n')
buffer = []
while True:
    d = s.recv(1024)
    if d:
        buffer.append(d)
    else:
        break
data = ''.join(buffer)
s.close()
print header
with open('baidu.html','wb') as f:
    f.write(html)
# for server
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

s.bind(('127.0.0.1',9999))
listen()
s.listen(5)
print 'Waiting for connection...'

while True:
    sock,addr = s.accept()
    t = threading.Thread(tatget=tcplink,args=(sock,addr))
    t.start()















