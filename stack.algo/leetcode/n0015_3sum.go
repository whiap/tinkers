package main

import "sort"

// threeSum:  https://leetcode-cn.com/problems/3sum/
// -- sorting & double pointer; O(N^2)
func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	result, bgn, end, idx, add, length := make([][]int, 0), 0, 0, 0, 0, len(nums)
	for idx = 1; idx < length-1; idx++ {
		bgn, end = 0, length-1
		// for efficiency
		if idx > 1 && nums[idx] == nums[idx-1] {
			bgn = idx - 1
		}
		for bgn < idx && idx < end {
			if bgn > 0 && nums[bgn] == nums[bgn-1] {
				bgn++
				continue
			}
			if end < length-1 && nums[end] == nums[end+1] {
				end--
				continue
			}
			add = nums[bgn] + nums[idx] + nums[end]
			if add == 0 {
				result = append(result, []int{nums[bgn], nums[idx], nums[end]})
				bgn++
				end--
			} else if add > 0 {
				end--
			} else {
				bgn++
			}
		}
	}
	return result
}
