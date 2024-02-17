## 2203. Minimum Weighted Subgraph With the Required Paths

**Difficulty:** Hard

### Topics
Graph Theory, Shortest Path, Dynamic Programming

### Companies
Not Specified

### Problem

You are given an integer `n` denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to `n - 1`.

You are also given a 2D integer array `edges` where `edges[i] = [fromi, toi, weighti]` denotes that there exists a directed edge from `fromi` to `toi` with weight `weighti`.

Lastly, you are given three distinct integers `src1`, `src2`, and `dest` denoting three distinct nodes of the graph.

Return the minimum weight of a subgraph of the graph such that it is possible to reach `dest` from both `src1` and `src2` via a set of edges of this subgraph. In case such a subgraph does not exist, return `-1`.

A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.

