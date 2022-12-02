package main

import "math"

// https://charlesliuyx.github.io/2018/10/11/%E3%80%90%E7%9B%B4%E8%A7%82%E7%AE%97%E6%B3%95%E3%80%91Egg%20Puzzle%20%E9%B8%A1%E8%9B%8B%E9%9A%BE%E9%A2%98/#4-1-%E5%9F%BA%E7%A1%80%E7%89%88
func superEggDrop(k int, n int) int {
	if k < 1 || n < 1 {
		return 0
	}

	// f is matrix of (k+1) X (n+1)
	f := make([][]float64, k+1)
	for i := 0; i <= k; i++ {
		a := make([]float64, n+1)
		f[i] = a
	}

	for i := 2; i <= k; i++ {
		for j := 1; j <= n; j++ {
			for x := 1; x < j; x++ {
				f[i][j] = math.Min((f[i][j]), 1+math.Max(f[i-1][x-1], f[i][j-x]))
			}
		}
	}

	return int(f[k][n])
}
