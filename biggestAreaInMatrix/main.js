function connectedCell(matrix) {
  const addZeroBorder = (mt) => {
    const res = [];
    const n = mt.length;
    const m = mt[0].length;
    for (let i = 0; i < n + 2; i++) {
      res[i] = [];
      for (let j = 0; j < m + 2; j++) {
        res[i][j] = 0;
      }
    }
    for (let i = 1; i < n + 1; i++) {
      res[i] = [0, ...mt[i - 1], 0];
    }
    return res;
  };
  const dx = [-1, 0, 1, -1, 1, -1, 0, 1];
  const dy = [-1, -1, -1, 0, 0, 1, 1, 1];
  const dfs = (x, y) => {
    ++count;

    visited[x][y] = true;
    for (let k = 0; k < 8; k++) {
      if (!visited[x + dx[k]][y + dy[k]] && mtr[x + dx[k]][y + dy[k]] === 1) {
        dfs(x + dx[k], y + dy[k]);
      }
    }
  };
  const mtr = addZeroBorder(matrix);
  const visited = [];
  for (let i = 0; i < mtr.length; i++) {
    visited[i] = [];
    for (let j = 0; j < mtr[0].length; j++) {
      visited[i][j] = false;
    }
  }
  let res = 0;
  let count = 0;
  for (let i = 0; i < mtr.length; i++) {
    for (let j = 0; j < mtr[0].length; j++) {
      if (!visited[i][j] && mtr[i][j] === 1) {
        count = 0;
        dfs(i, j);
        if (count > res) {
          res = count;
        }
      }
    }
  }
  return res;
}

const matrix1 = [
  [1, 1, 0, 1],
  [0, 1, 0, 1],
  [0, 1, 0, 1],
  [0, 1, 0, 1],
  [1, 1, 0, 1],
];
const matrix2 = [
  [1, 1, 0, 0],
  [0, 1, 1, 0],
  [0, 0, 1, 0],
  [1, 0, 0, 0],
];

const labirint = [
    [0,0,1,1,0,0,1],
    [0,0,1,1,0,0,1],
    [0,1,0,0,0,0,1],
    [0,0,1,1,0,0,1],
    [0,0,1,0,1,1,1],
    [0,0,1,1,0,0,1],
    [0,0,1,1,0,0,1],
    [0,0,1,1,0,0,1],
]

console.log(connectedCell(labirint));

