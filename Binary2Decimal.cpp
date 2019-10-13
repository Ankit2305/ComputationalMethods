#include<iostream>
using namespace std;

int main(){
    string binary;
    long long int decimal = 0, base = 1;
    cout<<"Enter Binary Number : ";
    cin>>binary;
    for(int i = binary.size()-1 ; i >= 0; i--){
        decimal += base*(binary[i] - '0');
        base *= 2;
    }
    cout<<"Decimal representation of given binary is "<<decimal<<"\n";
    return 0;
}
