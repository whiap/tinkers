package main

import "sort"

/* https://leetcode.com/problems/two-sum/description/
**
** Given an array of integers nums and an integer target,
** return indices of the two numbers such that they add up to target.
** You may assume that each input would have exactly one solution, and you may not use the same element twice.
** You can return the answer in any order.
 */

func twoSum(nums []int, target int) []int {
	/** O(N^2), NOT O(N)
	for i := range nums {
		if i == 0 {
			continue
		}
		for j := range nums {
			if j >= i {
				break
			}
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	*/
	m := make(map[int]int)
	for i, n := range nums {
		j, ok := m[target-n]
		if ok {
			return []int{i, j}
		}
		m[n] = i
	}
	return []int{}
}

// if return value NOT indices
// maybe we can try following methods

// double pointer version 1
func twoSum1(nums []int, target int) []int {
	sort.Ints(nums)
	lo, hi := 0, len(nums)-1
	for lo < hi {
		sum := nums[lo] + nums[hi]
		if sum < target {
			lo++
		} else if sum > target {
			hi--
		} else {
			return []int{lo, hi}
		}
	}
	return []int{}
}

// double pointer version 2: duplicated elements removed
// O(N*logN) + O(N)
func twoSum2(nums []int, target int) [][]int {
	sort.Ints(nums)
	lo, hi, res := 0, len(nums)-1, make([][]int, 0)
	for lo < hi {
		left, right := nums[lo], nums[hi]
		sum := left + right
		if sum < target {
			for lo < hi && nums[lo] == left {
				lo++
			}
		} else if sum > target {
			for lo < hi && nums[hi] == right {
				hi--
			}
		} else {
			res = append(res, []int{left, right})
			for lo < hi && nums[lo] == left {
				lo++
			}
			for lo < hi && nums[hi] == right {
				hi--
			}
		}
	}
	return res
}
