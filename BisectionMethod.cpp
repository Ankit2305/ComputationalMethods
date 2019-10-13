#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define MAX 10

double coeff[MAX], expo[MAX];
int size = 0;

double f(double);
double bisection(double, double);

int main(){
    char choice;
    do{
        if(size == MAX){
            cout<<"\nMax size limit reached...";
            break;
        }
        cout<<"Enter exponent : ";
        cin>>expo[size];
        cout<<"Enter coefficient of x^"<<expo[size]<<" : ";
        cin>>coeff[size];
        size++;
        cout<<"Do you want to enter more terms? (y/n) ";
        cin>>choice;
    }while(choice != 'n' && choice != 'N');

    cout<<"\nf(n) = ";
    for(int i=0;i<size;i++){
        cout<<coeff[i]<<"x^"<<expo[i]<<" ";
        if(i != size-1 && coeff[i+1] >= 0 )
            cout<<"+ ";
    }
    cout<<"\n";

    double a = 0, b = 0, x1, x2 = -1, c = 0, d = 0, root;
    while(true){
        a = b;
        b = f(x2);
        if(b == 0){
            root = x2;
            break;
        }
        else if(a*b < 0){
            x1 = x2 - 1;
            root = bisection(x1, x2);
            break;
        }

        c = d;
        d = f(-x2);
        if(d == 0){
            root = -x2;
            break;
        }
        else if(c*d < 0){
            x1 = -x2 + 1;
            root = bisection(x1, -x2);
            break;
        }
        x2++;
    }
    cout<<fixed<<setprecision(4);
    cout<<"Root of the given equation is "<<root<<"\nf("<<root<<") = "<<f(root)<<"\n";
    return 0;
}


double f(double x){
    double val = 0;
    for(int i=0;i<size;i++){
        val += coeff[i]*pow(x, expo[i]);
    }
    return val;
}

double bisection(double x1, double x2){
    double fx1 = f(x1), fx2 = f(x2);
    double mid = (x1+x2)/2, fmid = f(mid);
    if(fabs(fmid) < 0.0001)
        return mid;
    if(fmid*fx1 > 0)
        return bisection(mid, x2);
    else
        return bisection(x1, mid);
}
