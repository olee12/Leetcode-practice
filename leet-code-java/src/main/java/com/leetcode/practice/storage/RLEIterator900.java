package com.leetcode.practice.storage;

public class RLEIterator900 {
    static class RLEIterator {
        private int index;
        private int[] input;

        public RLEIterator(int[] A) {
            this.input = A;
            this.index = 0;
        }

        public int next(int n) {
            return nextSmart(n);
            // if (index >= input.length) {
            //     return -1;
            // }

            // long tmp = 0;
            // while (index < input.length && tmp < n) {
            //     tmp += input[index];
            //     index += 2;
            // }
            // index -= 2;
            // if (index > input.length || tmp < n) {
            //     index = input.length;
            //     return -1;
            // }
            // input[index] = (int) (tmp - n);
            // return input[index + 1];
        }

        public int nextSmart(int n) {
            while (index < input.length && n > input[index]) {
                n = n - input[index];
                index += 2;
            }
            if (index >= input.length)
                return -1;
            input[index] = input[index] - n;
            return input[index + 1];
        }
    }

    public static void main(String[] args) {
        int[] input = { 0, 100, 0, 50, 3, 8, 0, 9, 2, 5 };
        RLEIterator iterator = new RLEIterator(input);
        System.out.println(iterator.next(2));
        System.out.println(iterator.next(1));
        System.out.println(iterator.next(1));
        System.out.println(iterator.next(2));
    }
}
