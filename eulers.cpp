#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>

/* defining ordinary differential equation to be solved */
/* In this example we are solving dy/dx = x + y */
#define f(x,y) x+y

using namespace std;

float roundoff(float value, unsigned char prec)
{
  float pow_10 = pow(10.0f, (float)prec);
  return round(value * pow_10) / pow_10;
}
int main()
{
 float x0, y0, xn, h, yn, slope;
 int i, n,prec;

 cout<<"Enter precision: ";
 cin>>prec;
 cout<< setprecision(prec)<< fixed;

 cout<<"Enter Initial Condition"<< endl;
 cout<<"x0 = ";
 cin>> x0;
 cout<<"y0 = ";
 cin >> y0;
 cout<<"Enter calculation point xn = ";
 cin>>xn;
 cout<<"Enter number of steps: ";
 cin>> n;

 /* Calculating step size (h) */
 h = roundoff((xn-x0)/n,prec);

cout<< endl<<"*********************"<< endl;
cout<<"EULER'S METHOD"<< endl;
cout<<"*********************"<< endl;

 cout<<"\nx0\ty0\tslope\tyn\n";
 cout<<"------------------------------\n";

 for(i=0; i < n; i++)
 {
  slope = roundoff(f(x0, y0),prec);
  yn = roundoff(y0 + h * slope,prec);
  cout<< roundoff(x0,prec)<<"\t"
      << roundoff(y0,prec)<<"\t"
      << roundoff(slope,prec)<<"\t"
      << yn<< endl;
  y0 = roundoff(yn,prec);
  x0 = roundoff(x0+h,prec);
 }

 /* Displaying result */
 cout<<"\nValue of y at x = "<< roundoff(xn,prec)<< " is " << roundoff(yn,prec) <<endl<<endl;

 return 0;
}
