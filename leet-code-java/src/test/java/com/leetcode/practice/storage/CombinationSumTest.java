package com.leetcode.practice.storage;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.*;

public class CombinationSumTest {
    @Test
    public void TestCombinationSum3() {
        CombinationSum combinationSum = new CombinationSum();

        int n = 9, k = 3;
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(Arrays.asList(1, 2, 6));
        expected.add(Arrays.asList(1, 3, 5));
        expected.add(Arrays.asList(2, 3, 4));
        System.out.println("expected: " + expected.toString());
        List<List<Integer>> ret = combinationSum.combinationSum3(k, n);
        System.out.println("ret: " + ret.toString());

        assertTrue(expected.size() == ret.size());
        expected.stream().forEach(exp -> {
            assertTrue(ret.contains(exp));
        });
    }

}