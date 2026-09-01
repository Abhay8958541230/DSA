class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr =0;
        int i =0;
        for(i=0; i<nums.size(); i++){
        xorr = xorr^nums[i];
        }
        return xorr;
    }       
};