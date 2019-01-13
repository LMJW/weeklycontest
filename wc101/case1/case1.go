package main

import (
	"fmt"
)

type RLEIterator struct {
	idx     []int
	actvals []int
	cur     int
	curidx  int
}

func Constructor(A []int) RLEIterator {
	var vals = []int{}
	var idx = []int{}
	var l = len(A)
	for i, v := range A {
		if i < l-1 && i%2 == 0 {
			if v > 0 {
				vals = append(vals, A[i+1])
				if i == 0 {
					idx = append(idx, v-1)
				} else {
					idx = append(idx, idx[len(idx)-1]+v)
				}
			}
		}
	}
	return RLEIterator{idx: idx, actvals: vals, cur: -1}
}

func (this *RLEIterator) Next(n int) int {
	this.cur += n
	for {
		if this.curidx >= len(this.idx) {
			return -1
		}
		if this.idx[this.curidx] < this.cur {
			this.curidx++
		} else {
			return this.actvals[this.curidx]
		}
	}

}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * obj := Constructor(A);
 * param_1 := obj.Next(n);
 */

func main() {
	obj := Constructor([]int{3, 8, 0, 9, 2, 5})
	fmt.Println(obj.Next(2))
	fmt.Println(obj.Next(1))
	fmt.Println(obj.Next(1))
	fmt.Println(obj.Next(2))

}
