int min_(int a, int b) {
    return (a >= b) ? b : a;
}

int max_(int a, int b) {
    return (a >= b) ? a : b;
}

int isInside(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int dfs(int i, int j, char** matrix, int n, int m, int **memo) {
    if (!isInside(i, j, n, m) || matrix[i][j] == '0')
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];

    int right = dfs(i + 1, j, matrix, n, m, memo);
    int down = dfs(i, j + 1, matrix, n, m, memo);
    int diag = dfs(i + 1, j + 1, matrix, n, m, memo);

    return memo[i][j] = 1 + min_(min_(right, down), diag);
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int m = matrixColSize[0];
    int maxSize = 0;

    int **memo = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        memo[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
            memo[i][j] = -1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == '1')
                maxSize = max_(maxSize, dfs(i, j, matrix, n, m, memo));
    
    for (int i = 0; i < n; i++)
        free(memo[i]);
    free(memo);
    return maxSize * maxSize;
}