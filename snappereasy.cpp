#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back

#define nl cout << endl;
#define none ""

#define out(a, separator) cout << (a) << (separator);
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
#define int ll
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

signed main()
{
    int t, n, k, caseNo = 1;
    in(t);

    while (t--)
    {
        inm(n, k);
        out("Case #", caseNo);
        out((k+1) % (1 << n)? ": OFF": ": ON", "\n");
        caseNo++;
    }
}