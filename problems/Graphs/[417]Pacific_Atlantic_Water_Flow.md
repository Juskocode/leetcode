# 417. Pacific Atlantic Water Flow

You are given an `m x n` integer matrix `heightMap` representing the height of each unit cell in a continent. The continent is surrounded by the Pacific Ocean to the left and top and the Atlantic Ocean to the right and bottom.

Water can only flow in four directions: up, down, left, and right. Water flows from a cell to an adjacent one with an equal or lower height.

Return a list of grid coordinates where water can flow to both the Pacific and Atlantic oceans.

**Note:**

- The order of returned grid coordinates does not matter.
- Both `m` and `n` are less than 150.

**Example 1:**

Input: `heightMap = [[1,2,2,3,5],
                   [3,2,3,4,4],
                   [2,4,5,3,1],
                   [6,7,1,4,5],
                   [5,1,1,2,4]]`

Output: `[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]`
