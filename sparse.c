#include<stdio.h>
  int main()
  {
   int r1,c1,i,j,n=0;
   printf("Enter row count :\n");
   scanf("%d",&r1);
   printf("Enter column count :\n");
   scanf("%d",&c1);
   printf("Enter elements :\n");
   int a[r1][c1];
   for(i=0;i<r1;i++)
   for(j=0;j<c1;j++)
    scanf("%d",&a[i][j]);

   for(i=0;i<r1;i++)
   {
    for(j=0;j<c1;j++)
    {
     if(a[i][j]!=0)
      n++;
    }
   }
 int b[n+1][3];
  b[0][0]=r1;
  b[0][1]=c1;
  int k=1;
   for(i=0;i<r1;i++)
   {
    for(j=0;j<c1;j++)
    {
     if(a[i][j]!=0)
      {
      b[k][0]=i;
      b[k][1]=j;
      b[k][2]=a[i][j];
      k++;
      }
    }
   }
 b[0][2]=n;

   printf("Sparse matrix is :\n");
  for(i=0;i<n+1;i++)
    {
   for(j=0;j<3;j++)
     {
     printf("%d\t",b[i][j]);
     }
     printf("\n");
    }

  

  }
   
   
      

   
    
