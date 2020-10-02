#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){

    float accurateValue, approxValue, error;
    cout<<"Enter Accurate Value : ";
    cin>>accurateValue;
    cout<<"Enter Approx. Value : ";
    cin>>approxValue;
    error = fabs(accurateValue - approxValue);
    cout<<fixed<<setprecision(4);
    cout<<"Error \t\t\t: "<<error<<endl;
    error /= accurateValue;
    cout<<"Relative error \t\t: "<<error<<endl;
    error *= 100;
    cout<<fixed<<setprecision(2);
    cout<<"Percentage error \t: "<<error<<" %"<<endl;
    cout<"error";
    return 0;
}

