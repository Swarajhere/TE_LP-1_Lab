#include <bits/stdc++.h>
using namespace std;

double maximumProf(int n, int W, vector<int> &prof, vector<int> &weig, vector<int> &selected)
{
    vector<pair<double, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        double ratio = (double)prof[i] / (double)weig[i];
        v[i] = {ratio, i};
    }
    sort(v.begin(), v.end(), greater<pair<double, int>>());

    double ans = 0.0;
    int cap = W;
    for (int i = 0; i < n && cap > 0; i++)
    {
        int idx = v[i].second;
        double currRatio = v[i].first;
        int currWt = min(weig[idx], cap);
        cap -= currWt;
        ans += (currRatio * currWt);
        if (currWt > 0)
            selected.push_back(idx + 1);
    }
    return ans;
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
    vector<int> selected;
    double result = maximumProf(n, W, profits, weights, selected);
    cout << "Maximum Profit: " << result << endl;
    cout << "Selected Items (1-based index): ";
    for (int &it : selected)
        cout << "I" << it << " ";
    return 0;
}
