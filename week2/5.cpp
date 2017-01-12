
#ifdef JUDGE
#include <fstream>
std::ifstream cin("postfix.in");
std::ofstream cout("postfix.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<stack>

int valueOf(int a, int b, char op)
{
    switch(op)
    {
        case '*'    : return a*b;
        case '+'    : return a+b;
        case '-'    : return a-b;
        default     : return 0; //invalid operator
    }
}

bool isOperator(char op)
{
    switch(op)
    {
        case '*'    : return true;
        case '+'    : return true;
        case '-'    : return true;
        default     : return false; //invalid operator
    }
}

int main()
{
 char c;
 char input[2];
 std::stack <int> operandStack;

 int a,b,res;

 while(cin.get(c))
    {
        //cout<<c<<"s";
        if(c=='\r' || c==' ') //for compatibility on linux system
            continue;
        if(c=='\n')
        {
           break;
        }


        if(!isOperator(c))
            {
                operandStack.push(c-(int)'0');
                res = c-(int)'0';
                //cout<<c-(int)'0'<<"gg";
            }

        else
            {
                b=operandStack.top();
                operandStack.pop();
                a=operandStack.top();
                operandStack.pop();

                res = valueOf(a,b,c);
                //cout<<res<<"\n";
                operandStack.push(res);
            }

    }

    cout<<res;

 return 0;
}
