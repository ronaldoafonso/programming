
import requests

r = requests.get('http://localhost:8080/user/username')
print(r.text)

r = requests.post('http://localhost:8080/user/username')
print(r.text)

r = requests.put('http://localhost:8080/user/username')
print(r.text)

r = requests.delete('http://localhost:8080/user/username')
print(r.text)
