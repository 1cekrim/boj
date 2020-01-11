#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

using ll = long long;

template <typename Node>
class SegmentTree
{
 public:
    SegmentTree() = delete;
    SegmentTree(const std::vector<ll>& numbers)
        : m_size(numbers.size()),
          m_height(std::ceil(std::log2(m_size))),
          m_nodes((1 << m_height + 1), Node{})
    {
        InitTree(numbers, 0, 0, m_size - 1);
    }
    Node GetSub(int idx, int start, int end, int left, int right) const
    {
        if (start > right || left > end)
        {
            return Node{};
        }

        if (start >= left && right >= end)
        {
            return m_nodes[idx];
        }

        Node leftResult =
            GetSub(2 * idx + 1, start, (start + end) / 2, left, right);
        Node rightResult =
            GetSub(2 * idx + 2, (start + end) / 2 + 1, end, left, right);
        return Node::Calculate(leftResult, rightResult);
    }

 private:
    Node InitTree(const std::vector<ll>& numbers, int idx, int start, int end)
    {
        if (start == end)
        {
            m_nodes[idx] = { numbers[start], numbers[start] };
        }
        else
        {
            Node leftResult =
                InitTree(numbers, idx * 2 + 1, start, (start + end) / 2);
            Node rightResult =
                InitTree(numbers, idx * 2 + 2, (start + end) / 2 + 1, end);
            m_nodes[idx] = Node::Calculate(leftResult, rightResult);
        }

        return m_nodes[idx];
    }
    std::size_t m_size, m_height;
    std::vector<Node> m_nodes;
};

template <typename T>
class SegmentNode
{
 public:
    SegmentNode()
        : SegmentNode(std::numeric_limits<T>::max(),
                      std::numeric_limits<T>::min())
    {
        // Do nothing.
    }
    SegmentNode(T min, T max) : m_min(min), m_max(max)
    {
        // Do nothing.
    }
    static SegmentNode<T> Calculate(const SegmentNode<T>& left,
                                    const SegmentNode<T>& right)
    {
        return SegmentNode{ std::min(left.m_min, right.m_min),
                            std::max(left.m_max, right.m_max) };
    }

    T m_min, m_max;
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

    SegmentTree<SegmentNode<ll>> segtree(data);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        SegmentNode<ll> n = segtree.GetSub(0, 0, data.size() - 1, a - 1, b - 1);
        std::cout << n.m_min << ' ' << n.m_max << '\n';
    }
}