//#ifdef JUDGE
#include <fstream>
std::ifstream cin("template.in");
//std::ofstream cout("template.out");
//#else
#include <iostream>
//using std::cin;
using std::cout;
//#endif

int main()
{

    std::string tempLine;

     for(unsigned i=0;i<12;i++)
        {

//            if (!(getline(cin, tempLine))) { break; }
//            cin>>tempLine;

            std::getline(cin, tempLine);


            cout<<(int)tempLine[0]<<" "<<tempLine<<std::endl;

//            if(tempLine[0]=='\0' || tempLine[0]=='\n')
//                break;


        }

        return 0;

}
