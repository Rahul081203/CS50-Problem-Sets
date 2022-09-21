d = [{"name":"Rahul", "marks": "100"}, {"name": "yash", "marks": "100"}]
list_name = []
list_name.append(list(d[0].keys()))
list_name.append(list(d[1].keys()))
print(f"{list_name}")