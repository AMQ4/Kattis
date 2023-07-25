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

bool is_open_bracket(char &c)
{
    return c == '(' || c == '{' || c == '[';
}

bool matched(char &temp, char &top_of_the_stack)
{
    switch (top_of_the_stack)
    {
    case '(':
        return temp == ')';
    case '[':
        return temp == ']';

    default:
        return temp == '}';
    }

    return false;
}

int main()
{
    int n, counter = -1;
    in(n);
    stack<char> s;
    string line;

    std::cin.ignore();
    std::getline(std::cin, line);
    
    for (auto &&i : line)
    {
        ++counter;

        if (i == ' ')
        {
            continue;
        }

        if (is_open_bracket(i))
        {
            s.push(i);
        }
        else
        {
            if (s.empty() || !matched(i, s.top()))
            {
                out(i,' ');
                out(counter, none);
                exit(0);
            }
            else
            {
                s.pop();
            }
        }
    }

    out("ok so far",none);
}
