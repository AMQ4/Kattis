#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define vl vector<long long>
#define nl cout << endl;
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
#define out(a, separator) cout << (a) << separator;
#define pi pair<int, int>
#define pl pair<long long, long long>
#define vpi vector<pi>
#define vpl vector<pl>
#define vvi vector<vi>
#define vd vector<double>
#define ll long long
#define ull unsigned long long
#define str string
#define none ""
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
/// @brief this function finds an iterator of the smallest element in defined range.
template <typename it, typename _Compare = std::greater<typename it::value_type>>
it minc(it firstIt, it endIt, _Compare op = std::greater<typename it::value_type>())
{
    it minIt = firstIt++;
    for (; firstIt != endIt; ++firstIt)
    {
        if (op(*minIt, *firstIt))
        {
            minIt = firstIt;
        }
    }
    return minIt;
}
template <class T>
T gcd(T a, T b)
{
    if (b == 0)
    {
        throw "devision by zero\n";
    }
    return a % b ? gcd(b, a % b) : b;
}
template <class U, class... T>
U gcd(U a, U b, T... c)
{
    if (b == 0)
    {
        throw "devision by zero\n";
    }
    return a % b ? gcd(b, a % b, c...) : gcd(b, c...);
}

template <class T>
void counting_sort(std::vector<T> &a)
{
    std::vector<T> sorted(a.size());
    size_t low = *minc(all(a));
    size_t max = *minc(all(a), std::less<int>());
    size_t k = max - low + 1;

    vi f(k, 0);
    for (size_t i = 0; i < a.size(); i++)
    {
        ++f[a[i] - low];
    }

    // partial sum
    for (size_t i = 1; i < k; i++)
    {
        f[i] = f[i] + f[i - 1];
    }

    for (size_t i = a.size() - 1; i < a.size(); i++)
    {
        sorted[f[a[i] - low] - 1] = a[i];
        --f[a[i] - low];
    }

    a = move(sorted);
}

vi traial_division(int n)
{
    vi d;
    while (n % 2 == 0)
    {
        d.push_back(2);
        n /= 2;
    }
    for (size_t i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            d.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        d.push_back(n);
    }

    outc(d, " ");
    return d;
}
vi divisiors(int n)
{
    vi d;
    int sq = sqrt(n);

    for (size_t i = 1; i <= sq; i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            if (n / i != i)
            {
                d.push_back(n / i);
            }
        }
    }

    return d;
}

int no_of_n_s_in_v(vi &v, int n)
{
    auto it1 = upper_bound(all(v), n - 1), it2 = upper_bound(all(v), n);
    return (it2 - it1);
}

bool ___hash[(int)1e5 + 1];
void flip(string& l)
{
    for(int i = 0; i< l.size();++i)
    {
        if(l[i] == '0')
        {
            l[i] = '1';
        }
        else
        {
            l[i] = '0';
        }
    }
}
int main()
{
    int N;
    in(N);

    string l,his_ans;
    inm(l, his_ans);

    if(N&1)
    {
        flip(l);
    }
    if(l == his_ans)
    {
        out("Deletion succeeded",none);
    }
    else
    {
        out("Deletion failed",none)
    }

    
}

