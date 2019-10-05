package problem

import "testing"

func Test_removeDuplicates(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "test1",
			args: args{[]int{1, 2, 2, 3, 3, 3, 4, 5, 5, 6, 6, 6, 6, 6}},
			want: 10,
		},
		{
			name: "test2",
			args: args{[]int{1, 1, 1, 1, 2, 3, 4, 5, 6}},
			want: 7,
		},
		{
			name: "test3",
			args: args{[]int{}},
			want: 0,
		},
		{
			name: "test4",
			args: args{[]int{1, 2, 3, 4, 5}},
			want: 5,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := removeDuplicates(tt.args.nums); got != tt.want {
				t.Errorf("removeDuplicates() = %v, want %v", got, tt.want)
			}
		})
	}
}
