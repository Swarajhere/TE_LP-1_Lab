#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &v, int currSum, int target, vector<int> &ans,
           vector<vector<int>> &final, int idx)
{
    // Base cases
    if (currSum == target)
    {
        final.push_back(ans);
        return;
    }
    if (currSum > target || idx >= n)
    {
        return;
    }

    // Include current element
    ans[idx] = 1;
    solve(n, v, currSum + v[idx], target, ans, final, idx + 1);

    // Exclude current element (backtrack)
    ans[idx] = 0;
    solve(n, v, currSum, target, ans, final, idx + 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int target;
    cin >> target;

    vector<int> ans(n, 0);
    vector<vector<int>> final;

    solve(n, v, 0, target, ans, final, 0);

    if (!final.empty())
    {
        cout << "Solutions found:\n";
        for (const auto &solution : final)
        {
            // Print the actual subset elements instead of just 0s and 1s
            cout << "Subset: ";
            for (int i = 0; i < n; i++)
            {
                if (solution[i])
                {
                    cout << v[i] << " ";
                }
            }
            cout << "\nBinary representation: ";
            for (int i : solution)
            {
                cout << i << " ";
            }
            cout << "\n\n";
        }
    }
    else
    {
        cout << "No solution exists for the given target sum." << endl;
    }

    return 0;
}
