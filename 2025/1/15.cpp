class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0, ans = num1;
        int oneCnt = __builtin_popcount(num1), goalCnt = __builtin_popcount(num2);
        cnt = 0;
        while (oneCnt != goalCnt) {
            // remove 1's
            if ((ans >> cnt)&1) {
                if (goalCnt < oneCnt){ 
                    ans ^= (1 << cnt);
                    oneCnt--;
                }
            }
            // add 1's
            else {
                if (goalCnt > oneCnt){ 
                    ans ^= (1 << cnt);
                    oneCnt++;
                }
            }
            cnt++;
        }
        return ans;
    }
};
