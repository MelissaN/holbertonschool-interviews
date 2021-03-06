#!/usr/bin/python3
"""
Request data from API endpoints; export data in JSON format into file
"""
from collections import OrderedDict
import json
import requests


def display():
    """return API data"""
    dic = dict()

    users = requests.get("http://jsonplaceholder.typicode.com/users")
    for u in users.json():
        ID = str(u.get('id'))
        dic[ID] = [u.get('username')]

    todos = requests.get("http://jsonplaceholder.typicode.com/todos")
    for t in todos.json():
        task = OrderedDict()
        task["username"] = dic[str(t.get('userId'))][0]
        task["task"] = t.get('title')
        task["completed"] = t.get('completed')
        dic[str(t.get('userId'))].append(task)

    for i in dic:
        dic[i].pop(0)

    filename = "todo_all_employees.json"
    with open(filename, 'w') as f:
        json.dump(dic, f)


if __name__ == "__main__":
    display()
