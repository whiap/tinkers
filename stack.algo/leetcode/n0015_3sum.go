package main

import "sort"

// threeSum:  https://leetcode-cn.com/problems/3sum/
// -- sorting & double pointer; O(N^2)
func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	result := make([][]int, 0)
	for idx := 1; idx < len(nums)-1; idx++ {
		bgn, end := 0, len(nums)-1

		// duplicates removed for efficiency, maybe especially for 3sum
		if idx > 1 && nums[idx] == nums[idx-1] {
			bgn = idx - 1
		}

		for bgn < idx && idx < end {
			// duplicates removed for efficiency
			if bgn > 0 && nums[bgn] == nums[bgn-1] {
				bgn++
				continue
			}

			// duplicates removed for efficiency
			if end < len(nums)-1 && nums[end] == nums[end+1] {
				end--
				continue
			}

			add := nums[bgn] + nums[idx] + nums[end]
			if add > 0 {
				end--
				continue
			} else if add < 0 {
				bgn++
				continue
			} else {
				result = append(result, []int{nums[bgn], nums[idx], nums[end]})
				bgn++
				end--
			}
		}
	}
	return result
}
