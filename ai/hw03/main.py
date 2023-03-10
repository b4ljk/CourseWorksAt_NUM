class UndirectedGraph:
    def __init__(self, graph_dict=None):
        """ initializes a graph object """
        if graph_dict == None:
            graph_dict = {}
        self.__graph_dict = graph_dict

    def vertices(self):
        """ returns the vertices of a graph """
        return list(self.__graph_dict.keys())

    def edges(self):
        """ returns the edges of a graph """
        return self.__generate_edges()

    def add_vertex(self, vertex):
        """ If the vertex "vertex" is not in
            self.__graph_dict, a key "vertex" with an empty
            list as a value is added to the dictionary.
            Otherwise nothing has to be done.
        """
        if vertex not in self.__graph_dict:
            self.__graph_dict[vertex] = []

    def add_edge(self, edge):
        """ assumes that edge is of type set, tuple or list;
            between two vertices can be multiple edges!
        """
        edge = set(edge)
        (vertex1, vertex2) = tuple(edge)
        if vertex1 in self.__graph_dict:
            self.__graph_dict[vertex1].append(vertex2)
        else:
            self.__graph_dict[vertex1] = [vertex2]
        if vertex2 in self.__graph_dict:
            self.__graph_dict[vertex2].append(vertex1)
        else:
            self.__graph_dict[vertex2] = [vertex1]

    def __generate_edges(self):
        """ A static method generating the edges of the
            graph "graph". Edges are represented as sets
            with one (a loop back to the vertex) or two
            vertices
        """
        edges = []
        for vertex in self.__graph_dict:
            for neighbor in self.__graph_dict[vertex]:
                if {neighbor, vertex} not in edges:
                    edges.append({vertex, neighbor})
        return edges

    def find_isolated_vertices(self):
        """ returns a list of isolated vertices. """
        graph = self.__graph_dict
        isolated = []
        for vertex in graph:
            if not graph[vertex]:
                isolated += [vertex]
        return isolated

    def __str__(self):
        res = "vertices: "
        for k in self.__graph_dict:
            res += str(k) + " "
        res += "edges: "
        for edge in self.__generate_edges():
            res += str(edge) + " "
        return res

    def dfs(self, start, end, path=[]):
        path = path + [start]
        if start == end:
            yield path
        for node in self.__graph_dict[start]:
            if node not in path:
                yield from self.dfs(node, end, path)

    def bfs(self, start, end):
        queue = [(start, [start])]
        while queue:
            (vertex, path) = queue.pop(0)
            for next in set(self.__graph_dict[vertex]) - set(path):
                if next == end:
                    yield path + [next]
                else:
                    queue.append((next, path + [next]))
    
    def ucs(self, start, end):
        queue = [(start, [start], 0)]
        while queue:
            (vertex, path, cost) = queue.pop(0)
            for next in set(self.__graph_dict[vertex]) - set(path):
                if next == end:
                    yield path + [next], cost + self.__graph_dict[vertex][next]
                else:
                    queue.append((next, path + [next], cost + self.__graph_dict[vertex][next]))
            queue.sort(key=lambda x: x[2])
    
    
    
    
    
    

romania_map = UndirectedGraph(dict(
    Arad=dict(Zerind=75, Sibiu=140, Timisoara=118),
    Bucharest=dict(Urziceni=85, Pitesti=101, Giurgiu=90, Fagaras=211),
    Craiova=dict(Drobeta=120, Rimnicu=146, Pitesti=138),
    Drobeta=dict(Mehadia=75),
    Eforie=dict(Hirsova=86),
    Fagaras=dict(Sibiu=99),
    Hirsova=dict(Urziceni=98),
    Iasi=dict(Vaslui=92, Neamt=87),
    Lugoj=dict(Timisoara=111, Mehadia=70),
    Oradea=dict(Zerind=71, Sibiu=151),
    Pitesti=dict(Rimnicu=97),
    Rimnicu=dict(Sibiu=80),
    Urziceni=dict(Vaslui=142)))

print("DFS")
for path in romania_map.dfs('Arad', 'Bucharest'):
    print(path)

# print("BFS")
# for path in romania_map.bfs('Arad', 'Bucharest'):
#     print(path)

# print("UCS")
# for path in romania_map.ucs('Arad', 'Bucharest'):
#     print(path)