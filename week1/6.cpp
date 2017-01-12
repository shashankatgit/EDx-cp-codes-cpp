//#define JUDGE 1

#ifdef JUDGE
#include <fstream>
std::ifstream cin("template.in", std::ios::binary);
std::ofstream cout("template.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<cmath>
#include<algorithm>
#include<sstream>
#include<climits>

int mem[256][3]={0}; //dp whose keys shall be the ascii values
std::string a[102];
unsigned w,h;

int calc(char, char);

int main() {

    int tempScore, resScore=INT_MAX;
    int resLang=0;
    int lineCount;
    char prevC, curC,temp;
    std::string langs[3];
    std::string str;
    std::getline(cin, str);

    std::stringstream ss(str);
    ss >> w >> h>>temp;

    for(register int i=0;i<h;i++)
        {
            std::getline(cin, a[i]);
            //cout<<"Test1 "<<a[i]<<std::endl;
        }
    std::getline(cin, str);
    for(register int i=0;i<3;i++) //for 3 languages
    {
        tempScore=0;
        lineCount=0;



        std::getline(cin, langs[i], '\r');
        std::getline(cin,str);


        //cout<<i<<".. "<<langs[i]<<std::endl;

        while(true)
        {
            //cout<<"linecount = "<<lineCount<<std::endl;
            std::getline(cin, str);

            if(str[0]=='\r')
                break;

            //cout<<"2"<<str<<std::endl;

            register int x;

            if(lineCount==0)
                {
                    prevC = str[0];
                    x=1;
                }
            else
                {
                x=0;
                }
            int expSize;

            for(expSize=str.size()-1;x<expSize;x++)
            {
                curC = str[x];
                tempScore += calc(prevC, curC);
                //cout<<"x="<<x<<" and i="<<i<<" ,size="<<expSize<< " gaya"<<std::endl;
                prevC = curC;
            }

            ++lineCount;
        }

        //cout<<langs[i]<<"= "<<tempScore<<std::endl;
        if(tempScore<resScore)
        {
            resScore=tempScore;
            resLang=i;
        }


    }

    cout<<langs[resLang]<<std::endl;
    cout<<resScore;

    return 0;

}
int calc(char prevC, char curC)
{
    int hP,hC,wP,wC;
    bool flagP, flagC;
    flagP = false;
    flagC = false;

    //return 0 if a character has been repeated
    if(prevC == curC) return 0;

    //cout<<(int)prevC<<" - "<<prevC<<"memC:"<<mem[(int)prevC][0]<<std::endl;
    if(mem[(int)prevC][0]!=0)
        {
            //cout<<"ghusaC";
            wP=mem[(int)prevC][1];
            hP=mem[(int)prevC][2];
            flagP=true;
        }
    if(mem[(int)curC][0]!=0)
        {
            //cout<<"ghusaP";
            wC=mem[(int)curC][1];
            hC=mem[(int)curC][2];
            flagC=true;
        }

    for(register int i=0;i<h && !(flagC && flagP);i++)
    {
        for(register int j=0;j<w;j++)
            {
                //cout<<"M"<<a[i][j]<<std::endl;
                if(flagC && flagP)
                    break;
                else if(!flagP && a[i][j]==prevC) {
                    hP = i;
                    wP = j;
                    flagP=true;
                    //cout<<"foundC at "<<i<<", "<<j<<std::endl;
                }

                else if(!flagC && a[i][j]==curC) {
                    hC = i;
                    wC = j;

                    flagC = true;
                    //cout<<"foundP at "<<i<<", "<<j<<std::endl;
                }
            }
        }

       mem[(int)curC][0] = 1;
       mem[(int)curC][1] = wC;
       mem[(int)curC][2] = hC;

       mem[(int)prevC][0] = 1;
       mem[(int)prevC][1] = wP;
       mem[(int)prevC][2] = hP;

       int result = std::max(std::abs(hP-hC), std::abs(wP-wC));
//        int result = std::abs(hP-hC);
        //cout<<"Res"<<result;
        return result;

}





