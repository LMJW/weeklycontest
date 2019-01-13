package main

// 905 sort the array by parity
func sortArrayByParity(A []int) []int {
	var odd, even []int
	for i, v := A{
		if v%2==0{
			even = append(even, v)
		}else{
			odd = append(odd, v)
		}
	}
	even = append(even, odd...)
	return even
}

func main() {}
