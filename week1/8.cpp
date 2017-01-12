//#define JUDGE 1

#ifdef JUDGE
#include <fstream>
std::ifstream cin("win.in");
std::ofstream cout("win.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<algorithm>

#define TIME 18000

int main() {

    unsigned n;
    cin>>n;
    unsigned times[15];
    unsigned sum;
    short unsigned count;

    for(register unsigned i=0;i<n;i++) {
        cin>>times[i];
    }

    std::sort(times, times+n);
    sum=0;
    count=0;
    for(register unsigned i=0;i<n;i++) {
        sum+=times[i];
        ++count;
        if(sum>TIME)
            {
                --count;
                break;
            }

    }

    cout<<count;

    return 0;
    }




