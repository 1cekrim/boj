#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using ll = long long;

class SegmentTree
{
 public:
    SegmentTree() = delete;
    SegmentTree(const std::vector<ll>& numbers);
    ll GetSubSum(int idx, int start, int end, int left, int right) const;

 private:
    ll InitTree(const std::vector<ll>& numbers, int idx, int start, int end);
    std::size_t m_size, m_height;
    std::vector<ll> m_numbers;
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
        std::cout << segtree.GetSubSum(0, 0, data.size() - 1, a - 1, b - 1)
                  << '\n';
    }
}

SegmentTree::SegmentTree(const std::vector<ll>& numbers)
    : m_size(numbers.size()),
      m_height(std::ceil(std::log2(m_size))),
      m_numbers((1 << m_height + 1), std::numeric_limits<long long>::max())
{
    InitTree(numbers, 0, 0, m_size - 1);
}

ll SegmentTree::InitTree(const std::vector<ll>& numbers, int idx, int start,
                         int end)
{
    if (start == end)
    {
        m_numbers[idx] = numbers[start];
    }
    else
    {
        m_numbers[idx] = std::min(
            InitTree(numbers, idx * 2 + 1, start, (start + end) / 2),
            InitTree(numbers, idx * 2 + 2, (start + end) / 2 + 1, end));
    }

    return m_numbers[idx];
}

ll SegmentTree::GetSubSum(int idx, int start, int end, int left,
                          int right) const
{
    if (start > right || end < left)
    {
        return std::numeric_limits<long long>::max();
    }

    if (start >= left && end <= right)
    {
        return m_numbers[idx];
    }

    return std::min(
        GetSubSum(2 * idx + 1, start, (start + end) / 2, left, right),
        GetSubSum(2 * idx + 2, (start + end) / 2 + 1, end, left, right));
}