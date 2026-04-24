#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            sum %= p; 
        } 
        int ans = n+1;

        if(sum%p==0) return 0;

        for(int i=0; i<n;i++){
            int count = 0;
            long long temp = sum;
            for(int j=i; j<n; j++){
                temp -= (nums[j]%p);
                count++;
                if(temp%p == 0){
                    if(count<ans) ans = count;
                    break;
                }
            }
        }
        if(ans == n) return -1;
        return ans;
    }
};