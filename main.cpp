#include <iostream>

#include "tasks.h"

using namespace std;

int main()
{
    IsDebugOutput = true;

    cout << "Task 1" << endl;
    auto res1 = Task1("2/100+3/100");
    cout << "res1 = " << res1 << endl;


    cout << "Task 2" << endl;
    size_t n;
    int t;
    n = 1;
    //cin >> n;
    vector<vector<int>> m2(n);
    m2[0].emplace_back(1);
//    for (int i = 0; i < n; ++i)
//        for (int j = 0; j <= i; ++j)
//        {
//            cin >> t;
//            m2[i].emplace_back(t);
//        }
    auto res2 = Task2(m2);
    cout << "res2 = " << res2 << endl;


    cout << "Task 3" << endl;
    n = 3;
    auto res3 = Task3(n);
    cout << "res3 = " << res3 << endl;


    cout << "Task 4" << endl;
    n = 1;
    vector<vector<int>> m4(n);
    m4[0].emplace_back(1);
//    for (size_t i = 0; i < n; ++i)
//        for (size_t j = 0; j < n; ++j)
//        {
//            cin >> t;
//            m4[i].emplace_back(t);
//        }
    auto res4 = Task4(m4);
    cout << "res4 = " << res4 << endl;


//    cout << "Shed 1" << endl;
    size_t m = 3;
//    n = 4;
//    cin >> n >> m;
//    vector<vector<int>> shed1(n);

////    4 3         // N M
////    0 0 0 0
////    0 1 0 0
////    1 0 0 0
////    shed1.emplace_back(vector<int>{1, 0, 1});
////    shed1.emplace_back(vector<int>{0, 1, 0});
////    shed1.emplace_back(vector<int>{0, 0, 0});
////    shed1.emplace_back(vector<int>{0, 0, 0});

//    for (size_t y = 0; y < m; ++y)
//        for (size_t x = 0; x < n; ++x)
//        {
//            cin >> t;
//            shed1[x].emplace_back(t);
//        }

//    auto res_s_1 = Shed1(shed1);
//    cout << "res_s_1 = " << res_s_1 << endl;
    //--------------------------------------

//    cout << "Shed 2" << endl;
//    m = 3;
//    n = 4;
//    cin >> n >> m;
//    vector<vector<int>> shed2;
//    for (size_t j = 0; j < n; ++j)
//        shed2.emplace_back(vector<int>(m));
//    cin >> t;
//    for (int i = 0; i < t; ++i)
//    {
//        int x, y;
//        cin >> x >> y;
//        shed2[x][y] = 1;
//    }

//    auto res_s_2 = Shed2(shed2);
//    cout << "res_s_2:" << endl;
//    for (size_t y = 0; y < m; ++y)
//        for (size_t x = 0; x < n; ++x)
//        {
//            cout << res_s_2[y][x] << ((x==n-1)?"\n":" ");
//        }
//    cout << endl;
    //--------------------------------------

//    cout << "Shed 3" << endl;
//    cin >> n;
//    vector<int> A;
//    for (size_t i = 0; i < n; ++i)
//    {
//        cin >> t;
//        A.emplace_back(t);
//    }
//    vector<int> L(n), R(n);
//    Shed3(A, L, R);
//    cout << "res_s_3:" << endl;
//    cout << "L: ";
//    for (size_t i = 0; i < n; ++i)
//        cout << L[i] << ((i==n-1)?"\n":" ");
//    cout << "R: ";
//    for (size_t i = 0; i < n; ++i)
//        cout << R[i] << ((i==n-1)?"\n":" ");
    //--------------------------------------

    cout << "Shed 4" << endl;
    cin >> n >> m;
    vector<vector<int>> shed4;
    for (size_t j = 0; j < n; ++j)
        shed4.emplace_back(vector<int>(m));
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int x, y;
        cin >> x >> y;
        shed4[x][y] = 1;
    }

    auto res_s_4 = Shed4(shed4);
    cout << "res_s_4 = " << res_s_4 << endl;

    return 0;
}
