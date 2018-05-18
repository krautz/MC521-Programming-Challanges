import sys

dp = [0] * 1001

dp[1] = 2
dp[2] = 5
dp[3] = 13

for i in range (4, 1001):
    dp[i] = 2*dp[i-1] + dp[i-2] + dp[i-3]

for entrada in sys.stdin:
    print (dp[int(entrada)])
