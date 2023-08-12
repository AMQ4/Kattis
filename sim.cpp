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
#define vstr vector<str>
#define ll long long
#define ull unsigned long long
#define str string
#define __none []() {}

istream &operator>>(istream &_in, pi &p)
{
    _in >> p.first >> p.second;
    return _in;
}
ostream &operator<<(ostream &_out, pi &p)
{
    _out << p.first << " " << p.second;
    return _out;
}
void stack_dump(stack<char>& s, list<char>& l)
{
    while (not s.empty())
    {
        l.push_front(s.top());
        s.pop();
    }
    
}
int main()
{
    int t;
    in(t);
    cin.ignore();

    while (t--)
    {
        list<char> r;
        stack<char> s;
        str line;
        getline(cin, line);

        bool flag = true;

        for (auto &&i : line)
        {
            if (i == '<')
            {
                if (flag and !r.empty())
                {
                    r.pop_back();
                }
                else
                {
                    if (not s.empty())
                    {
                        s.pop();
                    }
                }
            }
            else
            {
                if (i == ']')
                {
                    stack_dump(s, r);
                    flag = true;
                }
                else
                {
                    if (i == '[')
                    {
                        stack_dump(s, r);
                        flag = false;
                    }
                    else
                    {
                        if (flag)
                        {
                            r.push_back(i);
                        }
                        else
                        {
                            s.push(i);
                        }
                    }
                }
            }
        }
        stack_dump(s, r);
        for (auto &&i : r)
        {
            cout << i;
        }
        cout << endl;
    }
}
