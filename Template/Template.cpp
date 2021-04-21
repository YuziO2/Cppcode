#include <iostream>
#include <cstddef>
using namespace std;
template <typename T>
class T_Matrix
{
    friend class T_Counter;
protected:
    int m, n;
    T **a;

public:
    T_Matrix(int, int);
    T_Matrix(T **, int, int);
    T_Matrix(const T_Matrix &);
    T_Matrix();
    ~T_Matrix();
};

template <typename T>
T_Matrix<T>::T_Matrix(int m, int n)
{
    this->m = m;
    this->n = n;
    a = new T *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new T[n];
    }
}

template <typename T>
T_Matrix<T>::T_Matrix(const T_Matrix &M)
{
    this->m = M.m;
    this->n = M.n;
    this->a = new T *[m];
    for (int i = 0; i < m; i++)
    {
        this->a[i] = new T[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            this->a[i][j] = M.a[i][j];
    }
}

template <typename T>
T_Matrix<T>::T_Matrix(T **P, int m, int n)
{
    this->m = m;
    this->n = n;
    a = P;
}

template <typename T>
T_Matrix<T>::T_Matrix()
{
}

template <typename T>
T_Matrix<T>::~T_Matrix()
{
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
        a[i] = NULL;
    }
    delete[] a;
}

template <typename T>
class T_Vector : public T_Matrix<T>
{
private:
    /* data */
public:
    T_Vector(int);
    ~T_Vector();
};
template <typename T>
T_Vector<T>::T_Vector(int n)
{
    m = 1;
    this->n = n;
    a = new T *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new T[n];
    }
}

template <typename T>
T_Vector<T>::~T_Vector()
{
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
        a[i] = NULL;
    }
    delete[] a;
}

template <typename T>
class T_Counter
{
private:
    T_Matrix test;
public:
    T_Counter(/* args */);
    ~T_Counter();
    T_Matrix &operator=(const T_Matrix &A)
    {
        test.m = A.m;
        test.n = A.n;
        for (int i = 0; i < A.m; i++)
        {
            for (int k = 0; k < A.n; k++)
            {
                test.a[i][k] = A.a[i][k];
            }
        }
        return *this;
    }
    friend T_Matrix operator+(const T_Matrix &A, const T_Matrix &B)
    {
        T_Matrix C(A.m, A.n);
        for (int i = 0; i < A.m; i++)
        {
            for (int k = 0; k < A.n; k++)
            {
                C.a[i][k] = A.a[i][k] + B.a[i][k];
            }
        }
        const T_Matrix D = C;
        return D;
    }

    friend ostream &operator<<(ostream &output, const T_Matrix &A)
    {
        for (int i = 0; i < A.m; i++)
        {
            for (int k = 0; k < A.n; k++)
            {
                cout << A.a[i][k] << "  ";
            }
            cout << endl;
        }
        return output;
    }

    friend istream &operator>>(istream &input, T_Matrix &A)
    {

        for (int i = 0; i < A.m; i++)
        {
            for (int k = 0; k < A.n; k++)
            {
                cin >> A.a[i][k];
            }
        }
        return input;
    }
};

template <typename T>
T_Counter<T>::T_Counter(/* args */)
{
}

template <typename T>
T_Counter<T>::~T_Counter()
{
}


int main()
{
    int m, n;
    cout << "enter m: ";cin >> m;
    cout << "enter n: ";cin >> n;
    T_Matrix<int> A(m, n);
    cout << "Please enter this " << m << " x " << n << " matrix" << endl;
    cin >> A;
    T_Matrix<int> B(m, n);
    cout << "Please enter this " << m << " x " << n << " matrix" << endl;
    cin >> B;
    cout << "C=A+B=" << endl;
    cout << (A + B) << endl;        //重载函数无法使用 ver_0.1
}