import requests
newurl = "https://www.baidu.com"
res = requests.get(newurl)
res.encoding = 'utf-8'
print(res.text)

