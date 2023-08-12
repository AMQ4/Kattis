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

int main()
{
    int n;
    in(n);

    vector<char> v;
    inc(v, n);

    cin.ignore();
    str line;

    getline(cin, line);

    stack<char> s;

    for (size_t i = 0; i < line.size(); i+= 2)
    {
        if (line[i] >= 'A' and line[i] <= 'Z')
        {
            s.push(v[line[i] - 65]);
        }
        else
        {
            char a = s.top();
            s.pop();

            if (line[i] == '-')
            {
                s.push((a == 'T') ? 'F' : 'T');
            }
            else
            {
                char b = s.top();
                s.pop();

                if (line[i] == '*')
                {
                    if (a == b and a == 'T')
                    {
                        s.push('T');
                    }
                    else
                    {
                        s.push('F');
                    }
                }
                else
                {
                    if(a == b and a == 'F')
                    {
                        s.push('F');
                    }
                    else
                    {
                        s.push('T');
                    }
                }
            }
        }
    }

    cout << s.top();
}