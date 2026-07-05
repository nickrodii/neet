class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,
        decltype([](const pair<int,int>& pairA, const pair<int,int>& pairB) {
            return pairA.second > pairB.second;})> pq;

        for (const auto& iter : mp) {
            if (pq.size() >= k) {
                if (pq.top().second < iter.second) {
                    pq.pop();
                    pq.push({iter.first, iter.second});
                }
            }
            else pq.push({iter.first, iter.second});
        }

// 1 2 8 9
// [8,9]
        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
