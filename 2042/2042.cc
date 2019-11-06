#include <cmath>
#include <iostream>
#include <vector>

using ll = long long;

class SegmentTree
{
 public:
    SegmentTree() = delete;
    SegmentTree(const std::vector<ll>& numbers);
    ll GetSubSum(int idx, int start, int end, int left, int right) const;
    void UpdateTree(int idx, int start, int end, int target, ll delta);

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

    int N, M, K;

    std::cin >> N >> M >> K;

    std::vector<ll> data;
    data.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        ll t;
        std::cin >> t;
        data.push_back(t);
    }

    SegmentTree segtree(data);

    for (int i = 0; i < (M + K); ++i)
    {
        ll a, b, c;
        std::cin >> a >> b >> c;

        switch (a)
        {
            case 1:
            {
                ll delta = c - data[b - 1];
                data[b - 1] = c;
                segtree.UpdateTree(0, 0, data.size() - 1, b - 1, delta);
                break;
            }
            case 2:
            {
                std::cout << segtree.GetSubSum(0, 0, data.size() - 1, b - 1,
                                               c - 1)
                          << '\n';
                break;
            }
            default:
                break;
        }
    }
}

void SegmentTree::UpdateTree(int idx, int start, int end, int target, ll delta)
{
    if (target < start || target > end)
    {
        return;
    }

    m_numbers[idx] += delta;

    if (start != end)
    {
        UpdateTree(idx * 2 + 1, start, (start + end) / 2, target, delta);
        UpdateTree(idx * 2 + 2, (start + end) / 2 + 1, end, target, delta);
    }
}

SegmentTree::SegmentTree(const std::vector<ll>& numbers)
    : m_size(numbers.size()),
      m_height(std::ceil(std::log2(m_size))),
      m_numbers((1 << m_height + 1))
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
        m_numbers[idx] =
            InitTree(numbers, idx * 2 + 1, start, (start + end) / 2) +
            InitTree(numbers, idx * 2 + 2, (start + end) / 2 + 1, end);
    }

    return m_numbers[idx];
}

ll SegmentTree::GetSubSum(int idx, int start, int end, int left,
                          int right) const
{
    if (start > right || end < left)
    {
        return 0;
    }

    if (start >= left && end <= right)
    {
        return m_numbers[idx];
    }

    return GetSubSum(2 * idx + 1, start, (start + end) / 2, left, right) +
           GetSubSum(2 * idx + 2, (start + end) / 2 + 1, end, left, right);
}