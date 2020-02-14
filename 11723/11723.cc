#include <bitset>
#include <iostream>
#include <map>
#include <string>

std::bitset<21> bit;

void add()
{
    int x;
    std::cin >> x;

    bit.set(x);
}

void remove()
{
    int x;
    std::cin >> x;

    bit.reset(x);
}

void check()
{
    int x;
    std::cin >> x;

    std::cout << bit.test(x) << '\n';
}

void toggle()
{
    int x;
    std::cin >> x;

    bit.flip(x);
}

void all()
{
    bit.set();
}

void empty()
{
    bit.reset();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m;
    std::cin >> m;

    while (m--)
    {
        std::string s;
        std::cin >> s;

        static std::map<std::string, void (*)()> func = {
            { "add", add },       { "remove", remove }, { "check", check },
            { "toggle", toggle }, { "all", all },       { "empty", empty }
        };

        func[s]();
    }

    return 0;
}