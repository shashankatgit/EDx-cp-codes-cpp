#ifdef JUDGE
#include <fstream>
std::ifstream cin("team.in");
std::ofstream cout("team.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<climits>
#include<cmath>
#include<iomanip>

unsigned int a[3][3];

double calc2();

int main() {


 for(unsigned i=0;i<3;i++)
    for(unsigned j=0;j<3;j++)
        cin>>a[i][j];

 double result = calc2();

 cout<<std::setprecision(15);
 cout<<result;
 return 0;
}

double calc2(){

 double result=0;
 double temp;
 unsigned x,y,z;
 for(unsigned i=0;i<3;i++)
    for(unsigned j=0;j<3;j++)
        for(unsigned k=0;k<3;k++)
            if(i!=j && j!=k && i!=k){
                //cout<<a[i][0]<<" "<<a[j][1]<<" "<<a[k][2]<<std::endl;
                temp = sqrt(a[i][0]*a[i][0]+a[j][1]*a[j][1] + a[k][2]*a[k][2]);
                if(temp > result)
                    result = temp;
            }


 return result;
}

//double calc(){
//
// double result=0;
// double temp;
// for(unsigned i=0;i<3;i++)
//    for(unsigned j=0;j<2;j++)
//    {
//        cout<<a[i][0]<<" "<<a[(i+j+1)%3][1]<<" "<<a[(i+j+2)%3][2]<<std::endl;
//        temp = sqrt(a[i][0]*a[i][0]+a[(i+j+1)%3][1]*a[(i+j+1)%3][1]+a[(i+j+2)%3][2]*a[(i+j+2)%3][2]);
//
//
//        if(temp > result)
//            result = temp;
//    }
//
// return temp;
//}


