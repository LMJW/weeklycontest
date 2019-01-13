package main

type RecentCounter struct {
	pingtime []int
}

func Constructor() RecentCounter {
	return RecentCounter{pingtime: []int{}}
}

func (this *RecentCounter) Ping(t int) int {
	this.pingtime = append(this.pingtime, t)
	var count int
	var lowb, total = t - 3000, len(this.pingtime)
	for i := range this.pingtime {
		if this.pingtime[i] < lowb {
			continue
		} else {
			count = i
			break
		}
	}
	return total - count
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */

func main() {}
