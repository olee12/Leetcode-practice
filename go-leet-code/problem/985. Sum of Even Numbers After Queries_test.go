package problem

import (
	"reflect"
	"testing"
)

func Test_sumEvenAfterQueries(t *testing.T) {
	type args struct {
		A       []int
		queries [][]int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name:"test1",
			args:args{
				A : []int{-10,2,-4,5,-3,3},
				queries:[][]int{
					{-4,2},{9,0},{-8,1},{5,4},{1,4},{9,0},
				},
			},
			want:[]int{-16,-6,-14,-12,-14,-6},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := sumEvenAfterQueries(tt.args.A, tt.args.queries); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("sumEvenAfterQueries() = %v, want %v", got, tt.want)
			}
		})
	}
}
