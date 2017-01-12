#ifdef JUDGE
#include <fstream>
std::ifstream cin("inversions.in");
std::ofstream cout("inversions.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

long long int mergeSort(int*, int l, int u);
long long int merge(int*, int l, int m,int u);



int main()
{
 int n;
 register int i;
 long long int inversions;

 cin>>n;

 int array[100001];

 for(i=1; i<=n; ++i)
 {
    cin>>array[i];
 }


 inversions = mergeSort(array,1,n);

// for(i=1;i<=n;++i)
// {
//    cout<<array[i]<<" ";
// }

 cout<<inversions;
 return 0;

}


long long int mergeSort(int *a, int l, int u)
{
    if(l<u)
    {
        int m = l + (u-l)/2;
        long long int invCount1, invCount2;
        invCount1 = mergeSort(a, l, m);
        invCount2 = mergeSort(a, m+1,u);

        return (invCount1 + invCount2 + merge(a,l,m,u));

    }

    else
        return 0;
}


long long int merge(int* a, int l, int m,int u)
{

    int n1 = m-l+1;
    int n2 = u-m;
    int n = u-l+1;

    long long int inversions=0;

    int copy1[n1];
    int copy2[1+n2];
    register int i,j,k;

    for(i=0;i<n1;++i)
        copy1[i] = a[l+i];
    for(i=0;i<n2;++i)
        copy2[i] = a[m+1+i];



//     for(i=1;i<=10;++i)
//     {
//        cout<<a[i]<<" ";
//     }
//    cout<<"\n";

    j=k=0;
    i=l;
    while(j<n1 && k<n2)
    {
        if(copy1[j]<=copy2[k])
            a[i++] = copy1[j++];
        else
        {
//            cout<<"old inv = "<<inversions<<" | index = "<<l+j<<", "<<m+k+1<<"| value = "<<copy1[j]<<", "<<copy2[k]<<"\n";
//            cout<<"l="<<l<<", m="<<m<<", j="<<j<<"\n";
            inversions+= n1-j;
            a[i++] = copy2[k++];
        }
    }

    for( ;j<n1;++j)
        {
            a[i++] = copy1[j];
        }
    for( ; k<n2; ++k)
        a[i++] = copy2[k];

//    cout<<"inv = "<<inversions<<"\n\n";
    return inversions;
}
