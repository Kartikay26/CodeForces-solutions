// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

const int mod = 1e9+7;

template<int n>
class Vector
{
public:
    int mat[n];
    Vector() {
        memset(mat, 0, sizeof(mat));
    }
    Vector(int given[n]) {
        memcpy(mat, given, sizeof(mat));
    }
    Vector(Vector& other) {
        memcpy(mat, other.mat, sizeof(mat));
    }
    friend ostream& operator<< (ostream& out, Vector v)
    {
        out << '\n';
        for (auto& x : v.mat) {
            out << x << '\n';
        }
        return out;
    }
};
template<int n>
class Matrix
{
public:
    int mat[n][n];
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }
    Matrix(int given[n][n]) {
        memcpy(mat, given, sizeof(mat));
    }
    Matrix(Matrix& other) {
        memcpy(mat, other.mat, sizeof(mat));
    }
    Matrix operator*(Matrix other) {
        Matrix ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans.mat[i][j] += (mat[i][k] * other.mat[k][j]) % mod;
                    ans.mat[i][j] %= mod;
                }
            }
        }
        return ans;
    }
    Vector<n> operator*(Vector<n> other) {
        Vector<n> ans;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                ans.mat[i] += (mat[i][k] * other.mat[k]) % mod;
                ans.mat[i] %= mod;
            }
        }
        return ans;
    }
    friend ostream& operator<< (ostream& out, Matrix m)
    {
        out << '\n';
        for (auto& row : m.mat) {
            for (auto& x : row) {
                out << x << ' ';
            }
            out << '\n';
        }
        return out;
    }
};

void test()
{
    int M[4][4] = {
        {0,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {1,1,1,0},
    };
    int V[] = {0,0,0,1};
    Matrix<4> m (M);
    Vector<4> v (V);
    int n; cin >> n;
    while(n>0){
        if(n&1){
            v = m*v;
        }
        m = m*m;
        n /= 2;
    }
    cout << v.mat[3] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    test();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}