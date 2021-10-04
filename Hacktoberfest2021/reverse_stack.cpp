#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(0 && cin.tie(0) && cout.tie(0));
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repe(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i > b; i--)
#define rrepe(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sorta(v) sort(all(v))
#define sortd(v) sort(all(v), greater<int>())
#define END "\n"
typedef long long ll;
const int MOD = 1e9 + 7;
const int maxN = 1e5 + 2;

// Google Kick Start
// int main()
// {
//	fastIO;
//	int t;
//	cin >> t;
//	repe(tc, 1, t)
//	{
//		cout << "Case #" << tc << ": ";
//	}
//	return 0;
// }

void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topele);
}

void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}

int main()
{
    fastIO;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << END;
    return 0;
}