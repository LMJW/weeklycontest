package main

import "fmt"

type node struct {
	value string
	time  int
}

type TimeMap struct {
	hash map[string][]node
}

/** Initialize your data structure here. */
func Constructor() TimeMap {
	return TimeMap{hash: make(map[string][]node)}
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
	if _, ok := this.hash[key]; !ok {
		this.hash[key] = []node{node{value: value, time: timestamp}}
	} else {
		this.hash[key] = append(this.hash[key], node{value: value, time: timestamp})
	}
}

func binsearch(arr []node, time int) int {
	var i, j = 0, len(arr) - 1
	var m int

	for i <= j {
		m = (i + j) / 2

		if arr[m].time == time {
			return m
		} else if arr[m].time > time {
			j = m - 1
		} else if arr[m].time < time {
			i = m + 1
		}
	}
	return m
}

func (this *TimeMap) Get(key string, timestamp int) string {
	if ele, ok := this.hash[key]; !ok {
		return ""
	} else {
		var n = binsearch(ele, timestamp)
		for n >= 0 {
			if ele[n].time > timestamp {
				n--
			} else {
				return ele[n].value
			}
		}
		return ""
	}
}

// func bin(arr []int, a int) int {
// 	var i, j = 0, len(arr) - 1
// 	var m int

// 	for i <= j {
// 		m = (i + j) / 2
// 		if arr[m] == a {
// 			return arr[m]
// 		} else if arr[m] < a {
// 			i = m + 1
// 		} else if arr[m] > a {
// 			j = m - 1
// 		}
// 	}
// 	return arr[m]
// }

func main() {
	fmt.Println(bin([]int{0}, 0))
	fmt.Println(bin([]int{0, 1}, 0))
	fmt.Println(bin([]int{0, 1, 2}, 3))
	fmt.Println(bin([]int{0, 1, 2, 3, 4}, 2))
	fmt.Println(bin([]int{0, 1, 2, 3, 4}, 6))
	fmt.Println(bin([]int{0, 1, 2, 3, 4}, -5))
}
