package main

import (
	"reflect"
	"testing"
)

func Test_combinationSum2(t *testing.T) {
	type args struct {
		candidates []int
		target     int
	}
	tests := []struct {
		name string
		args args
		want [][]int
	}{
		{
			name: "test1",
			args: args{
				candidates: []int{1, 2, 3, 4},
				target:     6,
			},
			want: [][]int{{1, 2, 3}, {2, 4}},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := combinationSum2(tt.args.candidates, tt.args.target); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("combinationSum2() = %v, want %v", got, tt.want)
			}
		})
	}
}

func BenchmarkCombinationSum2(b *testing.B) {
	candidates := []int{1, 2, 2,3, 3, 4}
	target := 6
	for i := 0; i < b.N; i++ {
		_ = combinationSum2(candidates,target)
	}
}
