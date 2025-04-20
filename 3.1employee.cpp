/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 8 March 2025
   3.1 Employee SALARY MANAGEMENT */

#include<iostream>
using namespace std;
class Employee
{
    string name;
    int salary;
    int bonus;
    int totalsalary;

public:
    Employee()//default constructor
    {
        bonus=1500;//default bonus
    }
    Employee(string n,int s,int b)//parametarised constructor
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
    cout<<"Enter the Number of Employee you want to Add the Datas For:";
    cin>>n;
    Employee** e = new Employee*[n];

    for(int i=0;i<n;i++)
    {
        string name;
        int bonus,salary;
        string x;
        cout<<"Enter the Name of the Emplyoee "<< i+1 << ":";
        cin>>name;
        cout<<"Enter the Salary of Employee " <<i+1<<":";
        cin>>salary;
        cout<<"Do you wnat to enter extra bonus for this Employee? (y/n)";
        cin>>x;
        if(x=="y" || x=="Y")
        {
            cout<<"Enter the bonus ammount you want to add for Employee " <<i+1<<":";
            cin>>bonus;
            e[i]= new Employee(name,salary,bonus);


        }
        else if (x=="n" || x=="N")
        {
            cout<<"Applying Default Bonus for this Employee"<<endl;
            e[i]=new Employee(name,salary,1500);
        }
        else
        {
            cout<<"Please Enter a Valid Choice"<<endl;
        }
       cout<<endl;

    }
    for (int i=0;i<n;i++)
    {
        cout<<"Details Of the Employee "<<i+1<<":"<<endl;
        e[i]->display();
    }
    for (int i = 0; i < n; i++)
    {
        delete e[i];
    }
    cout<<"Kavisha Bhagat 24CE007";
}
