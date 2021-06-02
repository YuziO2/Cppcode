#include<iostream>
using namespace std;

int io_stream()
{
    while (1)
    {
        cout << "请输入一个数字：（输入114514关闭程序）";
        double x = 0;
        while (cin >> x)
        {
            if (x==114514)
            {
                return 0;
            }
            x = x * x;
            cout << "x的平方是：" << x << endl;
        }
        cout << "错误输入！请重新输入！" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        cin.rdstate();
    }
}

int main()
{
    io_stream();
}