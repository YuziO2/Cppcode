#include <iostream>
#include <cstddef>
using namespace std;

template <typename T>
class T_Matrix
{
    template <typename T>
    friend class T_Counter;
    //protected:
public:
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
/*
template <typename T>
class T_Vector : public T_Matrix<T>
{
private:
    
public:
    T_Vector(int);
    ~T_Vector();
};
template <typename T>
T_Vector<T>::T_Vector(int n)
{
    m = 1;
    this->n = n;
    a = new T * [m];
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
*/
template <typename T>
class T_Counter
{
private:
public:
    T_Matrix<T> test;
    T_Counter(int m, int n);
    ~T_Counter();
    /**/
    /*
    T_Matrix<T>& operator=(const T_Matrix<T>& A)
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
    friend T_Matrix<T> operator+(const T_Matrix<T>& A, const T_Matrix<T>& B)
    {
        T_Matrix<T> C(A.m, A.n);
        for (int i = 0; i < A.m; i++)
        {
            for (int k = 0; k < A.n; k++)
            {
                C.a[i][k] = A.a[i][k] + B.a[i][k];
            }
        }
        const T_Matrix<T> D = C;
        return D;
    }
    */

    friend ostream &operator<<(ostream &output, T_Counter<T> &A)
    {
        for (int i = 0; i < A.test.m; i++)
        {
            for (int k = 0; k < A.test.n; k++)
            {
                cout << A.test.a[i][k] << "  ";
            }
            cout << endl;
        }
        return output;
    }

    friend istream &operator>>(istream &input, T_Counter<T> &A)
    {

        for (int i = 0; i < A.test.m; i++)
        {
            for (int k = 0; k < A.test.n; k++)
            {
                cin >> A.test.a[i][k];
            }
        }
        return input;
    }
};

template <typename T>
T_Counter<T>::T_Counter(int m, int n)
{
    test.m = m;
    test.n = n;
    test.a = new T *[m];
    for (int i = 0; i < m; i++)
        test.a[i] = new T[n];
}

template <typename T>
T_Counter<T>::~T_Counter()
{
    for (int i = 0; i < test.m; i++)
        delete[] test.a[i];
    delete[] test.a;
}

int main()
{
    int m, n;
    cout << "enter m: ";
    cin >> m;
    cout << "enter n: ";
    cin >> n;

    T_Counter<int> Counter(m, n);

    cin >> Counter;
    cout << Counter;
}
