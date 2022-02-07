package main

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
