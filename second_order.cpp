#include <bits/stdc++.h>
using namespace std;
 
// A sample differential equation
// "dy/dx = (x - y)/2"
float dydx(float x, float y)
{
    return (x + y - 2);
}
 
float roundoff(float value, unsigned char prec)
{
  float pow_10 = pow(10.0f, (float)prec);
  return round(value * pow_10) / pow_10;
}

// Finds value of y for a given x
// using step size h
// and initial value y0 at x0.
float rungeKutta(float x0, float y0,
                 float x, float h,
                 int prec)
{
    int n = roundoff((int)((x - x0) / h),prec);
    float k1, k2;
 
    float y = roundoff(y0,prec);
    for (int i = 1; i <= n; i++) {
        k1 = roundoff(h * dydx(x0, y),prec);
        k2 = roundoff(h * dydx(x0 + 0.5 * h,
                      y + 0.5 * k1),prec);
        y = roundoff(y + (1.0 / 6.0) * (k1 + 2 * k2),prec);
        x0 = roundoff(x0 + h,prec);
    }
 
    return y;
}
 
int main()
{
    float x0, x, y, h;
    int prec;
    cout<<"Enter precision: ";
    cin>>prec;
    cout<< setprecision(prec)<< fixed;

    cout<<"Enter x0: ";
    cin>>x0;
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;
    cout<<"Enter h: ";
    cin>>h;
    cout <<endl<<endl << fixed << setprecision(prec) << "y(x) = " << rungeKutta(x0, y, x, h, prec) <<endl<<endl;
    return 0;
}
 