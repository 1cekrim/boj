#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using llong = long long;

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
        Matrix<T> result(n, rhs.m);
        assert(m == rhs.n);
        for (llong i = 0; i < n; ++i)
        {
            for (llong j = 0; j < rhs.m; ++j)
            {
                result.mat[i][j] = 0;
                for (llong k = 0; k < m; ++k)
                {
                    result.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T>& operator%=(T rhs)
    {
        for (llong i = 0; i < n; ++i)
        {
            for (llong j = 0; j < m; ++j)
            {
                mat[i][j] %= rhs;
            }
        }

        return *this;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& mat)
    {
        for (llong i = 0; i < mat.n; ++i)
        {
            for (llong j = 0; j < mat.m; ++j)
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

Matrix<llong> divide_and_conquer(const Matrix<llong>& a, llong b, llong c)
{
    if (b == 1)
    {
        return a;
    }

    Matrix<llong> temp = divide_and_conquer(a, b / 2, c);
    temp = temp * temp;
    temp %= c;

    if (b % 2)
    {
        temp = temp * a;
        temp %= c;
        return temp;
    }

    return temp;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    llong n, b;
    std::cin >> n >> b;

    Matrix<llong> mat(n, n);

    for (llong i = 0; i < n; ++i)
    {
        for (llong j = 0; j < n; ++j)
        {
            std::cin >> mat.mat[i][j];
        }
    }

    mat %= 1000;

    std::cout << divide_and_conquer(mat, b, 1000) << '\n';

    return 0;
}