package com.leetcode.practice.storage;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class OptimalAccountBalancing465 {

    static class Solution {
        Solution(){

        }
        private int MAX_STEP = Integer.MAX_VALUE;
        public int minTransfers(int[][] transactions) {
            Map<Integer,Integer> person = new HashMap<>();
            for(int[] tuple:transactions){
                person.put(tuple[0], person.getOrDefault(tuple[0],0) - tuple[2]);
                person.put(tuple[1], person.getOrDefault(tuple[1],0) + tuple[2]);
            }

            List<Integer> send = new ArrayList<>();
            List<Integer> receive = new ArrayList<>();

            for(int val:person.values()){
                if(val > 0) send.add(val);
                else if(val < 0) receive.add( -val);
                //System.out.println("val : "+ val);
            }

            this.MAX_STEP = transactions.length;

            return rec(send,receive,0);
        }

        public int rec(List<Integer> sendList,List<Integer> receiveList,int steps){
            //System.out.println(sendList.size()+" "+receiveList.size() + " " + steps+" "+this.MAX_STEP);
            if(steps >= this.MAX_STEP){
                return this.MAX_STEP;
            }
            if(sendList.size()==0) return 0;

            int sendSize = sendList.size();
            int receiveSize = receiveList.size();

            if((steps + sendSize >= this.MAX_STEP) || (steps + receiveSize >= this.MAX_STEP)){
                return this.MAX_STEP;
            }
            int ret = this.MAX_STEP;
            for(int i = 0;i<sendSize;i++){
                int sendVal = sendList.remove(i);
                for(int j = 0;j<receiveSize;j++){
                    int receiveVal = receiveList.remove(j);

                    if(sendVal > receiveVal){
                        sendList.add(sendVal - receiveVal);
                        ret = Math.min(ret, rec(sendList,receiveList,steps+1) + 1);
                        sendList.remove(sendList.size() - 1);
                    }else if(sendVal < receiveVal){
                        receiveList.add(receiveVal - sendVal);
                        ret = Math.min(ret, rec(sendList,receiveList,steps+1) + 1);
                        receiveList.remove(receiveList.size() - 1);
                    }
                    else ret = Math.min(ret, rec(sendList,receiveList,steps+1) + 1);
                    receiveList.add(j,receiveVal);
                }
                sendList.add(i,sendVal);
            }
            return ret;
        }

    }
    public static void main(String[] args) {
        //int[][] arr = {{0,1,10},{2,0,5}};
        //int[][] arr = {{0,1,10}, {1,0,1}, {1,2,5}, {2,0,5}};
        int[][] arr = {{1,8,1},{1,13,21},{2,8,10},{3,9,20},{4,10,61},{5,11,61},{6,12,59},{7,13,60}};
        Solution solution = new Solution();
        System.out.println(solution.minTransfers(arr));
    }
}
