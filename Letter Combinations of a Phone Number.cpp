class Solution
{
public:
    void solve(int i, vector<string> &ans, string &temp, string &digits, vector<string> &map)
    {
        // Base case
        if (temp.length() == digits.length())
        {
            ans.push_back(temp);
            return;
        }

        // Digits are in char form, so converting into int
        string group = map[digits[i] - '0'];

        // Logic of for loop on each digit
        for (char j : group)
        {
            temp.push_back(j);
            solve(i + 1, ans, temp, digits, map);
            // Backtrack
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        int i = 0;
        vector<string> ans;
        string temp;

        // Fix the variable name here
        vector<string> map = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if (digits.length() == 0)
        {
            return ans;
        }

        solve(i, ans, temp, digits, map);

        return ans;
    }
};
