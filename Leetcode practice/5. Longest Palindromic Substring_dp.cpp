#include <iostream>
using namespace std;

int dp[1001][1001][2];
const int negInf = -2000;
class Solution {
public:
    string str;
    string longestPalindrome(string s) {
        for(int i = 0;i<s.size();i++) {
            for(int j = 0;j<s.size();j++) {
                for(int k = 0;k<2;k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        str = s;
        // clock_t tStart = clock();
        int it = rec(0, s.size() - 1, 0);
        // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

        // printf("len: %d\n", it);
        return path(0, s.size() -1 , false);
    }
    int rec(int i, int j, bool skip) {
        if(i >=j) {
           return i == j;
        } 
        int &ret = dp[i][j][skip];
        if(ret != -1) return ret; 
        
        if(skip && str[i] != str[j]) {
            ret = negInf;
            return ret;
        }
        
        if(str[i] == str[j]) {
            int a = rec(i + 1, j - 1, true);
            if (a != negInf)
                ret = a + 2;
            else ret = negInf;
        }

        if(skip) return ret;
        ret = max(ret, rec(i+1, j, false));
        ret = max(ret, rec(i, j-1, false)); 
        return ret;
    }

    string path(int i, int j, int skip) {
        if(i >=j) {
            if (i > j)
                 return ""; 
            return str.substr(i,1);
        } 
        int ret = rec(i, j, skip);
        if (ret == negInf) return ""; 
        if(skip && str[i] != str[j]) {
            return "";
        }
        
        if(str[i] == str[j]) {
            int this_way = rec(i + 1, j-1, true);
            if (ret == this_way + 2) {
                string x = path(i+1, j-1, true);
                return str.substr(i,1) + x + str.substr(i, 1);
            }
        }
        if(skip) return "";
        if (ret == rec(i+1, j, false)) {
            return path(i+1, j, false);
        }
        else {
            return path(i, j-1, false);
        }
    }

    // pair<int,string> rec(int i, int j, bool skip) {
    //     if(i >=j) {
    //        if (i > j)
    //            return {0, ""}; 
    //        return {1, str.substr(i, 1)};
    //     } 
       
    //     pair<int,string> &ret = dp[i][j][skip];
    //     if(ret.first != -1) return ret; 
        
    //     if(skip && str[i] != str[j]) {
    //         ret = {negInf, ""};
    //         return ret;
    //     }
        
    //     if(str[i] == str[j]) {
    //         pair<int,string> a = rec(i + 1, j - 1, true);
    //         if (a.first != negInf)
    //             ret = {a.first + 2, str.substr(i, 1) + a.second + str.substr(i, 1)};
    //         else ret = {negInf, ""};
    //     }
    //     if(skip) return ret;
    //     pair<int,string> tmp;
    //     auto ret1 = rec(i+1, j, false);
    //     auto ret2 = rec(i, j-1, false); 
    //     if(ret1.first >= ret2.first) {
    //         tmp = ret1;
    //     }else {
    //         tmp = ret2;
    //     }
    //     if(tmp.first>ret.first) ret = tmp;
    //     return ret;
    // }
};

int main(int argc, char const *argv[])
{
    string cas = "lphbehiapswjudnbcossedgioawodnwdruaaxhbkwrxyzaxygmnjgwysafuqbmtzwdkihbwkrjefrsgjbrycembzzlwhxneiijgzidhngbmxwkhphoctpilgooitqbpjxhwrekiqupmlcvawaiposqttsdgzcsjqrmlgyvkkipfigttahljdhtksrozehkzgshekeaxezrswvtinyouomqybqsrtegwwqhqivgnyehpzrhgzckpnnpvajqevbzeksvbezoqygjtdouecnhpjibmsgmcqcgxwzlzztdneahixxhwwuehfsiqghgeunpxgvavqbqrelnvhnnyqnjqfysfltclzeoaletjfzskzvcdwhlbmwbdkxnyqappjzwlowslwcbbmcxoiqkjaqqwvkybimebapkorhfdzntodhpbhgmsspgkbetmgkqlolsltpulgsmyapgjeswazvhxedqsypejwuzlvegtusjcsoenrcmypexkjxyduohlvkhwbrtzjnarusbouwamazzejhnetfqbidalfomecehfmzqkhndpkxinzkpxvhwargbwvaeqbzdhxzmmeeozxxtzpylohvdwoqocvutcelgdsnmubyeeeufdaoznxpvdiwnkjliqtgcmvhilndcdelpnilszzerdcuokyhcxjuedjielvngarsgxkemvhlzuprywlypxeezaxoqfges";

    Solution sol;
    cout << sol.longestPalindrome(cas)<<endl;
    return 0;
}
