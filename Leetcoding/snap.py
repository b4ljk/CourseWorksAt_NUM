import networkx as nx
import matplotlib.pyplot as plt

# Load the graph from data file
G = nx.read_edgelist('/Users/baljinnyamdayan/Downloads/data.txt')

# Calculate the degree of each node
degree_sequence = sorted([d for n, d in G.degree()], reverse=True)

# Plot the degree distribution as a histogram
plt.hist(degree_sequence, bins='auto')
plt.title('Degree distribution')
plt.xlabel('Degree')
plt.ylabel('Frequency')
plt.show()
