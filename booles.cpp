#include <bits/stdc++.h>
using namespace std;
 
// In order to represent the implementation,
// a function f(x) = 1/(1 + x) is considered
// in this program
 
// Function to return the value of f(x)
// for the given value of x
float y(float x)
{
    return (1 / (1 + x));
}
 
// Function to computes the integrand of y
// at the given intervals of x with
// step size h and the initial limit a
// and final limit b
float BooleRule(float a, float b)
{
 
    // Number of intervals
    int n = 4;
    int h;
 
    // Computing the step size
    h = ((b - a) / n);
    float sum = 0;
 
    // Substituing a = 0, b = 4 and h = 1
    float bl = ((7 * y(a) +
                32 * y(a + h) +
                12 * y(a + 2 * h) +
                32 * y(a + 3 * h) +
                 7 * y(a + 4 * h)) *
                 2 * h / 45);
 
    sum = sum + bl;
    return sum;
}
 
int main()
{
    float lowlimit, upplimit;
    int prec;

    cout<<"Enter precision: ";
    cin>>prec;
    cout<< setprecision(prec)<< fixed;

    cout<<"Enter lower limit: ";
    cin>> lowlimit;
    cout<<"Enter upper limit: ";
    cin >> upplimit;

    cout<< endl<<"*********************"<< endl;
    cout<<"BOOLE'S METHOD"<< endl;
    cout<<"*********************"<< endl;

    cout << fixed << setprecision(prec) <<
        "f(x) = " << BooleRule(lowlimit, upplimit) <<endl<<endl;
         
    return 0;
}
 