#ifdef JUDGE
#include <fstream>
std::ifstream cin("stack.in");
std::ofstream cout("stack.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<stack>


int main()
{
    int n;
    cin>>n;

    char a;
    int num;

    std::stack <int> s;
    for(register int i=0;i<n;++i)
    {

        cin>>a;
        if(a=='-'){
            cout<<s.top()<<"\n";
            s.pop();
            continue;
        }
        else{
            cin>>num;
            s.push(num);
        }
    }
 return 0;
}
