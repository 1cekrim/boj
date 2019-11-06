#include <algorithm>
#include <iostream>
#include <vector>

class Point
{
 public:
    Point(int x, int y) : x(x), y(y)
    {
        // Do nothing.
    }
    bool operator<(Point& rhs)
    {
        if (rhs.x == x)
        {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
    int x, y;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<Point> data;
    data.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        data.emplace_back(a, b);
    }

    std::sort(data.begin(), data.end());

    for (int i = 0; i < n; ++i)
    {
        std::cout << data[i].x << ' ' << data[i].y << '\n';
    }

    return 0;
}