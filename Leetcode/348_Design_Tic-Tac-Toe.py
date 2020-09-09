class TicTacToe:

    def __init__(self, n: int):
        """
        Initialize your data structure here.
        """
        self.n = n
        self.rows_1 = [0  for _ in range(n + 1)]
        self.rows_2 = [0  for _ in range(n + 1)]
        self.cols_1 = [0 for _ in range(n + 1)]
        self.cols_2 = [0  for _ in range(n + 1)]
        self.diag1 = [0 for _ in range(n + 1)]
        self.diag2 = [0 for _ in range(n + 1)]

            

    def move(self, row: int, col: int, player: int) -> int:
        """
        Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
        """
        n = self.n
        if player == 1:
            self.rows_1[row] += 1
            self.cols_1[col] += 1
        if player == 2:
            self.rows_2[row] += 1
            self.cols_2[col] += 1
        if row == col:
            self.diag1[row] = player
        if row + col + 1 == n:
            self.diag2[row] = player
        f = 0
        g = 0
        for i in range(n):
            if self.rows_1[row] == n or self.cols_1[col] == n:
                return 1
            if self.rows_2[row] == n or self.cols_2[col] == n:
                return 2 
            if self.diag1[i] != self.diag1[0]:
                f = 1
            if self.diag2[i] != self.diag2[0]:
                g = 1
        if f == 0:
            return self.diag1[0]
        if g == 0:
            return self.diag2[0]
        return 0

# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)
