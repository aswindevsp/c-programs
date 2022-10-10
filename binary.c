#include<stdio.h>
 int main()
 {
  
   int n;
   printf("Enter limit \n");
   scanf("%d",&n);
   int ar[n];
   printf("Enter elements\n");
   for(int i=0;i<n;i++)
   scanf("%d",&ar[i]);
   printf("Entered elements are\n");
  for(int i=0;i<n;i++)
   printf("%d\n",ar[i]);
 
  int l=0,u=n-1,flag=0,a,mid;

 
   printf("Enter search element\n");
  scanf("%d",&a);
  

  while(flag!=1 && l<=u )
   {
      mid=(l+u)/2;

     if(a==ar[mid])
      {
      flag=1;
      printf("Found at position:%d",mid+1);
      }
     if(a<ar[mid])
       u=mid-1;
     else
       l=mid+1;
   }
  if(flag==0)
  printf("not found");

  }
   
