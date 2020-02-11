#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Data
{
    int old, idx;
    std::string name;

    bool operator<(const Data& data) const
    {
        if (old == data.old)
        {
            return idx < data.idx;
        }
        return old < data.old;
    }

    friend std::istream& operator>>(std::istream& it, Data& data)
    {
        it >> data.old >> data.name;
        return it;
    }

    friend std::ostream& operator<<(std::ostream& ot, const Data& data)
    {
        ot << data.old << ' ' << data.name;
        return ot;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<Data> v(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
        v[i].idx = i;
    }

    std::sort(v.begin(), v.end());

    for (auto& p : v)
    {
        std::cout << p << '\n';
    }

    return 0;
}