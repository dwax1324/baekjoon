# 피보나치
# BIG INTEGER 지원 파이썬 짱짱
a = int(input())

dp = [i for i in range(1000000)]

dp[1] = 1
dp[2] = 1


for i in range(3, a+1):
    dp[i] = dp[i-1] + dp[i-2]

print(dp[a])
