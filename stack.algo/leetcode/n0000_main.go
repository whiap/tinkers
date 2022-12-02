package main

import "fmt"

func main() {
	fmt.Println("-- 0001. 2Sum --")
	// Expected: [0, 1]
	fmt.Println(twoSum([]int{2, 7, 11, 15}, 9))
	// Expected: [1, 2]
	fmt.Println(twoSum([]int{3, 2, 4}, 6))
	// Expected: [0, 1]
	fmt.Println(twoSum([]int{3, 3}, 6))

	fmt.Println("-- 0015. 3Sum --")
	// Expected: [[-1,-1,2],[-1,0,1]]
	fmt.Println(threeSum([]int{-1, 0, 1, 2, -1, -4}))
	// Expected: []
	fmt.Println(threeSum([]int{0, 1, 1}))
	// Expected: [[0,0,0]]
	fmt.Println(threeSum([]int{0, 0, 0}))

	fmt.Println("-- 0016. 3Sum Closest --")
	// Expected: 2
	fmt.Println(threeSumClosest([]int{-1, 2, 1, -4}, 1))
	// Expected: 0
	fmt.Println(threeSumClosest([]int{0, 0, 0}, 1))

	fmt.Println("-- 0018. 4Sum --")
	// Expected: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
	fmt.Println(fourSum([]int{1, 0, -1, 0, -2, 2}, 0))
	// Expected: [[2,2,2,2]]
	fmt.Println(fourSum([]int{2, 2, 2, 2}, 8))

	fmt.Println("-- 0887. Super Egg Drop --")
	superEggDrop(3, 4)

}
