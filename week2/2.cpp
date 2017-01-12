#ifdef JUDGE
#include <fstream>
std::ifstream cin("queue.in");
std::ofstream cout("queue.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<queue>


int main()
{
    int n;
    cin>>n;

    char a;
    int num;

    std::queue <int> q;
    for(register int i=0;i<n;++i)
    {

        cin>>a;
        if(a=='-'){
            cout<<q.front()<<"\n";
            q.pop();
            continue;
        }
        else{
            cin>>num;
            q.push(num);
        }
    }
 return 0;
}
