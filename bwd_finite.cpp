#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdlib.h>

using namespace std;

float roundoff(float value, unsigned char prec)
{
  float pow_10 = pow(10.0f, (float)prec);
  return round(value * pow_10) / pow_10;
}
int main()
{
 float x[20], y[20][20];
 int i,j, n, prec;
 int w=10;

 cout<<"Enter precision: ";
 cin>>prec;
 cout<< setprecision(prec)<< fixed;

 cout << "Enter number of data: ";
 cin >> n;
 cout << "Enter data: " << endl;
 for(i = 0; i < n ; i++)
 {
    cout << "x[" << i << "] = ";
    cin >> x[i];
    cout << "y[" << i <<"] = ";
    cin >> y[i][0];
 }

cout<<endl<<"*********************"<< endl;
cout<<"BACKWARD DIFFERENCE TABLE"<< endl;
cout<<"*********************"<< endl;
 for(i = 1; i < n; i++)
 {
  for(j = n-1; j > i-1; j--)
  {
    y[j][i] = roundoff(y[j][i-1] - y[j-1][i-1],prec); 
  }
 }

 /* Displaying Backward Difference Table */
//  cout << endl << "BACKWARD DIFFERENCE TABLE" << endl;
 for(i = 0; i < n; i++)
 {
  cout << x[i];
  for(j = 0; j <= i ; j++)
  {
   cout << "\t" << setw(w) << roundoff(y[i][j],prec);
  }
  cout << endl;
 }

 return 0;
}

