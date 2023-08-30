#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n * m);
        for (int i = 0; i < n * m; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        ll mini1 = a[0], mini2 = a[1];
        ll maxi1 = a[m * n - 1], maxi2 = a[m * n - 2];

        if (m < n)
            swap(n, m);

        ll res2 = (m - 1) * n * (maxi1 - mini1);
        res2 += ((n - 1) * (maxi2 - mini1));

        ll res1 = (m - 1) * n * (maxi1 - mini1);
        res1 += ((n - 1) * (maxi1 - mini2));

        cout << max(res1, res2) << '\n';
    }

    return 0;
}