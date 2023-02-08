#include<bits/stdc++.h>
using namespace std;

const int N = 60;
const int M = 1001;
const int MOD = 100000007;

int dp[N][M];
int coin[N],limit[N];

int main()
{
    int t,tst = 0;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        for(int i = 1; i<=n; i++)
        {
            cin>>coin[i];
        }
        for(int j = 1; j<=n; j++)
        {
            cin>>limit[j];
        }
        // 1. handle base case
        dp[0][0] = 1;
        // 2.loop over the steps
        for(int i = 1; i<=n; i++)
        {
            for(int target = 0; target<=k; target++)
            {
                // 2.1 Calculate answer from smaller sub problem
                dp[i][target] = dp[i-1][target];
                for(int j = 1; j<=limit[i]; j++)
                {
                    if(target < j*coin[i]) break;
                    int ret = dp[i-1][target - j*coin[i]];
                    dp[i][target] = (dp[i][target] + ret)%MOD;
                }
            }
        }

        cout<<dp[n][k]<<endl;



    }

    return 0;
}

