class Solution(object):
    
    def dfs(self, board, a, b):
        if a>=0 and a<len(board) and b>=0 and b<len(board[0]) and board[a][b]=='O':
            board[a][b]='P'
            self.dfs(board, a+1, b)
            self.dfs(board, a-1, b)
            self.dfs(board, a, b+1)
            self.dfs(board, a, b-1)
        else:
            return
    
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        m = len(board)
        
        if m==0:
            return
        
        n = len(board[0])
        
        for i in range(m):
            if board[i][0]=='O':
                self.dfs(board, i, 0)
                
        for i in range(m):
            if board[i][n-1]=='O':
                self.dfs(board, i, n-1)
                
        for i in range(n):
            if board[0][i]=='O':
                self.dfs(board, 0, i)
                
        for i in range(n):
            if board[m-1][i]=='O':
                self.dfs(board, m-1, i)
                
        for i in range(m):
            for j in range(n):
                if board[i][j]=='O':
                    board[i][j]='X'
        
        for i in range(m):
            for j in range(n):
                if board[i][j]=='P':
                    board[i][j]='O'
