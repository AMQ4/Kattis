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

long long __count__ = 0;

vl merge(vl &a, vl &b)
{
    vl c(a.size() + b.size());
    int ai = 0, bi = 0, ci = 0;

    for (auto &&i : a)
    {
        __count__ += lower_bound(all(b), i) - b.begin();
    }

    while (ai < a.size() && bi < b.size())
    {
        if (a[ai] < b[bi])
        {
            c[ci] = a[ai];
            ++ai;
        }
        else
        {
            c[ci] = b[bi];
            ++bi;
        }
        ++ci;
    }

    while (ai < a.size())
    {
        c[ci++] = a[ai++];
    }
    while (bi < b.size())
    {
        c[ci++] = b[bi++];
    }
    return c;
}
std::vector<long long> merge_sort(std::vector<long long> &v)
{
    if (v.size() == 1)
    {
        return v;
    }
    vl a1(v.begin(), v.begin() + v.size() / 2);
    vl a2(v.begin() + v.size() / 2, v.end());

    a1 = move(merge_sort(a1));
    a2 = move(merge_sort(a2));

    return merge(a1, a2);
}

int main()
{
    str line;
    in(line);

    vl v;
    for (auto &&i : line)
    {
        v.pb((int)i - 48);
    }

    merge_sort(v);
    out(__count__, none);
}