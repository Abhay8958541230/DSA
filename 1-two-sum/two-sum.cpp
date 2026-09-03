class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        int i=0;
        vector<pair<int,int>> numswithindices;
        for(i=0; i<n; i++){
            numswithindices.push_back({nums[i],i});
        }
        sort(numswithindices.begin(), numswithindices.end());

        int left=0;


        int right=n-1;
        while(left<right){
            int sum = numswithindices[left].first + numswithindices[right].first;
        
        if(sum==target){
            return {numswithindices[left].second, numswithindices[right].second};
        }
        else if (sum < target){
            left++;
        }
        else{
            right--;
        }


        }
        return {-1,-1};

    }
};