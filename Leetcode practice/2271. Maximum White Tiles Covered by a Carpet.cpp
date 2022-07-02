#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int carpetLen) {
        vector<pair<long long,long long>> tiles;
        
        for(auto &vec:t) {
            tiles.push_back({vec[0], vec[1]});
        }
        sort(tiles.begin(), tiles.end());
        
        
        vector< long long> rIndex;
        
        for(int i = 0;i<tiles.size();i++) {
            pair<long long,long long> &ti = tiles[i];
            rIndex.push_back(ti.second);
        }
        sort(rIndex.begin(), rIndex.end());
       // printf("tiles: ");
       // for(auto t:tiles) printf(" | %d %d", t.first, t.second);
       // printf("\n");
       // printf("rIndex: - ");
       // for(auto ri:rIndex) printf(" | %d %d", ri.first, ri.second);
       // printf("\n"); 
        
        // 18 - 10 + 1
        
        vector<long long> sum = vector<long long> (tiles.size()+1, 0);
        
     //   sum[0] = tiles[0].second - tiles[0].first + 1;
        
        for(int i = 0;i<tiles.size();i++) {
            pair<long long ,long long> &ti = tiles[i];
            sum[i+1] = sum[i] + (ti.second - ti.first + 1);
        }
        
        // printf("cumulative: -- ");
       // for(int i = 0;i<tiles.size();i++) printf(" -- i: %d, sum[i]: %d", i, sum[i]);
       // printf("\n");
        long long ret = 0; 
        for(int i = 0;i<tiles.size();i++) {
            long long range = tiles[i].first + carpetLen - 1;
            auto it = upper_bound(rIndex.begin(), rIndex.end(), range);
           // if(it == rIndex.end()) {
            //    it --;
            //}
           // if(it != rIndex.begin() && it->first > range) {
           //     it--;
           // }
            int l = it - rIndex.begin();
          //  printf("i: %d, range:{%d, 0}, l: %d, sum[l]: %d \n", i, range, l, sum[l]);
            
            long long tmp = 0;
            
            if(l < tiles.size() && range >= tiles[l].first) tmp = range - tiles[l].first + 1;
            
            long long tmp2 = 0;
            
                
            tmp2 = sum[l] - sum[i];
            
            ret = max(ret, tmp2 + tmp);
        }
        
        return ret;
    }
};

int main(int argc, char const *argv[])
{
   vector<vector<int>> tiles = {{1,5},{10,11},{12,18},{20,25},{30,32}};
int carpetLen = 10;
    Solution sol;

    cout << sol.maximumWhiteTiles(tiles, carpetLen)<<endl;
    
    return 0;
}
