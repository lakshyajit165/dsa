/*

Chefina has two sequences A1,A2,…,AN and B1,B2,…,BN. 
She views two sequences with length N as identical if, 
after they are sorted in non-decreasing order, 
the i-th element of one sequence is equal to the i-th element of the other sequence for each i (1≤i≤N).

To impress Chefina, Chef wants to make the sequences identical. 
He may perform the following operation zero or more times: 
choose two integers i and j (1≤i,j≤N) and swap Ai with Bj. The cost of each such operation is min(Ai,Bj).

You have to find the minimum total cost with which Chef can make the two sequences identical.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains N space-separated integers B1,B2,…,BN.
Output
For each test case, print a single line containing one integer ― the minimum cost, or −1 if no valid sequence of operations exists.

Constraints
1≤T≤2,000
1≤N≤2⋅105
1≤Ai,Bi≤109 for each valid i
the sum of N over all test cases does not exceed 2⋅106
Subtasks
Subtask #1 (15 points):

T≤20
N≤20
Subtask #2 (85 points): original constraints

Example Input
3
1
1
2
2
1 2
2 1
2
1 1
2 2
Example Output
-1
0
1
Explanation
Example case 1: There is no way to make the sequences identical, so the answer is −1.

Example case 2: The sequence are identical initially, so the answer is 0.

Example case 3: We can swap A1 with B2, which makes the two sequences identical, so the answer is 1.



---------------- LOGIC/INSIGHTS -----------------------

- if frequency of any elements is odd in any array, then it is not possible to make both arrays
identical, so the asnwer is "-1"

- each array should contain a particular element with half of its total frequency

- minimum cost is either 2*min_element or min of swap of both elements


Soln explanation link - https://www.youtube.com/watch?time_continue=941&v=m9nBuAkwXWE&feature=emb_logo


*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, j, k, t, ip;
 
    cin >> t;
    while (t--)
    {
        ll n, p, a, b, c, d, x, y, z = 0, q, r, m;
        vector<ll> va, vb, ans;
        map<ll, ll> mp, mpa, mpb;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> ip;
            va.push_back(ip);
            mpa[ip]++;
            mp[ip]++;
        }
        for (i = 0; i < n; i++)
        {
            cin >> ip;
            vb.push_back(ip);
            mpb[ip]++;
            mp[ip]++;
        }
        x = 0;
        for (auto it : mp)
        {
 
            if (it.second % 2 != 0)
            {
                x = 1;
                break;
            }
        }
        if (x == 1)
        {
            cout << "-1\n";
            continue;
        }
        else
        {
           
            for (auto it : mpa)
            {
                a = it.second;
                b = mp[it.first] / 2;
                if (a > b)
                {
                    ll tt = a - b;
                    while (tt--)
                    {
                        ans.push_back(it.first);
                    }
                }
            }
           
            for (auto it : mpb)
            {
                a = it.second;
                b = mp[it.first] / 2;
                if (a > b)
                {
                    ll tt = a - b;
                    while (tt--)
                    {
                        ans.push_back(it.first);
                    }
                }
            }
            sort(ans.begin(), ans.end());

            ll ma = *min_element(va.begin(), va.end());

            ll mb = *min_element(vb.begin(), vb.end());

            ll mn = min(ma, mb);

            mn = mn * 2;

            z = 0;
            
            for (i = 0; i < ans.size() / 2; i++)
            {
                z = z + min(mn, ans[i]);
            }
            cout << z << "\n";
        }
    }
    return 0;
}