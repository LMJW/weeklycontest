package main

func issorted(A []int) bool {
	var i int
	for i = 1; i < len(A); i++ {
		if A[i] < A[i-1] {
			return false
		}
	}
	return true
}

func findmaxidx(A []int) (int, int) {
	var max = A[0]
	var idx = 0
	for i := 1; i < len(A); i++ {
		if max < A[i] {
			idx = i
			max = A[i]
		}
	}
	return max, idx
}

func flipidx(A []int, d int) {
	for i := 0; i < d/2; i++ {
		var t = A[i]
		A[i] = A[d-i]
		A[d-i] = t
	}
}

func pancakeSort(A []int) []int {
	var ops []int
	for !issorted(A) {
		_, idx := findmaxidx(A)
		if idx == len(A)-1 {
			A = A[:idx]
		} else {
			ops = append(ops, idx+1)
			ops = append(ops, len(A))
		}
	}
	return ops
}

func main() {

}
