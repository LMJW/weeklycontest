package main

func sortArrayByParityII(A []int) []int {
	var odd []int
	var even []int
	for i, v := range A {
		switch i % 2 {
		case 0:
			if v%2 == 1 {
				even = append(even, i)
			}
		case 1:
			if v%2 == 0 {
				odd = append(odd, i)
			}
		}
	}
	for i := 0; i < len(odd); i++ {
		A[odd[i]], A[even[i]] = A[even[i]], A[odd[i]]
	}
	return A
}

func main() {}
