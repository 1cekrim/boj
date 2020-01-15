#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Matrix
{
 public:
    Matrix(T n, T m) : n(n), m(m), mat(n, std::vector<T>(m))
    {
        // Do nothing.
    }

    Matrix(const Matrix<T>& matrix) : n(matrix.n), m(matrix.m), mat(matrix.mat)
    {
        // Do nothing.
    }

    Matrix<T> operator*(const Matrix<T>& rhs)
    {
        assert(m == rhs.n);
        Matrix<T> result(n, rhs.m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < rhs.m; ++j)
            {
                result.mat[i][j] = 0;
                for (int k = 0; k < m; ++k)
                {
                    result.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T> operator+(const Matrix<T>& rhs) const
    {
        assert(m == rhs.m && n == rhs.n);
        Matrix<T> result(n, m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                result.mat[i][j] = mat[i][j] + rhs.mat[i][j];
            }
        }

        return result;
    }

    Matrix<T>& operator%=(T rhs)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                mat[i][j] %= rhs;
            }
        }

        return *this;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& mat)
    {
        for (int i = 0; i < mat.n; ++i)
        {
            for (int j = 0; j < mat.m; ++j)
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

    int n, m;
    std::cin >> n >> m;

    Matrix a(n, m), b(n, m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> a.mat[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> b.mat[i][j];
        }
    }

    std::cout << a + b << '\n';

    return 0;
}