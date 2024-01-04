class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        // First we will focus on trimming
        vector<int> ans;
        int temp;

        int len = nums[0].length();
        int n = nums.size();
        int r = queries.size();
        int c = queries[0].size();

        for (int i = 0; i < r; i++)
        {
            priority_queue<pair<string, int>> pq;
            for (int j = 0; j < n; j++)
            {
                int trim = queries[i][1];
                int st = len - trim;
                string sub = nums[j].substr(st, trim);
                // Kth smallest
                int k = queries[i][0];

                pq.push({sub, j});
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
            int val = pq.top().second;
            ans.push_back(val);
        }

        return ans;
    }
};