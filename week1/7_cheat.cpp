//#define JUDGE 1

#ifdef JUDGE
#include <fstream>
std::ifstream cin("testgen.in");
std::ofstream cout("testgen.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<algorithm>
#include<cmath>

#define PRIME_N 20

unsigned cheatsheet[]={
    2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720,
    840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160,
    25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320,
     221760, 277200, 332640, 498960, 554400, 665280, 720720,
     1081080, 1441440, 2162160, 2882880, 3603600, 4324320,
     6486480, 7207200, 8648640
};

#define SHEETCOUNT 46

int main()
{

    unsigned n;
    cin>>n;

    unsigned val;

    for(register unsigned i=0;i<SHEETCOUNT;++i)
    {
        val=cheatsheet[i];
        if(val>n)
        {
            val=cheatsheet[i-1];
            break;
        }

        if(val==n)
        {
            break;
        }
    }

    //cout<<"val = "<<val<<std::endl;
       // cout<<val<<std::endl;
        cout<<n-val+1;



return 0;
}
