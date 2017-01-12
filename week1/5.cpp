#ifdef JUDGE
#include <fstream>
std::ifstream cin("chairs.in");
std::ofstream cout("chairs.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<climits>
#include<cmath>
#include<iomanip>


int main() {

    unsigned a,b,c; //the three sides of triangle

    cin>>a>>b>>c;

    double midL1,midL2,midL3;
    double avg;

    midL1 = (double)a/2;
    midL2 = (double)b/2;
    midL3 = (double)c/2;

    avg = (midL1 + midL2 + midL3)/3;

    cout<<std::setprecision(20);
    cout<<avg;

    return 0;

}
