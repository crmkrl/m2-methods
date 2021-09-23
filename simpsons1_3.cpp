#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>

/* Define function here */
#define f(x) (1/sqrt(2*M_PI))*exp((-1/2)*(pow(x,2)))

using namespace std;
int main()
{
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval, prec;

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

cout<< endl<<"*********************"<< endl;
cout<<"SIMPSON'S 1/3 METHOD"<< endl;
cout<<"*********************"<< endl;
 /* Calculation */
 stepSize = (upper - lower)/subInterval;

 /* Finding Integration Value */
 integration = f(lower) + f(upper);

 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;

  if(i%2==0)
  {
    integration = integration + 2 * (f(k));
  }
  else
  {
    integration = integration + 4 * (f(k));
  }

 }

 integration = integration * stepSize/3;

 cout<< endl <<"Required value of integration is: "<< integration <<endl<<endl;

 return 0;
}

