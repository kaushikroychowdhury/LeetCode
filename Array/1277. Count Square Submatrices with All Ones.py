def countSquares(matrix):
    '''
    count_sq = 0
    0 0 0 0 0       0 0 0 0 0
    0 0 1 1 1       0 0 1 1 1
    0 1 1 1 1       0 1 1 2 2
    0 0 1 1 1       0 0 1 2 3
    
    '''
    m = len(matrix)
    n = len(matrix[0])
    dp = [0]*(m+1)
    
    count = 0
    for i in range(m+1):
        dp[i] = [0]*(n+1)
        for j in range(1,n+1):
            if i>0 and matrix[i-1][j-1] == 1:
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1
                
                count += dp[i][j]
    return count
