# 787. Cheapest Flights Within K Stops

**Medium**

## Topics:
- Dynamic Programming, Depth-First Search, Breadth-First Search, Graph, Heap (Priority Queue), Shortest Path

## Companies:
- Not specified

There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [fromi, toi, pricei]` indicates that there is a flight from city `fromi` to city `toi` with cost `pricei`.

You are also given three integers `src`, `dst`, and `k`, return the cheapest price from `src` to `dst` with at most `k` stops. If there is no such route, return `-1`.

**Example:**

Input: 
- `n = 3`
- `flights = [[0,1,100],[1,2,100],[0,2,500]]`
- `src = 0`
- `dst = 2`
- `k = 1`

Output: `200`

Explanation: The graph is shown below:

