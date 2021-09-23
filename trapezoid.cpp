#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>

#define f(x) 1/(1+pow(x,2))

using namespace std;

float roundoff(float value, unsigned char prec)
{
  float pow_10 = pow(10.0f, (float)prec);
  return round(value * pow_10) / pow_10;
}

int main()
{
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval, prec;

 cout<<"Enter the precision: ";
 cin>>prec;
 cout<< setprecision(prec)<< fixed;

 cout<<"Enter lower limit of integration: ";
 cin>>lower;
 cout<<"Enter upper limit of integration: ";
 cin>>upper;
 cout<<"Enter number of sub intervals: ";
 cin>>subInterval;

 /* Calculation */
 stepSize = roundoff((upper - lower)/subInterval,prec); 
 integration = roundoff(f(lower),prec) + roundoff(f(upper),prec);

cout<< endl<<"*********************"<< endl;
cout<<"Trapezoidal Method"<< endl;
cout<<"*********************"<< endl;

 for(i=1; i<= subInterval-1; i++)
 {
  k = roundoff(lower + i*stepSize, prec);
  integration = roundoff(integration + 2 * (f(k)), prec);
 }

 integration = roundoff(integration * stepSize/2, prec);

 cout<< endl<<"Required value of integration is: "<< roundoff(integration, prec) <<endl <<endl;

 return 0;
}