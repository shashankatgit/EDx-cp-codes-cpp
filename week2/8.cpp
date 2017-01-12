
#ifdef JUDGE
#include <fstream>
//std::ifstream cin("kenobi.in");
std::ofstream cout("kenobi.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<cstdlib>
#include<cstdio>

typedef struct Saber
{
    int id;
    Saber* next;
    Saber* prev;
};


void printSabers(Saber*);

int main()
{
 FILE *f = fopen("kenobi.in","r");
 Saber *startSaber;
 Saber *endSaber;
 Saber *midSaber;
 Saber *newSaber;
 Saber *endOfLeftChain;
 Saber *startOfLeftChain;


 char command[6];
 int id;

 startSaber=NULL;
 endSaber=startSaber;
 midSaber=NULL;

 int n;
 int count=0;
 fscanf(f,"%d",&n);
 register int i;
 i=n;

 while(i--)
 {
    fscanf(f,"%s",command);

    if(command[0]=='t') //take a saber
    {
        newSaber = endSaber;
        endSaber = endSaber->prev;
        --count;
        if(endSaber == NULL)
            {
                startSaber = NULL;
                midSaber = NULL;
            }

        else
            {
                endSaber->next = NULL;
                if(count&1==1) //if total saber count is odd
                {
                    //cout<<"gaya";
                    midSaber = midSaber->prev;
                }
            }

        free(newSaber);
        //cout<<count;
    }

    else if(command[0]=='a') //add a saber
    {
        fscanf(f,"%d",&id);
        newSaber = (Saber *)malloc(sizeof(Saber));
        newSaber->id = id;
        newSaber->next = NULL;
        ++count;

        if(startSaber==NULL) //no saber was there
        {
            startSaber = newSaber;
            endSaber = startSaber;
            startSaber->prev=NULL;
            midSaber=NULL;
        }
        else //simply add to right of existing sabers
        {
            newSaber->prev = endSaber;
            endSaber->next = newSaber;
            endSaber = newSaber;
            if(count%2==0) //if total saber count is even
            {
                if(midSaber==NULL)
                    midSaber=startSaber;
                else
                    midSaber= midSaber->next;
            }
        }




    }

    else //mum came
    {
        if(midSaber!=NULL)
        {
            endOfLeftChain = midSaber;
            startOfLeftChain = startSaber;

            startSaber = midSaber->next;
            endSaber->next = startOfLeftChain;
            startOfLeftChain->prev = endSaber;

            if(count%2==0)
                midSaber = endSaber;
            else
                midSaber = endSaber->prev;

            endSaber = endOfLeftChain;
            endSaber->next = NULL;
        }
    }

//    cout<<"List is : ";
//    printSabers(startSaber);
//    if(midSaber!=NULL)
//    cout<<"\nMid is "<<midSaber->id<<"\n\n";
 }

 cout<<count<<"\n";
 printSabers(startSaber);


return 0;
}

void printSabers(Saber *start)
{
    while(start != NULL)
    {
        cout<<start->id<<" ";
        start=start->next;
    }
}
