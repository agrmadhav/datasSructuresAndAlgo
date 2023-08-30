#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t1 = 1, t_case = 1;
    cin >> t1;

    while (t1--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        set<int> st;

        int left = 0, right = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
                left++;
            else if (a[i] == -2)
                right++;
            else
                st.insert(a[i]);
        }

        vector<int> b;
        for (auto it : st)
            b.push_back(it);

        int ans = max(left, right);
        int sz = b.size();
        ans = min(m, ans + sz);

        auto it = lower_bound(b.begin(), b.end(), left);

        if (it != b.end())
        {
            int val = (*it);
            int rem = b.end() - it - 1;
            int tmp = left + 1;
            tmp += min(m - val, right + rem);

            ans = max(ans, tmp);
        }

        cout << ans << '\n';
    }
    return 0;
}
