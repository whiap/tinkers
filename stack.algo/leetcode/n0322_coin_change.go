package main

func coinChange(coins []int, amount int) int {
	dp, length := make([]int, amount+1), amount+1
	dp[0] = 0
	for i := 1; i < length; i++ {
		dp[i] = amount + 1
	}
	for i := 1; i < length; i++ {
		for j := 0; j < len(coins); j++ {
			if coins[j] > i {
				continue
			}
			if val := dp[i-coins[j]] + 1; val < dp[i] {
				dp[i] = val
			}
		}
	}
	if dp[amount] > amount {
		return -1
	}
	return dp[amount]
}
