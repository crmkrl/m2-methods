#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>

/* Define function here */
#define f(x) 1/(1+pow(x,2))

float roundoff(float value, unsigned char prec)
{
  float pow_10 = pow(10.0f, (float)prec);
  return round(value * pow_10) / pow_10;
}

using namespace std;
int main()
{
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval,prec;

 cout<<"Enter precision: ";
 cin>>prec;
 cout<< setprecision(prec)<< fixed;

 /* Input */
 cout<<"Enter lower limit of integration: ";
 cin>>lower;
 cout<<"Enter upper limit of integration: ";
 cin>>upper;
 cout<<"Enter number of sub intervals: ";
 cin>>subInterval;

 /* Calculation */
cout<< endl<<"*********************"<< endl;
cout<<"SIMPSON'S 3/8 METHOD"<< endl;
cout<<"*********************"<< endl;
 /* Finding step size */
 stepSize = roundoff((upper - lower)/subInterval,prec);

 /* Finding Integration Value */
 integration = roundoff(f(lower) + f(upper),prec);

 for(i=1; i<= subInterval-1; i++)
 {
  k = roundoff(lower + i*stepSize,prec);

  if(i%3==0)
  {
    integration = roundoff(integration + 2 * (f(k)),prec);
  }
  else
  {
    integration = roundoff(integration + 3 * (f(k)),prec);
  }

 }

 integration = roundoff(integration * stepSize*3.0/8.0,prec);

 cout<< endl <<"Required value of integration is: "<< integration<<endl<<endl;

 return 0;
}