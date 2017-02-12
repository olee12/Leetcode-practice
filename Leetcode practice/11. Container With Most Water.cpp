class Solution {
public:
    int maxArea(vector<int>& height) {
        int beg = 0, end = height.size()-1;
        int h = 0;
        int w = 0;
        while(beg < end){
            h = min(height[end],height[beg]);
            w = max(w,(end - beg ) * h);
            while(height[beg] <= h && beg < end ) beg++;
            while(height[end] <= h && end > beg) end--;
        }
        return w;
    }
};
