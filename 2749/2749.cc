#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;

template <typename T>
class Matrix
{
 public:
    Matrix(T n, T m) : n(n), m(m), mat(n, std::vector<T>(m))
    {
        // Do nothing.
    }

    Matrix(std::vector<std::vector<T>> mat)
        : mat(mat), n(mat.size()), m(mat[0].size())
    {
        // Do nothing.
    }

    Matrix(const Matrix<T>& matrix) : n(matrix.n), m(matrix.m), mat(matrix.mat)
    {
        // Do nothing.
    }

    Matrix<T>& operator=(const Matrix<T>& rhs)
    {
        Matrix<T> copy(rhs);
        std::swap(mat, copy.mat);
        std::swap(n, copy.n);
        std::swap(m, copy.m);
        return *this;
    }

    Matrix<T> operator*(const Matrix<T>& rhs) const
    {
        Matrix<T> result(n, rhs.m);
        assert(m == rhs.n);
        for (T i = 0; i < n; ++i)
        {
            for (T j = 0; j < rhs.m; ++j)
            {
                result.mat[i][j] = 0;
                for (T k = 0; k < m; ++k)
                {
                    result.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T>& operator*=(const Matrix<T>& rhs)
    {
        (*this) = (*this) * rhs;
        return *this;
    }

    Matrix<T>& operator%=(T rhs)
    {
        for (T i = 0; i < n; ++i)
        {
            for (T j = 0; j < m; ++j)
            {
                mat[i][j] %= rhs;
            }
        }

        return *this;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& mat)
    {
        for (T i = 0; i < mat.n; ++i)
        {
            for (T j = 0; j < mat.m; ++j)
            {
                std::cout << mat.mat[i][j] << ' ';
            }
            std::cout << '\n';
        }
        return os;
    }

    T n, m;
    std::vector<std::vector<T>> mat;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    Matrix<ll> fibo({ { 1, 1 }, { 1, 0 } }), result({ { 1, 0 }, { 0, 1 } });

    ll n;
    std::cin >> n;

    if (!n)
    {
        std::cout << "0\n";
        return 0;
    }

    --n;

    while (n > 0)
    {
        if (n & 1)
        {
            result *= fibo;
            result %= 1000000;
        }
        fibo *= fibo;
        fibo %= 1000000;
        n >>= 1;
    }

    std::cout << result.mat[0][0] << '\n';

    return 0;
}