#include "tasks.h"
#include <iostream>
#include <stack>
using namespace std;
bool IsDebugOutput = false;

#include <numeric>

unsigned GCD(unsigned x, unsigned y)
{
    if (x == y)
        return x;
    if (x == 0)
        return y;
    if (y == 0)
        return x;

    if (~x & 1) // x is even
    {
        if (y & 1) // y is odd
            return GCD(x >> 1, y);
        else // both x and y are even
            return GCD(x >> 1, y >> 1) << 1;
    }

    if (~y & 1) // x is odd, y is even
        return GCD(x, y >> 1);

    if (x > y)
        return GCD(x - y, y);

    return GCD(y - x, x);
}



string Task1(const string &in)
{
    //string res;
    unsigned a, b, c, d;
    sscanf(in.c_str(), "%u/%u+%u/%u", &a, &b, &c, &d);

    MY_DEBUG_ONLY( cout << "a = " << a << endl; )
    MY_DEBUG_ONLY( cout << "b = " << b << endl; )
    MY_DEBUG_ONLY( cout << "c = " << c << endl; )
    MY_DEBUG_ONLY( cout << "d = " << d << endl; )

    unsigned x = a*d + b*c;
    unsigned y = b*d;

    unsigned gcd1 = GCD(x, y);
//    unsigned gcd1 = gcd(x, y); // В с++ уже есть встроенная функция gcd !
    x /= gcd1;
    y /= gcd1;

    return to_string(x) + "/" + to_string(y);
}
//---------------------------------------------------------------


//int Task2(int m[MAX_N][MAX_N], int n)
int Task2(std::vector<std::vector<int>> &m)
{
    for (int i = m.size()-2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
            m[i][j] += max(m[i+1][j], m[i+1][j+1]);
    return m[0][0];
}
//---------------------------------------------------------------


unsigned long Task3(unsigned N)
{
    unsigned long x5  = 1, n5;
    unsigned long x8  = 1, n8;
    unsigned long x55 = 0, n55;
    unsigned long x88 = 0, n88;
    for (unsigned i = 1; i < N; ++i)
    {
        n5 = x8 + x88;
        n8 = x5 + x55;
        n55 = x5;
        n88 = x8;
        x5 = n5; x8 = n8; x55 = n55; x88 = n88;
    }
    return x5 + x55 + x8 + x88;
}
//---------------------------------------------------------------

void go4(int x, int y, vector<vector<int>> &m)
{
    if (x < 0 || x >= (int)m.size()) return;
    if (y < 0 || y >= (int)m.size()) return;
    if (!m[x][y]) return;
    m[x][y] = 0;
    go4(x-1, y, m);
    go4(x+1, y, m);
    go4(x, y-1, m);
    go4(x, y+1, m);
}

unsigned Task4(vector<vector<int>> &m)
{
    unsigned res = 0;
    for (int y = 0; y < (int)m.size(); ++y)
        for (int x = 0; x < (int)m.size(); ++x)
            if (m[x][y])
            {
                ++res;
                go4(x, y, m);
            }

    return res;
}
//---------------------------------------------------------------

int GetHeight(const vector<vector<int>> &m, int x, int y)
{
    const int M = m[0].size();
    int yh = y;
    while (yh < M && m[x][yh] == 0)
        yh++;
    return yh - y;
}

int CalcMaxSquare(const vector<vector<int>> &m, int x, int y)
{
    int minHeight = GetHeight(m, x, y);
    if (!minHeight)
        return 0;

    const int N = m.size();
    int maxSquare = minHeight; // minHeight * 1;
    for (int xw = x+1; xw < N; ++xw)
    {
        int height = GetHeight(m, xw, y);
        if (!height)
            return maxSquare;
        if (minHeight > height)
            minHeight = height;
        int square = (xw-x+1)*minHeight;
        if (square > maxSquare)
            maxSquare = square;
    }
    return maxSquare;
}

unsigned Shed1(const vector<vector<int>> &m)
{
    if (m.empty())
        return 0;
    const int M = m[0].size();
    const int N = m.size();
    int maxSquare = -1;
    for (int y = 0; y < M; ++y)
        for (int x = 0; x < N; ++x)
        {
            int square = CalcMaxSquare(m, x, y);
            if (square > maxSquare)
                maxSquare = square;
        }

    return maxSquare;
}
//---------------------------------------------------------------

void GetHeightD(const vector<vector<int>> &m, int y, vector<int> &line)
{
    const int N = m.size();
    for (int x = 0; x < N; ++x)
        if (m[x][y] == 0)
            line[x]++;
        else
            line[x] = 0;
}

vector<vector<int>> Shed2(const vector<vector<int>> &m)
{
    if (m.empty())
        return vector<vector<int>>();
    const int M = m[0].size();
    const int N = m.size();
    vector<vector<int>> res;
    vector<int> line(N);

    for (int y = 0; y < M; ++y)
    {
        GetHeightD(m, y, line);
        res.emplace_back(line);
    }

    return res;
}
//---------------------------------------------------------------

//std::pair<std::vector<int>, std::vector<int>> Shed3(const std::vector<int> &A)
void Shed3(const std::vector<int> &A, std::vector<int> &L, std::vector<int> &R)
{
    const int N = A.size();

    stack<int> s;
    for (int i = N-1; i >= 0; --i)
    {
        while (!s.empty())
            if (A[i] < A[s.top()])
            {
                L[s.top()] = i+1;
                s.pop();
            }
            else
                break;
        s.push(i);
    }
    while (!s.empty())
    {
        L[s.top()] = 0;
        s.pop();
    }

    //stack<int> s;
    for (int i = 0; i < N; ++i)
    {
        while (!s.empty())
            if (A[i] < A[s.top()])
            {
                R[s.top()] = i-1;
                s.pop();
            }
            else
                break;
        s.push(i);
    }
    while (!s.empty())
    {
        R[s.top()] = N-1;
        s.pop();
    }
}
//---------------------------------------------------------------


int Shed4(const vector<vector<int>> &m)
{
    if (m.empty())
        return 0;
    const int M = m[0].size();
    const int N = m.size();
    int maxSquare = -1;
    vector<int> line(N);
    vector<int> L(N), R(N);

    for (int y = 0; y < M; ++y)
    {
        GetHeightD(m, y, line);
        Shed3(line, L, R);

        for (int x = 0; x < N; ++x)
        {
            int square = (R[x]-L[x]+1)*line[x];
            if (square > maxSquare)
                maxSquare = square;
        }
    }
    return maxSquare;
}
//---------------------------------------------------------------











