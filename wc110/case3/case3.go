package main

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}

func minAreaRect(points [][]int) int {
	var xmap = map[int]map[int]bool{}
	// var ymap = map[int]map[int]bool{}

	var xp []int
	// var yp []int
	for _, v := range points {
		// store x->y
		if xmap[v[0]] == nil {
			xp = append(xp, v[0])
			xmap[v[0]] = map[int]bool{v[1]: true}
		} else {
			xmap[v[0]][v[1]] = true
		}
		// // store y->x
		// if ymap[v[1]] == nil {
		// 	yp = append(yp, v[1])
		// 	ymap[v[1]] = map[int]bool{v[0]: true}
		// } else {
		// 	ymap[v[1]][v[0]] = true
		// }
	}
	var area = 1 << 62
	var l = len(points)
	for i := 0; i < l; i++ {
		for j := i + 1; j < l; j++ {
			x0, y0 := points[i][0], points[i][1]
			x1, y1 := points[j][0], points[j][1]
			if x0 != x1 && y0 != y1 {
				if xmap[x0][y1] && xmap[x1][y0] {
					t := abs((x1 - x0) * (y1 - y0))
					if area > t {
						area = t
					}
				}
			}
		}
	}
	if area == 1<<62 {
		return 0
	}
	return area
}

func main() {

}
