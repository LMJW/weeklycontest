package main

func diStringMatch(S string) []int {
	var n = len(S) + 1
	var path = []int{0}
	var left = []int{}
	for i := 1; i < n; i++ {
		left = append(left, i)
	}

	if n == 1 {
		return []int{}
	}

	var found bool
	var dfs func(int, []int, []int) []int

	dfs = func(ll int, path []int, left []int) []int {
		if len(left) == 0 {

		}
		for !found {
			var letter = S[ll]
			switch letter {
			case 'I':
				for i, v := range left {
					if v > path[len(path)-1] {
						dfs(ll+1, append(path, v), append(left[:i], left[i+1:]...))
					}
				}
			default:
				for i, v := range left {
					if v < path[len(path)-1] {
						dfs(ll+1, append(path, v), append(left[:i], left[i+1:]...))
					}
				}
			}

		}
		return path
	}
}

func main() {}
