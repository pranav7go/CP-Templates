/*    ___           ___
     /\  \         /\  \
    /::\  \       /::\  \
   /:/\:\  \     /:/\:\  \
  /::\~\:\  \   /:/  \:\  \
 /:/\:\ \:\__\ /:/__/_\:\__\
 \/__\:\/:/  / \:\  /\ \/__/
      \::/  /   \:\ \:\__\
       \/__/     \:\/:/  /
                  \::/  /
                   \/__/
*/


#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)          substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)           cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void pg()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FIO;
}


int dp[21][200000];
int arr[21];

void print(int n, int k)
{
    int num = n;
    int binaryNum[12] = {0};


    int i = 0;
    while (n > 0) {


        binaryNum[i] = n % 3;
        n = n / 3;
        i++;
    }

    for (int i = k - 1; i >= 0 ; i--) {
        cout << binaryNum[i];
    }

    cout << endl;


}



int decToBinary(int n, int p)
{
    int num = n;
    int binaryNum[12] = {0};


    int i = 0;
    while (n > 0) {


        binaryNum[i] = n % 3;
        n = n / 3;
        i++;
    }


    if (binaryNum[p] == 0) {

        return -1;
    }
    else {

        return num - pow(3, p);
    }
}


int solve(int i, int mask, int &n, int k) {


    // cout << i << " " << mask << " ";
    // print(mask, k);

    if (i == n) return 0;

    if (dp[i][mask] != -1) return dp[i][mask];

    int answer = INT_MIN;

    for (int j = 0; j < k; j++) {

        if (decToBinary(mask, j) != -1) {


            int temp = (arr[i] & (j + 1)) ;
            int p = solve(i + 1, decToBinary(mask, j), n, k);
            // cout << i << " " << arr[i] << " " << " " << j + 1 << " " << p << endl;
            temp += p;
            //cout << (arr[i] & (j + 1)) << " " << temp << endl ;
            answer = max(answer, temp);

        }

    }

    return dp[i][mask] = answer;

}

int32_t main()
{
    pg();
    w(t) {

        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 200000; j++) {
                dp[i][j] = -1;
            }
        }

        int n, k;
        cin >> n >> k;
        //int arr[n];
        for (int i = 0; i < n ; i++) cin >> arr[i];
        int mask = 0;
        int p = 1;
        for (int i = 0; i < k; i++) {
            mask += 2 * pow(3, i);
        }

        //cout << mask << endl;
        int num = solve(0, mask, n, k);

        int ans = INT_MIN;


        for (int j = 0; j < 200000; j++) {
            ans = max(ans, dp[0][j]);
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < 100; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cout << ans << endl;

    }
    return 0;
}

