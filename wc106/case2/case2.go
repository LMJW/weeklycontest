package main

func minAddToMakeValid(S string) int {
	var stack []rune
	var idx int

	for _, v := range S {
		if v == '(' {
			stack = append(stack, v)
			idx++
		} else {
			if idx == 0 {
				stack = append(stack, v)
				idx++
			} else if stack[idx-1] == '(' {
				stack = stack[:idx-1]
				idx--
			} else {
				stack = append(stack, v)
				idx++
			}
		}
	}
	return idx
}

func main() {}
