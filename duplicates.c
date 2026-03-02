#include<stdio.h>
int main()
{
int n,i,j,flag=0;
printf("Enter size:");
scanf("%d",&n);
int arr[n];
printf("Enter elements:");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(arr[i]==arr[j])
{
flag=1;
break;
}
}
if(flag==1)
break;
}
if(flag==1)
printf("Duplicates found");
else
printf("No duplicates");
return 0;
}
