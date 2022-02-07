package main

func maxArea(height []int) int {
	/** try 1st, out of time limit
	  sum := 0
	  for left := range height {
	      if left >= len(height) -1 {
	          break
	      }
	      right := left + 1
	      for right < len(height) {
	          hl := height[left]
	          hr := height[right]
	          ha := hl
	          if hl > hr  {
	              ha = hr
	          }
	          if s := (right - left) * ha; s > sum {
	              sum = s
	          }
	          right++
	      }
	  }
	*/

	/** try 2nd, not correct
	  min := func(l, r int) int {
	      if l < r {
	          return l
	      }
	      return r
	  }

	  var sum, left, right int
	  hl, hr := height[left], height[right]
	  for pos, hgh := range height {
	      if pos == 0 {
	          continue
	      }
	      if pos != len(height) -1 {
	     if h := height[pos + 1];hgh - hl > 1 && h > hl {
	          left, hl = pos, hgh
	          right, hr = pos +1, h
	          sum = (right - left) * min(hl, hr)
	          continue
	      }
	      }
	      if s := (pos - left) * min(hl, hgh); s > sum {
	          right, hr = pos, hgh
	          sum = s
	      }
	  }
	*/

	/** try 3rd, O(N) / O(1) **/
	sum, bgn, end := 0, 0, len(height)-1
	for bgn < end {
		wth := end - bgn
		hgh := 0
		if height[bgn] < height[end] {
			hgh = height[bgn]
			bgn++
		} else {
			hgh = height[end]
			end--
		}
		if s := wth * hgh; s > sum {
			sum = s
		}
	}
	return sum
}
