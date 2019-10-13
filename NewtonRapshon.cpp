#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define MAX 10

double coeff[MAX], expo[MAX], coeff_dash[MAX], expo_dash[MAX];
int size = 0, size_dash = 0;

double f(double);
double f_dash(double);
double newtonRapshon(double);
void diff();

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

    diff();

    cout<<"f'(n) = ";
    for(int i=0;i<size_dash;i++){
        cout<<coeff_dash[i]<<"x^"<<expo_dash[i]<<" ";
        if(i != size_dash-1 && coeff_dash[i+1] >= 0 )
            cout<<"+ ";
    }
    cout<<"\n\n";

    double root = newtonRapshon(0);

    cout<<fixed<<setprecision(4);
    cout<<"Root of the given equation is "<<root<<"\nf("<<root<<") = "<<f(root)<<"\n";
    return 0;
}

void diff(){
    for(int i=0;i<size;i++){
        if(expo[i] != 0){
            coeff_dash[size_dash] = coeff[i]*expo[i];
            expo_dash[size_dash] = expo[i] - 1;
            size_dash++;
        }
    }
}

double f(double x){
    double val = 0;
    for(int i=0;i<size;i++){
        val += coeff[i]*pow(x, expo[i]);
    }
    return val;
}

double f_dash(double x){
    double val = 0;
    for(int i=0;i<size_dash;i++){
        val += coeff_dash[i]*pow(x, expo_dash[i]);
    }
    return val;
}

double newtonRapshon(double x0){
    double fx0 = f(x0), fdashx0 = f_dash(x0);
    if(fabs(fx0) < 0.00001)
        return x0;
    if(fdashx0 == 0)
        newtonRapshon(x0 + 0.00001);
    double x1 = x0 - (fx0 / fdashx0);
    return newtonRapshon(x1);
}
