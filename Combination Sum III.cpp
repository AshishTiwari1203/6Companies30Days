class Solution
{
public:
    void solve(int ind, int sum, int len, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (temp.size() == len && sum == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (temp.size() == len)
        {
            return;
        }

        // Logic of take and not take
        for (int i = ind; i <= 9; i++)
        {
            // Take
            temp.push_back(i);
            solve(i + 1, sum - i, len, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, n, k, temp, ans);
        return ans;
    }
};