#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double x[], int y, double z[]){
//ค่าเฉลี่ยเลขคณิต (Arithmetic Mean)
    double sum = 0;
    for (int i = 0; i < y; i++)
    {
        sum += x[i]; 
    }
    z[0] = sum/y;

//ส่วนเบี่ยงเบนมาตรฐาน (Standard Deviation)
    double sum2 = 0;
    for (int i = 0; i < y; i++)
    {
        sum2 += pow(x[i],2);
        
    }
    z[1] = sqrt((sum2/y)-(pow(z[0],2)));
    
//ค่าเฉลี่ยเรขาคณิต (Geometric Mean)
    double gm = 1.0;
    for (int i = 0; i < y; i++)
    {
        gm *= x[i];
        
    }
    z[2] = pow(gm,(double)1/y);


//ค่าเฉลี่ยฮาร์โมนิก (Harmonic Mean)  
     double hm = 0;
     for (int i = 0; i < y; i++)
     {
         hm += 1/x[i];   
     }
    z[3] = y/hm;

//ค่าสูงสุด (Max) และค่าต่ำสุด (Min) ของ Array
    double max = x[0], min = x[0];
    for (int i = 0; i < y; i++)
    {
        
        if (x[i]> max) max = x[i];
    
        if (min > x[i]) min = x[i];
        
    }
    z[4] = max;
    z[5] = min;
}