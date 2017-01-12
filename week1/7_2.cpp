//#define JUDGE 1

//#ifdef JUDGE
#include <fstream>
//std::ifstream cin("testgen.in");
std::ofstream cout("testgen.out");
//#else
#include <iostream>
using std::cin;
//using std::cout;
//#endif

#include<algorithm>
#include<cmath>

#define PRIME_N 20

unsigned int primes[PRIME_N]=
                        {2,3,5,7,11,13,17,19,23,29,
                        31,37,41,43,47,53,59,61,67,71}; //we shall compute the first 15 primes as more than that shall not be needed

int main()
{
    unsigned n;
    unsigned count=0;

    unsigned maxDivCount=0;
    unsigned numMax;

    unsigned tempDivCount;
    unsigned tempDivisor;
    unsigned tempVar;

    unsigned powerPrimes[PRIME_N];


    n=10000001;

    register unsigned i,j;

    for(i=2;i<=n;++i)
    {
        //cout<<"checking for "<<i<<std::endl;

        tempVar=i;
        for(j=0;j<PRIME_N && (tempDivisor=primes[j])<=i && tempVar!=1;j++)
        {
            tempDivCount=0;
            while(tempVar!=1 && tempVar%tempDivisor == 0)
            {
                ++tempDivCount;
                tempVar/=tempDivisor;
                //cout<<"div by "<<tempDivisor<<" incrementing by 1"<<std::endl;
            }
            powerPrimes[j]=tempDivCount;
        }

        tempDivCount=1;
        for(unsigned k=0;k<j;k++)
        {
            //cout<<"multip by "<<powerPrimes[k]+1<<std::endl;
            tempDivCount*=(powerPrimes[k]+1);
        }

        if(tempDivCount>maxDivCount)
            {
            maxDivCount = tempDivCount;
            numMax = i;

            cout<<numMax<<", ";

           // cout<<"temporary maximum found which is "<<tempDivCount<<std::endl;
            }
        //cout<<"Total divisors: "<<tempDivCount<<std::endl;
        //cout<<std::endl;
    }

    //cout<<numMax<<std::endl;
    //cout<<n-numMax+1;

return 0;
}
