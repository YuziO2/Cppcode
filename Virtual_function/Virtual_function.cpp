#include<iostream>
using namespace std;

class normal
{
protected:
    int basicsalary,salary;
public:
    normal(int x);
    ~normal();
    virtual void input();
    virtual void pay();
    void print();
};

normal::normal(int x=0)
{
    this->basicsalary=x;
}

normal::~normal()
{
}

void normal::input()
{
    cout<<"Please enter the basic salary"<<endl;
    cin>>basicsalary;
}

void normal::pay()
{
    salary=basicsalary;
}

void normal::print()
{
    cout<<"The salary of this man is "<<salary<<endl;
}

class Salesman:public normal
{
protected:
    int sales;
public:
    Salesman(int);
    ~Salesman();
    static int Commission_rate;
    void input_rate() { cin >> Commission_rate; }
    void input(){ cout<<"Please enter the basic salary"<<endl;
    cin>>basicsalary; cout << "Please input the sales volume: "; cin >> sales; }
    void pay() { salary = basicsalary+sales*Commission_rate; }
};
int Salesman::Commission_rate=0;
Salesman::Salesman(int x=0)
{
    this->sales=x;
}

Salesman::~Salesman()
{
}

class Salesmanager:public Salesman
{
private:
    int jobsalary;
public:
    Salesmanager(int);
    ~Salesmanager();
    void input() { cout<<"Please enter the basic salary"<<endl;
    cin>>basicsalary; cout << "Please input the sales volume: "; cin >> sales; 
    cout << "Please input the extra salary: "; cin >> jobsalary; }
	void pay() { salary = basicsalary + sales * Commission_rate + jobsalary; }
};

Salesmanager::Salesmanager(int x=0)
{
    this->jobsalary=x;
}

Salesmanager::~Salesmanager()
{
}

int main()
{
    cout << "Welcome to the Wage calculation system!!" << endl;
	cout << "Please enter the Commission rate:  ";
	Salesman test; test.input_rate();
	normal A; Salesman B; Salesmanager C;
    normal *p;
	while (true)
	{
		cout << "Please enter the number of employee type:" << endl;
		cout << "1.Normal employeer 2.Salesman 3.Salesmanager" << endl;
		int chooser; cin >> chooser;
		switch (chooser)
		{
		case 1:p=&A;p->input(); p->pay(); p->print(); break;
		case 2:p=&B;p->input(); p->pay(); p->print(); break;
		case 3:p=&C;p->input(); p->pay(); p->print(); break;
		default:cout << "Wrong input!Please enter 1,2 or 3!!" << endl;
			break;
		}
		cout << "enter 1 to quit, 2 to continue:  "; int continue_chooser; cin >> continue_chooser;
		cout << endl;
		if (continue_chooser==1)
		{
			return 0;
		}
	}
}
