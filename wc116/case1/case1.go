package main

func repeatedNTimes(A []int) int {
	var hash = map[int]int{}
	for _, v := range A {
		hash[v]++
	}
	var L = len(A)
	for k, v := range hash {
		if v == L/2 {
			return k
		}
	}
	return -1
}

func main() {
}
