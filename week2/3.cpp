#ifdef JUDGE
#include <fstream>
std::ifstream cin("queuemin.in");
std::ofstream cout("queuemin.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<stack>
#include<climits>


int main()
{
    std::stack <int> queuedStack;
    std::stack <int> pushStack;
    std::stack <int> minQueuedStack;

    register int n;
    char op;
    int operand;
    int topQueuedStack;
    int topPushStack;

    int pushStackMinVal = INT_MAX;
    int queuedStackMinVal = INT_MAX;
    int tempMinVal;

    cin>>n;

    while(n--)
    {
        cin>>op;
        if(op == '+') {
            cin>>operand;
            pushStack.push(operand);
            if(pushStackMinVal>operand)
                pushStackMinVal=operand;
        }

        if(op == '-') {

            if(queuedStack.empty()) {
                tempMinVal=INT_MAX;
                pushStackMinVal = INT_MAX; //since the push stack is gonna be empty it shouldnt have a minimum

                while(!pushStack.empty())
                {
                    topPushStack = pushStack.top();
                    queuedStack.push(topPushStack);
                    pushStack.pop();
                    if(topPushStack <= tempMinVal) {
                        minQueuedStack.push(topPushStack);
                    }
                }
            }

            topQueuedStack = queuedStack.top();
            //cout<<topQueuedStack<<"\n";
            queuedStack.pop();

            if(minQueuedStack.top() == topQueuedStack)
            {
                minQueuedStack.pop();
            }
        }

        if(op == '?') {
            if(!minQueuedStack.empty())
                tempMinVal = minQueuedStack.top();
            else
                tempMinVal = INT_MAX;
            if(pushStackMinVal > tempMinVal)
                cout<<tempMinVal<<"\n";

            else
                cout<<pushStackMinVal<<"\n";
        }

    }



return 0;
}
