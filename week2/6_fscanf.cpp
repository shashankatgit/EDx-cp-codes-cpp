
#ifdef JUDGE
#include <fstream>
std::ifstream cin("snowmen.in");
std::ofstream cout("snowmen.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include<stdlib.h>
#include<stdio.h>

typedef struct Snowman
{
    int parent;
    int size;
    short int top;  //what operation was done on parent to make this snowman, 0 means top ball removed else means the weight of addl ball
    int height;
};

int main()
{

 Snowman *s[1000001]; // 0=>parent, 1=>size

 int n;

 register int i,j;
 FILE *f = fopen("snowmen.in", "r");

 fscanf(f,"%d",&n);
 int id,add;
 long long int sum=0;

 s[0] = (Snowman *)malloc(sizeof(Snowman));
 s[0]->parent=-1;
 s[0]->size=0;
 s[0]->top=0;
 s[0]->height=0;

 int topRemovedHeight;

 for(i=1; i<=n; i++)
 {
    s[i] = (Snowman *)malloc(sizeof(Snowman));
    fscanf(f, "%d %d", &id, &add); //id refers to id of the parent snowman
    //cout<<"i="<<i<<"\n";
    if(add == 0) {

        s[i]->parent = id;
        s[i]->size = s[id]->size - s[id]->top;
        sum+=s[i]->size;
        s[i]->height = s[id]->height - 1;

        j=s[id]->parent;
        topRemovedHeight = s[id]->height - 1;

        while(s[j]->height != topRemovedHeight && j!=0) //searching for the snowman whose height is 1 less than the parent
        {
            j=s[j]->parent;
        }
        //cout<<"top of this snowman is "<<s[j]->top<<"\n";
        s[i]->top=s[j]->top;
        s[i]->parent = j;
    }

    else {
        s[i]->parent = id;
        s[i]->height = s[id]->height + 1;
        s[i]->size = s[id]->size + add;
        s[i]->top = add;
        sum+=s[i]->size;
        //cout<<"height of this snowman is "<<s[i]->height<<"\n";
    }
   //cout<<"\n\n";

 }


 //cout<<"sum is "<<sum;
 cout<<sum;
 return 0;
}

