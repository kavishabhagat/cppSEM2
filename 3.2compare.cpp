/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 8 March 2025
   3.1 RECURSION AND ITTRATION COMPARISION */

#include <iostream>
using namespace std;
int iterrative(int a[],int n)
{
    int sum;
    for (int i=0; i<n; i++)
    {
        sum=sum+a[i];
    }
    return sum;
}
int reccursive(int a[],int n)
{
    if (n==0)
    {
        return 0;
    }
    return a[n-1] + reccursive(a,n-1);
}
int main()
{
    int n;
    cout<<"enter the number of elements:";
    cin>>n;

    int* x = new int[n];

    cout<<"enter "<<n<<" elements:"<<endl;
    for (int i=0; i<n; i++)
    {
        cin>>x[i];

    }

    int i=iterrative(x,n);
    int r=reccursive(x,n);

    cout<<"Sum using Ittration: "<<i<<endl;
    cout<<"Sum using Reccursion: "<<r<<endl;

    delete[] x;

    cout<<endl<<"Kavisha Bhagat 24CE007";

}
