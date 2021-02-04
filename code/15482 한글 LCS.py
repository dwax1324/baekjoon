import sys
a = input()
b = input()
sys.setrecursionlimit(10**6)
dp = [[-1 for i in range(1001)] for i in range(1001)]
def lcs(i,j):
    if(i == len(a) or j == len(b)):
        return 0
    if(dp[i][j] != -1):
        return dp[i][j]
    if(a[i] == b[j]):
        dp[i][j] = max(dp[i][j], lcs(i+1,j+1)+1)
    else:
        dp[i][j] = max(dp[i][j],lcs(i+1,j),lcs(i,j+1))
    return dp[i][j]



print(lcs(0,0))