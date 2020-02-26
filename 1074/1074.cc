#include <iostream>

void solve(int cnt, int x, int y, int r, int c)
{
    static int result;

    if (!cnt)
    {
        if (x == c && y == r)
        {
            std::cout << result << '\n';
        }
        if (x == c - 1 && y == r)
        {
            std::cout << result + 1 << '\n';
        }
        if (x == c && y == r - 1)
        {
            std::cout << result + 2 << '\n';
        }
        if (x == c - 1 && y == r - 1)
        {
            std::cout << result + 3 << '\n';
        }
        result += 4;
    }
    else
    {
        solve(cnt - 1, x, y, r, c);
        solve(cnt - 1, x + (1 << cnt), y, r, c);
        solve(cnt - 1, x, y + (1 << cnt), r, c);
        solve(cnt - 1, x + (1 << cnt), y + (1 << cnt), r, c);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, r, c;
    std::cin >> n >> r >> c;

    solve(n - 1, 0, 0, r, c);

    return 0;
}