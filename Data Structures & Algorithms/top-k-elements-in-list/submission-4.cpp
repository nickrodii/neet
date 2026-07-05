class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size()+1);

        for (int n : nums) {
            mp[n]++;
        }

        for (const auto& iter : mp) {
            freq[iter.second].push_back(iter.first);
        }

        vector<int> res;
        for (int i = freq.size()-1; i > 0; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
