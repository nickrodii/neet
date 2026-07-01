class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int delta = target - nums[i];
            if (mp.contains(delta)) return {mp[delta], i};

            mp[nums[i]] = i;
        }
        return {};
    }
};