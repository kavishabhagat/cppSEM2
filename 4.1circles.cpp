/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 15 March 2025
   4.1 INHERITANCE-CIRCLES */

#include<iostream>
using namespace std;

class Circle;
class Shape
{
protected:
    int radiusValue;

public:
    void setRadius(int r)
    {
        radiusValue = r;
    }

    void showRadius()
    {
        cout << "Radius of the circle is: " << radiusValue;
    }

    int getRadius()
    {
        return radiusValue;
    }
};

class Circle : public Shape
{
    float circleArea;

public:
    void computeArea(int rad)
    {
        circleArea = 3.14 * rad * rad;
    }

    void showArea()
    {
        cout << endl << "Area of the circle is: " << circleArea << endl;
    }
};

int main()
{
    int inputRadius;
    Circle* c = new Circle[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter radius of circle " << i + 1 << ": ";
        cin >> inputRadius;
        c[i].setRadius(inputRadius);
    }

    for (int i = 0; i < 3; i++)
    {
        c[i].computeArea(c[i].getRadius());
    }

    for (int i = 0; i < 3; i++)
    {
        cout<<endl<<"CIRCLE "<< i+1 <<":"<<endl;
        c[i].showRadius();
        c[i].showArea();
    }

    delete[] c;
    cout<<endl<<"Kavisha Bhagat 24CE007";
}
