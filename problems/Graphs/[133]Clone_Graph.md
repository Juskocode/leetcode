# 133. Clone Graph
-*Difulculty*: Medium
- *Topics* : Hash Table, Depth-First Search, Breadth-First Search, Graph
- *Companies*

Given a reference of a node in a connected undirected graph.
Return a (clone) of the graph.
Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
