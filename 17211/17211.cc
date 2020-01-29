#include <algorithm>
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

    Matrix<T> operator*(int rhs) const
    {
        Matrix<T> result(*this);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                result.mat[i][j] *= rhs;
            }
        }
        return result;
    }

    Matrix<T>& operator*=(const Matrix<T>& rhs)
    {
        (*this) = (*this) * rhs;
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

    int n, init;
    std::cin >> n >> init;

    Matrix<double> x(2, 1);

    switch (init)
    {
        case 0:
            x.mat[0][0] = 1;
            x.mat[1][0] = 0;
            break;
        case 1:
            x.mat[0][0] = 0;
            x.mat[1][0] = 1;
            break;
    }

    Matrix<double> markov(2, 2), result({ { 1, 0 }, { 0, 1 } });
    std::cin >> markov.mat[0][0] >> markov.mat[1][0] >> markov.mat[0][1] >>
        markov.mat[1][1];

    while (n > 0)
    {
        if (n & 1)
        {
            result *= markov;
        }
        markov *= markov;
        n >>= 1;
    }

    result = result * x * 1000;

    std::cout << static_cast<int>(result.mat[0][0] + 0.5) << '\n'
              << static_cast<int>(result.mat[1][0] + 0.5) << '\n';

    return 0;
}