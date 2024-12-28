#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n=nums.size();
        vector<int> ksum(n-k+1, 0);
        vector<int> L(n-3*k+1, -1);
        int maxksum=ksum[0]=accumulate(nums.begin(), nums.begin()+k, 0);
        L[0]=0;

        for(int i=1; i<n-k+1; i++){
            ksum[i]=ksum[i-1]-nums[i-1]+nums[i+k-1];
            if(i>n-3*k) continue;
            if(maxksum<ksum[i]){
                maxksum=ksum[i];
                L[i]=i;
            }else L[i]=L[i-1];
        }

        vector<int> R(n-3*k+1, -1);
        maxksum=ksum.back();
        R.back()=n-k;
        for(int i=n-k-1; i>=2*k; i--){
            if(maxksum<=ksum[i]){
                maxksum=ksum[i];
                R[i-2*k]=i;
            }else R[i-2*k]=R[i+1-2*k];
        }

        vector<int> ans(3, -1);
        int max3k=0;
        for(int i=0; i<=n-3*k; i++){
            int sum3k=ksum[L[i]]+ksum[i+k]+ksum[R[i]];
            if(sum3k>max3k){
                max3k=sum3k;
                ans={L[i], i+k, R[i]};
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}