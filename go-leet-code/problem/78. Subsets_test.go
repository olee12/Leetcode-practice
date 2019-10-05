package problem

import (
	"reflect"
	"testing"
)

func Test_subsets(t *testing.T) {

	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want [][]int
	}{
		{
			name: "test0",
			args: args{nums: []int{1, 2}},
			want: [][]int{[]int{}, []int{2}, []int{1}, []int{1, 2}},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := subsets(tt.args.nums); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("subsets() = %v, want %v", got, tt.want)
			}
		})
	}
}
