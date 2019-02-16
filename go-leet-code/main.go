package main

import "fmt"

func main() {
	// wordlist := []string{"KiTe", "kite", "hare", "Hare"}
	// queries := []string{"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"}
	// output := []string{"kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "", "KiTe"}

	nums := []int{1, 1, 1, 1, 1}

	fmt.Println(findTargetSumWays(nums, 3))
}
