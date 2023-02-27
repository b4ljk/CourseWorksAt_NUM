test = ["xyz", "x a z"]
for x in test:
    if x.startswith("xyz") or x.endswith("xyz"):
        print(x)
