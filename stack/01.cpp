#include<iostream>
#include<map>
using namespace std;
typedef long long int lli;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        lli a[n];

        map <lli, lli> mp;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        lli ans =0;
        for(auto x : mp)
        {
            if(x.second  >1)
            {
                lli t = x.second;
                ans+= (t*(t-1))/2;
            }
        }
        cout<<ans<<endl;

    }
}
