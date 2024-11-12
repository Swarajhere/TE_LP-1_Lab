// ---------------------------------------------Simple 0_1 Knapsack Code (prints maximum possible profit ---------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, vector<int> &prof, vector<int> &weig, vector<vector<int>> &v)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= W; j++)
        {
            int inc = 0;
            if (j - weig[i] >= 0)
            {
                inc = v[i + 1][j - weig[i]] + prof[i];
            }
            int exc = v[i + 1][j];
            v[i][j] = max(inc, exc);
        }
    }
    return v[0][W];
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> profits(n), weights(n);
    for (int i = 0; i < n; i++)
        cin >> profits[i];
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    vector<vector<int>> v(n + 1, vector<int>(W + 1, 0));
    int res = knapsack(n, W, profits, weights, v);
    cout << res << endl;
    return 0;
}


// ------------------------------------- Below Code prints maximum profit as well as items that are selected ------------------------------------------------- //

/*
#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, vector<int> &prof, vector<int> &weig, vector<vector<int>> &v)
{
    // Build the knapsack table from bottom to top
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= W; j++)
        {
            int inc = 0;
            if (j - weig[i] >= 0)
            {
                inc = v[i + 1][j - weig[i]] + prof[i]; // Include item i
            }
            int exc = v[i + 1][j];   // Exclude item i
            v[i][j] = max(inc, exc); // Choose the maximum of including or excluding
        }
    }
    return v[0][W]; // Return the maximum profit
}

// Function to find and display the items selected in the knapsack
void findSelectedItems(int n, int W, vector<int> &prof, vector<int> &weig, vector<vector<int>> &v)
{
    int remainingWeight = W;
    vector<int> selectedItems;

    for (int i = 0; i < n; i++)
    {
        // Check if including the item gives the same profit as the current cell
        if (remainingWeight >= weig[i] && v[i][remainingWeight] == v[i + 1][remainingWeight - weig[i]] + prof[i])
        {
            selectedItems.push_back(i + 1); // Store item index (1-based)
            remainingWeight -= weig[i];     // Reduce the weight capacity by the weight of the selected item
        }
    }

    cout << "Selected Items (1-based index): ";
    for (int item : selectedItems)
    {
        cout << "I" << item << " ";
    }
    cout << endl;
}

int main()
{
    int n, W;
    cout << "Enter the number of items and maximum weight capacity: ";
    cin >> n >> W;
    vector<int> profits(n), weights(n);

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++)
        cin >> profits[i];

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    // Initialize the DP table with 0
    vector<vector<int>> v(n + 1, vector<int>(W + 1, 0));

    int res = knapsack(n, W, profits, weights, v);
    cout << "Maximum Profit: " << res << endl;

    // Find and display the selected items
    findSelectedItems(n, W, profits, weights, v);

    return 0;
}
*/
