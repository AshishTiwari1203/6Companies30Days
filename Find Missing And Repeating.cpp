//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // code here
        sort(arr.begin(), arr.end());
        int rep = 0;
        int mis = 0;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] == arr[i])
            {
                rep = arr[i];
                break;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] > 1)
            {
                mis = arr[i - 1] + 1;
                break;
            }
        }
        // Edge cases
        if (mis == 0)
        {
            // First element is missing
            if (arr[0] != 1)
            {
                mis = 1;
            }
            // Last element is missing
            else
            {
                mis = n;
            }
        }

        return {rep, mis};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends