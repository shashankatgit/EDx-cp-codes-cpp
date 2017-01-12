
#ifdef JUDGE
#include <fstream>
std::ifstream cin("brackets.in");
std::ofstream cout("brackets.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<stack>

int main()
{
    std::stack <char> s;
    char c;
    bool flag=true;

//    cin.get(c);
//    cout<<c;

    while(cin.get(c))
    {
        if(c=='\r')
            continue;
        if(c=='\n')
        {
            if(s.empty() && flag)
                cout<<"YES\n";

            else
                cout<<"NO\n";

            while(!s.empty()) //reinitializing things for next line
                s.pop();
            flag = true;

        }
        if(c=='[' || c=='(')
            s.push(c);

        else if(c==']')
        {
            if(s.empty()) {
                flag = false;
                //cout<<"1";
            }

            else if(s.top()=='[') {
                s.pop();
            }

            else {
                flag=false;
                //cout<<"2";
            }
        }

        else if(c==')')
        {
            if(s.empty()) {
                flag = false;
                //cout<<"3";
            }

            else if(s.top()=='(') {
                s.pop();
            }

            else {
                flag=false;
                //cout<<"4";
            }
        }


    }



 return 0;
}
