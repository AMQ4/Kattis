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
    int n, T, temp, sum {0};
    inm(n,T);

    queue<int> q;
    while (n--)
    {
        q.push(in(temp));
    }

    n = q.size();

    while (!q.empty())
    {
        if(sum + q.front() <= T)
        {
            sum += q.front();
            q.pop();
        }
        else
        {
            break;
        }
    }
    
    out(n - q.size(), none);

//  other simpler  ans. 

    // int n, T, temp = 0, counter = 0;
    // inm(n, T);

    // int sum = 0;

    // while (counter < n)
    // {
    //     in(temp);
    //     if (sum + temp <= T)
    //     {
    //         sum += temp;
    //         ++counter;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    // out(counter, none);
}
