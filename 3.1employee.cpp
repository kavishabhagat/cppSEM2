/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 2 March 2025
   3.1 EMPLOYEE SALARY MANAGEMENT */

#include<iostream>
using namespace std;
class employee
{
    string name;
    int salary;
    int bonus;
    int totalsalary;

public:
    employee()//default constructor
    {
        bonus=0;
    }
    employee(string n,int s,int b)//parametarised constructor
    {
        name=n;
        salary=s;
        bonus=b;
        totalsalary=caltotalsalary();
    }
    inline int caltotalsalary()//inline function
    {
        return totalsalary=salary+bonus;
    }
    void display()
    {
        cout<<"Name of Employee: "<<name<<endl;
        cout<<"Salary of Employee: "<<salary<<endl;
        cout<<"Bonus of Employee: "<<bonus<<endl;
        cout<<"Total Salary of Employee: "<<totalsalary<<endl<<endl;
    }

};

int main()
{
    int n;
    cout<<"enter the number of employee you want to add the datas for:";
    cin>>n;
    employee** e = new employee*[n];

    for(int i=0;i<n;i++)
    {
        string name;
        int bonus,salary;
        cout<<"enter the name of the emplyoee "<< i+1 << ":";
        cin>>name;
        cout<<"enter the bonus ammount of employee " <<i+1<<":";
        cin>>bonus;
        cout<<"enter the salary of employee " <<i+1<<":";
        cin>>salary;

       e[i]= new employee(name,salary,bonus);
       cout<<endl;

    }
    for (int i=0;i<n;i++)
    {
        cout<<"Details Of the Employee "<<i+1<<":"<<endl;
        e[i]->display();
    }
}
