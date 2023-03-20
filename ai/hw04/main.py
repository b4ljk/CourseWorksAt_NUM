
from queue import PriorityQueue

class UndirectedGraph:
    def __init__(self, graph_dict):
        self.graph_dict = graph_dict

    def get_vertices(self):
        return list(self.graph_dict.keys())

    def get_edges(self):
        edges = []
        for vertex in self.graph_dict:
            for neighbor, weight in self.graph_dict[vertex].items():
                edges.append((vertex, neighbor, weight))
        return edges

def dfs(graph, start, goal):
    visited = set()
    stack = [(start, [start])]
    while stack:
        vertex, path = stack.pop()
        if vertex not in visited:
            if vertex == goal:
                return path
            visited.add(vertex)
            for neighbor in graph.graph_dict[vertex]:
                if neighbor not in visited:
                    stack.append((neighbor, path + [neighbor]))

def bfs(graph, start, goal):
    visited = set()
    queue = [(start, [start])]
    while queue:
        vertex, path = queue.pop(0)
        if vertex not in visited:
            if vertex == goal:
                return path
            visited.add(vertex)
            for neighbor in graph.graph_dict[vertex]:
                if neighbor not in visited:
                    queue.append((neighbor, path + [neighbor]))

def ucs(graph, start, goal):
    visited = set()
    queue = PriorityQueue()
    queue.put((0, start, [start]))
    while not queue.empty():
        cost, vertex, path = queue.get()
        if vertex not in visited:
            if vertex == goal:
                return path, cost
            visited.add(vertex)
            for neighbor in graph.graph_dict[vertex]:
                if neighbor not in visited:
                    new_cost = cost + graph.graph_dict[vertex][neighbor]
                    queue.put((new_cost, neighbor, path + [neighbor]))

def heuristic(node, goal):
    euclidian_distance = {
    "Arad": 366,
    "Bucharest": 0,
    "Craiova": 160,
    "Dobreta": 242,
    "Eforie": 161,
    "Fagaras": 176,
    "Giurgiu": 77,
    "Hirsowa": 151,
    "Lasi": 226,
    "Lugoj": 244,
    "Mehadia": 241,
    "Neamt": 234,
    "Oradea": 380,
    "Pitesti": 100,
    "Rimnicu": 193,
    "Sibiu": 253,
    "Timisoara": 329,
    "Urziceni": 80,
    "Vaslui": 199,
    "Zerind": 374
    }
    return euclidian_distance[node]

def astar(graph, start, goal, heuristic):
    visited = set()
    queue = PriorityQueue()
    queue.put((0, start, [start]))
    while not queue.empty():
        cost, vertex, path = queue.get()
        if vertex not in visited:
            if vertex == goal:
                return path, cost
            visited.add(vertex)
            for neighbor in graph.graph_dict[vertex]:
                if neighbor not in visited:
                    new_cost = cost + graph.graph_dict[vertex][neighbor]
                    # buh neighbor-n huvid actual cost + heuristic cost nemeh baidlaar cost tootsoj
                    # priorityQueue-s hamgiin baha heuristics + actual cost buhii node garch ter zamaar yvsaar
                    # goal node ruu hurne
                    queue.put((new_cost + heuristic(neighbor, goal), neighbor, path + [neighbor]))

romania_map = UndirectedGraph({
    'Arad': {'Zerind': 75, 'Sibiu': 140, 'Timisoara': 118},
    'Zerind': {'Arad': 75, 'Oradea': 71},
    'Oradea': {'Zerind': 71, 'Sibiu': 151},
    'Timisoara': {'Arad': 118, 'Lugoj': 111},
    'Lugoj': {'Timisoara': 111, 'Mehadia': 70},
    'Mehadia': {'Lugoj': 70, 'Drobeta': 75},
    'Drobeta': {'Mehadia': 75, 'Craiova': 120},
    'Sibiu': {'Arad': 140, 'Oradea': 151, 'Fagaras': 99, 'Rimnicu': 80},
    'Rimnicu': {'Sibiu': 80, 'Craiova': 146, 'Pitesti': 97},
    'Craiova': {'Drobeta': 120, 'Rimnicu': 146, 'Pitesti': 138},
    'Fagaras': {'Sibiu': 99, 'Bucharest': 211},
    'Pitesti': {'Rimnicu': 97, 'Craiova': 138, 'Bucharest': 101},
    'Bucharest': {'Fagaras': 211, 'Pitesti': 101, 'Giurgiu': 90, 'Urziceni': 85},
    'Giurgiu': {'Bucharest': 90},
    'Urziceni': {'Bucharest': 85, 'Hirsova': 98, 'Vaslui': 142},
    'Hirsova': {'Urziceni': 98, 'Eforie': 86},
    'Eforie': {'Hirsova': 86},
    'Vaslui': {'Iasi': 92, 'Urziceni': 142},
    'Iasi': {'Vaslui': 92, 'Neamt': 87},
    'Neamt': {'Iasi': 87}
})

dfs_path = dfs(romania_map, 'Arad', 'Bucharest')
dfs_cost = 0
for i in range(len(dfs_path)-1):
    dfs_cost += romania_map.graph_dict[dfs_path[i]][dfs_path[i+1]]
for x in dfs_path:
    print(x, end=" => ")
print("Dfs Cost: ", dfs_cost)

bfs_path = bfs(romania_map, 'Arad', 'Bucharest')
bfs_cost = 0
for i in range(len(bfs_path)-1):
    bfs_cost += romania_map.graph_dict[bfs_path[i]][bfs_path[i+1]]
for x in bfs_path:
    print(x, end=" => ")
print("BFS Cost: ", bfs_cost)

ucs_path, ucs_cost = ucs(romania_map, 'Arad', 'Bucharest')
for x in ucs_path:
    print(x, end=" => ")
print("UCS Cost: ", ucs_cost)

astar_path, astar_cost = astar(romania_map, 'Arad', 'Bucharest', heuristic)
for x in astar_path:
    print(x, end=" => ")
print("A* Cost: ", astar_cost)