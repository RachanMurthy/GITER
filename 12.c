#include<stdio.h>
struct trans
{
 char pn[50];
 int pid,quan,tid;
};
int main()
{
    int n,i,j;
    printf("enter number of transactions");
    scanf( "%d",&n);
    struct trans a[n],temp;
    printf("enter product name,id,quantity,tid");
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d%d",&a[i].pn,&a[i].pid,&a[i].quan,&a[i].tid);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0; j<n-1-i;j++)
    {
        if(a[i].quan>a[j+1].quan)
    {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
    }
    }    
    }
    printf("sorted transactions are");
    for(i=0;i<n;i++)
{
    printf("product name = %s, pid=%d, quantity=%d,tid=%d\n",a[i].pn,a[i].pid,a[i].quan,a[i].tid);
}
return 0;
}
