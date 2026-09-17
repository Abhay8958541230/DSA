class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;

        int prefixSum = 0;
        int count = 0;

        // Base case
        prefixSumCount[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int remove = prefixSum - k;

            if (prefixSumCount.find(remove) != prefixSumCount.end()) {
                count += prefixSumCount[remove];
            }

            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};