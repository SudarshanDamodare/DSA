if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1)
  {
    visited[i][j] = 1;
    pathRec(i - 1, j, grid, n, res, path + 'L', visited);
    visited[i][j] = 0;
  