package main

import (
	"math"
	"sort"
)

// https://leetcode.com/problems/3sum-closest/
func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	const u = 32 << (^uint(0) >> 32 & 1) // getconf is more reliable
	resi := 1<<(u-1) - 1                 // max int from https://yourbasic.org/golang/max-min-int-uint/
	rest := 0

	for idx := 1; idx < len(nums)-1; idx++ {
		bgn, end := 0, len(nums)-1

		if idx > 1 && nums[idx] == nums[idx-1] {
			bgn = idx - 1
		}

		for bgn < idx && idx < end {
			if bgn > 0 && nums[bgn] == nums[bgn-1] {
				bgn++
				continue
			}
			if end < len(nums)-1 && nums[end] == nums[end+1] {
				end--
				continue
			}

			add := nums[bgn] + nums[idx] + nums[end]
			if add == target {
				return target
			}

			// faster than if/else diagram
			if r := math.Abs(float64(add - target)); r < float64(resi) {
				resi = int(r)
				rest = add
			}
			if add > target {
				end--
				continue
			}
			if add < target {
				bgn++
				continue
			}
		}
	}
	return rest
}
