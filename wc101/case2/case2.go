package main

type StockSpanner struct {
	prices []int
	spans  []int
}

func Constructor() StockSpanner {
	return StockSpanner{prices: []int{}, spans: []int{}}
}

func (this *StockSpanner) Next(price int) int {
	var index, curspan int
	this.prices = append(this.prices, price)
	index = len(this.prices) - 1
	curspan = 1
	for j := index - 1; j >= 0; {
		if this.prices[index] < this.prices[j] {
			break
		} else {
			t := this.spans[j]
			curspan += t
			j -= t
		}
	}
	this.spans = append(this.spans, curspan)
	return curspan
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */

func main() {}
