#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int N, vector<int> &p, int f)
{
    vector<pair<int, int>> q;
    for (int i = 0; i < N; ++i)
    {
        q.push_back({i + 1, p[i]});
    }

    int s = 0;
    while (true)
    {
        auto m = max_element(q.begin(), q.end(),
                             [](const auto &a, const auto &b)
                             {
                                 return a.second < b.second;
                             });
        s++;

        if (m->first == f)
        {
            break;
        }

        int fp = m->second;

        for (auto &o : q)
        {
            if (o.first < m->first)
            {
                o.second++;
            }
        }

        q.erase(m);
    }

    return s;
}

int main()
{
    int N;
    cin >> N;

    vector<int> p(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> p[i];
    }

    int fpos;
    cin >> fpos;

    int res = f(N, p, fpos);
    cout << res << endl;

    return 0;
}
