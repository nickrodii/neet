class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,
        decltype([](const pair<int,int>& pairA, const pair<int,int>& pairB) {
            return pairA.second < pairB.second;})> pq;

        for (const auto& iter : mp) {
            pq.push({iter.first, iter.second});
        }

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
