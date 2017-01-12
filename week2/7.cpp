
#ifdef JUDGE
#include <fstream>
std::ifstream cin("stacks.in");
std::ofstream cout("stacks.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

int main()
{
    int toHeightIncrement;
    int maxHeight;
    int nStacks;
    int p;

    int n;
    register int i;

    toHeightIncrement=0;
    maxHeight=0;
    nStacks=0;

    cin>>n;
    i=n-1;

    cin>>p;
    ++maxHeight;
    ++nStacks;

    while(i--)
    {
        cin>>p;
        if(p==0)
        {
            if(toHeightIncrement==0) {
                ++maxHeight;
                toHeightIncrement+=nStacks-1;
            }
            else
            {
                --toHeightIncrement;
            }
        }
        else {

            toHeightIncrement+=maxHeight-1;
            ++nStacks;
        }

    }

    cout<<maxHeight;
    return 0;
}

