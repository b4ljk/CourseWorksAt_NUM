import random

class MemoryAgent:
    def __init__(self):
        self.visited = set()   # set to keep track of visited locations
    
    def get_action(self, percept):
        location, status = percept
        
        self.visited.add(location)
        
        if status == 1:    # dirty
            return "clean"
        elif location == 1:
            return "right"
        elif location == 2:
            return "left"
        else:
            if len(self.visited) == 2:
                return random.choice(["left", "right"])
            else:
                return "do_nothing"