package com.leetcode.practice.storage;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSum {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> storage = new ArrayList<>();

        List<Integer> state = new ArrayList<>();

        rec(1, k, n, state, storage);

        return storage;
    }

    private void rec(int pos, int k, int n, List<Integer> state, List<List<Integer>> storage) {
        if (n == 0 && k == 0) {
            storage.add(new ArrayList<>(state));
            return;
        }
        if (n < 0 || k < 0) return;
        for (int i = pos; i <= 9; i++) {
            state.add(i);
            rec(i + 1, k - 1, n - i, state, storage);
            state.remove(state.size()-1);
        }
    }
}
