#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
#include <utility>

using ll = long long;
using Node = std::pair<ll, ll>;

class SegmentTree
{
 public:
    SegmentTree() = delete;
    SegmentTree(const std::vector<ll>& numbers);
    Node GetSub(int idx, int start, int end, int left, int right) const;

 private:
    Node InitTree(const std::vector<ll>& numbers, int idx, int start, int end);
    std::size_t m_size, m_height;
    std::vector<Node> m_numbers;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, M;

    std::cin >> N >> M;

    std::vector<ll> data;
    data.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        ll t;
        std::cin >> t;
        data.push_back(t);
    }

    SegmentTree segtree(data);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        Node n = segtree.GetSub(0, 0, data.size() - 1, a - 1, b - 1);
        std::cout << n.first << ' ' << n.second
                  << '\n';
    }
}

SegmentTree::SegmentTree(const std::vector<ll>& numbers)
    : m_size(numbers.size()),
      m_height(std::ceil(std::log2(m_size))),
      m_numbers((1 << m_height + 1), Node({std::numeric_limits<long long>::max(), std::numeric_limits<long long>::min()}))
{
    InitTree(numbers, 0, 0, m_size - 1);
}

Node SegmentTree::InitTree(const std::vector<ll>& numbers, int idx, int start,
                         int end)
{
    if (start == end)
    {
        m_numbers[idx] = {numbers[start], numbers[start]};
    }
    else
    {
        Node leftResult = InitTree(numbers, idx * 2 + 1, start, (start + end) / 2);
        Node rightResult = InitTree(numbers, idx * 2 + 2, (start + end) / 2 + 1, end);
        m_numbers[idx] = {std::min(leftResult.first, rightResult.first), std::max(leftResult.second, rightResult.second)};
    }

    return m_numbers[idx];
}

Node SegmentTree::GetSub(int idx, int start, int end, int left,
                          int right) const
{
    if (start > right || end < left)
    {
        return {std::numeric_limits<long long>::max(), std::numeric_limits<long long>::min()};
    }

    if (start >= left && end <= right)
    {
        return m_numbers[idx];
    }

    Node leftResult = GetSub(2 * idx + 1, start, (start + end) / 2, left, right);
    Node rightResult = GetSub(2 * idx + 2, (start + end) / 2 + 1, end, left, right);
    return {std::min(leftResult.first, rightResult.first), std::max(leftResult.second, rightResult.second)};
}