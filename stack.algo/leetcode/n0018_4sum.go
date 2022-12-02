package main

import "sort"

// https://leetcode.com/problems/4sum/
func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	return nSum(nums, 4, 0, target)
}

// nums is sorted
func nSum(nums []int, n, start, target int) [][]int {
	res, siz := make([][]int, 0), len(nums)

	if n < 2 || n > siz {
		return res
	}

	if n == 2 {
		// recursive basis
		bgn, end := start, siz-1
		for bgn < end {
			left, right := nums[bgn], nums[end]

			// try to test => action
			if sum := left + right; sum < target {
				for bgn < end && nums[bgn] == left {
					bgn++
				}
			} else if sum > target {
				for bgn < end && nums[end] == right {
					end--
				}
			} else {
				res = append(res, []int{left, right})
				for bgn < end && nums[bgn] == left {
					bgn++
				}
				for bgn < end && nums[end] == right {
					end--
				}
			}
		}
	} else {
		// recursive expression
		for idx := start; idx < siz-1; idx++ {
			sub := nSum(nums, n-1, idx+1, target-nums[idx])
			for _, arr := range sub {
				arr = append(arr, nums[idx])
				res = append(res, arr)
			}
			for idx < siz-1 && nums[idx] == nums[idx+1] {
				idx++
			}
		}
	}
	return res
}
