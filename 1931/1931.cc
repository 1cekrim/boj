#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::tuple<int, int>> data;
    data.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int start, end;
        std::cin >> start >> end;
        data.emplace_back(start, end);
    }

    std::sort(data.begin(), data.end(), [](auto& lhs, auto& rhs) {
        auto [start1, end1] = lhs;
        auto [start2, end2] = rhs;
        if (end1 == end2)
        {
            return start1 < start2;
        }
        return end1 < end2;
    });

    int result = 1, last = std::get<1>(data[0]);
    for (int i = 1; i < n; ++i)
    {
        auto [start, end] = data[i];
        if (start >= last)
        {
            last = end;
            ++result;
        }
    }

    std::cout << result << '\n';

    return 0;
}