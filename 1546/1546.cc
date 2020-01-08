#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    float max = std::numeric_limits<float>::min();

    std::vector<float> score(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> score[i];
        max = std::max(score[i], max);
    }

    float sum{};
    for (int i = 0; i < n; ++i)
    {
        sum += score[i] / max * 100;
    }

    std::cout << sum / n << '\n';

    return 0;
}