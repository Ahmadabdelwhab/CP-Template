#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define MOD ll(1e9+7)
#define OO LLONG_MAX
#define oo INT_MAX
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs"<< "\n";
//1d vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for(const T &i : v)
        os << i << ' ';
    return os;
}
template<typename T>
istream &operator>>(istream &in,vector<T> &v)
{
    for(T &i : v)
        in >> i;
    return in;
}

//fast i/O
void sodium(const string in ,const string out)
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen(in.c_str() , "r" , stdin) , freopen(out.c_str() , "w" , stdout);
#endif 
}
//return the max subarray sum
ll maxSubArraySum(vector<ll> &v)
{
    ll max_so_far = -OO, curr_max = 0;
    for (int i = 0; i < v.size(); i++) 
    {
        curr_max = max(curr_max + v[i], v[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}
//arr[0] : start Position , arr[1] : end position ,arr[2] the max sum 
vector<ll> maxSubArraySumVec(vector<int> &v)
{
    ll max_so_far = -OO, max_ending_here = 0,start = 0, end = 0, s = 0;
    for (int i = 0; i < v.size(); i++) 
    {
        max_ending_here += v[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    return {start , end , max_so_far};
}
//the max(maxsubarray , sum of array  - minsubarray)
template<typename T>
ll max_sub_array_circular(vector<T>&v)
{
    ll sum_of_array = accumulate(all(v) , 0ll);
    ll curr_max = v[0], max_so_far = v[0], curr_min = v[0], min_so_far = v[0];
     // Concept of Kadane's Algorithm
    for (int i = 1; i <v.size(); i++) {
        // Kadane's Algorithm to find Maximum subarray sum.
        curr_max = max(curr_max + v[i], v[i]);
        max_so_far = max(max_so_far, curr_max);
        // Kadane's Algorithm to find Minimum subarray sum.
        curr_min = min(curr_min + v[i], v[i]);
        min_so_far = min(min_so_far, curr_min);
    }
    if (min_so_far == sum_of_array)
        return max_so_far;
    // returning the maximum value
    return max(max_so_far, sum_of_array - min_so_far);
}


void solve()
{ 
    vector<ll>v = {3  , -5  , -9 , 4 , 5 ,-30 , 7};
    cout << max_sub_array_circular(v) << nl; // 10
    cout << maxSubArraySum(v);//9
}
int main()
{
    // sodium("input.txt" , "output.txt");
    int t = 1;
    //cin >> t;
    
    while (t--)
        solve();
    Time
    return 0;
}



