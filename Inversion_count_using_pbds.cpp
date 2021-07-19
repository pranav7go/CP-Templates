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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void pg()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FIO;
}

vector<int> smaller_left(vector<int> nums) {


    //No. of smaller elements on the left
    int n = nums.size();
    pbds s;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {

        //Count of strictly lesser number on the left
        ans[i] = s.order_of_key(make_pair(nums[i], 0));


        // Count of lesser or equal numbers on the left
        //     ans[i] = s.order_of_key(make_pair(nums[i], i));

        s.insert(make_pair(nums[i], i));
    }
    return ans;

}

vector<int> inversion_count(vector<int> nums) {

    //No. of smaller elements on the right

    int n = nums.size();
    pbds s;
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = s.order_of_key(make_pair(nums[i], i));

        //Greater than or equal to
        //ans[i] = s.order_of_key(make_pair(nums[i], n));
        s.insert(make_pair(nums[i], i));
    }
    return ans;

}

vector<int> inversion_count_alt(vector<int> nums) {

    //No. of smaller elements on the right

    int n = nums.size();
    reverse(nums.begin(), nums.end());
    pbds s;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {

        // Count of strictly smaller  numbers on the right
        ans[i] = s.order_of_key(make_pair(nums[i], 0));


        // Count of smaller or equal numbers on the right
        //     ans[i] = s.order_of_key(make_pair(nums[i], i));

        s.insert(make_pair(nums[i], i));
    }

    reverse(ans.begin(), ans.end());
    return ans;

}

int32_t main()
{
    pg();


    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> v = inversion_count_alt(arr);
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;


    return 0;
}