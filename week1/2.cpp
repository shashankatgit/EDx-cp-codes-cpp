#ifdef JUDGE
#include <fstream>
std::ifstream cin("prepare.in");
std::ofstream cout("prepare.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<limits.h>

int main() {

    bool theory = false; //theory flag
    bool pract = false; //practice flag

    unsigned n;
    unsigned t[100];
    unsigned p[100];

    unsigned minDiffForT=UINT_MAX; //in case we have to choose at least one day
    unsigned minDiffForP=UINT_MAX; //in case we have to choose at least one day

    unsigned score =0;


    cin>>n;

    for(unsigned register i=0; i<n; i++)
        cin>>p[i];

    for(unsigned register i=0; i<n; i++)
        cin>>t[i];

    for(unsigned register i=0; i<n; i++){
        if((p[i]-t[i])<minDiffForP)
            minDiffForP = p[i]-t[i];
        if((t[i]-p[i])<minDiffForT)
            minDiffForT = t[i]-p[i];

        if(p[i]>t[i])
        {
            score+=p[i];
            theory=true;
        }
        else
        {
            score+=t[i];
            pract=true;
        }
    }

    if(!pract)
    {
        score = score - minDiffForT;
    }

    else if(!theory)
    {
        score = score - minDiffForP;
    }

    cout<<score;
    return 0;
}


