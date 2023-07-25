#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back

#define nl cout << endl;
#define none ""

#define out(a, separator) cout << (a) << separator;
#define in(a)     \
    ({            \
        cin >> a; \
        a;        \
    })
void inm()
{
}
template <class header, typename... trailer>
void inm(header &h, trailer &...t)
{
    in(h);
    return inm(t...);
}
#define outc(__container, separator) \
    ({                               \
        for (auto &&i : __container) \
        {                            \
            out(i, separator);       \
        }                            \
    })

template <typename Container>
void inc_helper(Container &c, size_t size, random_access_iterator_tag)
{
    typename Container::value_type t;
    while (size--)
    {
        c.pb(in(t));
    }
}

template <typename Container>
void inc_helper(Container &c, size_t size, bidirectional_iterator_tag)
{
    typename Container::value_type t;
    while (size--)
    {
        c.pf(in(t));
    }
}

template <typename Container>
void inc_helper(Container &c, size_t size, std::forward_iterator_tag)
{
    typename Container::value_type t;
    while (size--)
    {
        c.insert(in(t));
    }
}
template <typename Container>
void inc(Container &c, size_t size)
{
    inc_helper(c, size, typename iterator_traits<typename Container::iterator>::iterator_category{});
}

#define vstr vector<string>
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int>
#define pl pair<long long, long long>
#define vpi vector<pi>
#define vpl vector<pl>
#define vvi vector<vi>
#define vd vector<double>
#define ll long long
#define ull unsigned long long
#define str string
#define __none []() {}

istream &operator>>(istream &__in, pi &p)
{
    __in >> p.first >> p.second;
    return __in;
}
ostream &operator<<(ostream &__out, pi &p)
{
    __out << p.first << " " << p.second;
    return __out;
}

map<int, vi> m;
vstr v;

void solve(vi &i)
{
    // now, each number of the starting vector,  may it result from other 
    // concatinations, like the 4th string in the first example, it result after concatinate
    // 1st string.
    // and the concatinated string, may it is also comes from other concatinated strings, and so on.

    // so we will loop through/solve the vectort of the starting index.
    // and solve for each element in that vector if it is not null.

    for (int j = 0; j < i.size(); ++j)
    {
        printf("%s", v[i[j] - 1].c_str());
        if (m[i[j]].size() != 0)
        {
            solve(m[i[j]]);
        }
    }
}

int main()
{
    int32_t n;
    in(n);
    bool notinb[n];

    memset(notinb, true, n);// to find the starting index, in the 
                            // first sample it was 3, kattis, and in the second 1.
    inc(v, n);

    // build the map, a map for storing the index and the numbers it follow
    // in the first sample 3 -> 2 
    //                     3 -> 4
    //                     4 -> 1
    // 3 -> [2, 4]
    // 4 -> [1]

    for (size_t i = 0; i < n - 1; i++)
    {
        int a, b;
        inm(a, b);
        m[a].pb(b);
        notinb[b - 1] = false;// in the final, will remain just one number is true which is the starting index.
    }

    int start = 0;
    // finding the starting index.
    for (size_t i = 1; i <= n; i++)
    {
        if (notinb[i - 1])
        {
            start = i;
            break;
        }
    }
    // print it's string.
    out(v[start - 1], none);

    // solve for the vector of that number.
    solve(m[start]);
}
