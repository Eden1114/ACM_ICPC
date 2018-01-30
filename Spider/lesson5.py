#!usr/bin/python
#coding = utf-8
from bs4 import BeautifulSoup
import requests

url = "https://www.ishadowsocks.xyz"
res = requests.get('url')

res.encoding = "utf=8"
soup = BeautifulSoup(res.text,'html.parser')

for  
