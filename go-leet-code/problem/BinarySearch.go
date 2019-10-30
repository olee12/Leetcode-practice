package problem

// BinarySearch ...
func BinarySearch(array []int, target int) int {
	low := 0
	high := len(array) - 1
	mid := 0
	for low <= high {
		mid = (low + high) / 2
		if array[mid] > target {
			high = mid - 1
		} else if array[mid] < target {
			low = mid + 1
		} else {
			return mid
		}
	}
	return -1
}

// UpperBound ...
func UpperBound(array []int, target int) int {
	low, high, mid := 0, len(array)-1, 0

	for low <= high {
		mid = (low + high) / 2
		if array[mid] > target {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return low
}

// LowerBound ...
func LowerBound(array []int, target int) int {
	low, high, mid := 0, len(array)-1, 0
	for low <= high {
		mid = (low + high) / 2
		if array[mid] >= target {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return low
}
