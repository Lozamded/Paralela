__author__ = 'Zhongpeng Lin'
"""
Graph algorithms implemented with networkx
"""
from networkx import Graph
import sys
import re
import itertools
import time


def read_graph(file):
    g = Graph()
    with open(file, 'r') as graph_file:
        for line in graph_file:
            if not line.startswith('#'):
                nodes = re.split('\s+', line.strip(), 1)
                if nodes[0] != nodes[1]:
                    g.add_edge(int(nodes[0]), int(nodes[1]))
    return g


def wedge_iterator(graph):
    for node in graph.nodes_iter():
        neighbors = graph.neighbors(node)
        for pair in itertools.combinations(neighbors, 2):
            yield (node, pair)


def count_triangle(graph):
    n = 0
    for wedge in wedge_iterator(graph):
        if graph.has_edge(wedge[1][0], wedge[1][1]) or graph.has_edge(wedge[1][1], wedge[1][0]):
            n += 1
    return n

if __name__ == '__main__':
    g = read_graph(sys.argv[1])
    print('Number of vertices:', g.number_of_nodes())
    print('Number of edges:', g.number_of_edges())
    n = 0
    start_time = time.time()
    n = count_triangle(g)
    print('Number of triangles:', n/3)
print('Time used:', time.time() - start_time)
