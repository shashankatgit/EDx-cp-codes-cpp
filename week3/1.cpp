#ifdef JUDGE
#include <fstream>
std::ifstream cin("sort.in");
std::ofstream cout("sort.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

void mergeSort(int*, int l, int u);
void merge(int*, int l, int m,int u);

int main()
{
 int n;
 register int i;

 cin>>n;

 int array[100001];

 for(i=1; i<=n; ++i)
 {
    cin>>array[i];
 }

 mergeSort(array,1,n);

 for(i=1;i<=n;++i)
 {
    cout<<array[i]<<" ";
 }

 return 0;

}


void mergeSort(int *a, int l, int u)
{
    if(l<u)
    {
        int m = l + (u-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1,u);

        merge(a,l,m,u);
        cout<<l<<" "<<u<<" "<<a[l]<<" "<<a[u]<<"\n";
    }

    else if(l==u)
        cout<<l<<" "<<u<<" "<<a[l]<<" "<<a[u]<<"\n";

}


void merge(int* a, int l, int m,int u)
{
    int n1 = m-l+1;
    int n2 = u-m;
    int n = u-l+1;

    int copy1[n1];
    int copy2[1+n2];
    register int i,j,k;

    for(i=0;i<n1;++i)
        copy1[i] = a[l+i];
    for(i=0;i<n2;++i)
        copy2[i] = a[m+1+i];

    j=k=0;
    i=l;
    while(j<n1 && k<n2)
    {
        if(copy1[j]<copy2[k])
            a[i++] = copy1[j++];
        else
            a[i++] = copy2[k++];
    }

    for( ;j<n1;++j)
        a[i++] = copy1[j];
    for( ; k<n2; ++k)
        a[i++] = copy2[k];
}
