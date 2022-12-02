package main

/* https://leetcode.com/problems/median-of-two-sorted-arrays/
**
** Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
** The overall run time complexity should be O(log (m+n)).
** You may assume nums1 and nums2 cannot be both empty.
 */

/**
func findMedianSortedArrays(nums1, nums2 []int) float64 {
	// thinking len(nums1) <= len(nums2)
	if len(nums1) > len(nums2) {
		return findMedianSortedArrays(nums2, nums1)
	}

	low, high, k, nums1mid, nums2mid := 0, len(nums1), (len(nums1)+len(nums2)+1)>>1, 0, 0
	for low <= high {

	}

}

*/
