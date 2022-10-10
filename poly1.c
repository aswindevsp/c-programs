#include<stdio.h>
  struct poly
   {
     int coe;
     int exp;
   }a[10],b[10],c[10];
 int main()
  { 
    int d1,d2,i,k=0;
    
    printf("enter degree of first:");
    scanf("%d",&d1);
    for(i=0;i<=d1;i++)
    { 
  
      a[i].exp=i;
      printf("\nEnter coefficient of x^%d :",i);
     scanf("%d",&a[i].coe);
    
    }
    
    printf("enter degree of second:");
    scanf("%d",&d2);
    for(i=0;i<=d2;i++)
    {
     
     b[i].exp=i;
     printf("\nEnter coefficient of x^%d : ",i); 
     scanf("%d",&b[i].coe);
    }
   if(d1>d2)
       {
	 for(i=0;i<=d2;i++)
         {
     	   c[k].coe=a[i].coe+b[i].coe;
	   c[k].exp=a[i].exp;
	   k=k+1;
 	 }
         for(i=d2+1;i<=d1;i++)
         {
          c[k].coe=a[i].coe;
	  c[k].exp=a[i].exp; 
	 }
       }
   else
      {
        for(i=0;i<=d1;i++)
         {
     	   c[k].coe=a[i].coe+b[i].coe;
	   c[k].exp=a[i].exp;
	   k=k+1;
 	 }
         for(i=d1+1;i<=d2;i++)
         {
          c[k].coe=b[i].coe;
	  c[k].exp=b[i].exp; 
	 }
       }

   if(d1>d2)
     {
       for(i=0;i<=d1;i++)
        {
         
         printf("%dx^%d",c[i].coe,i);
         printf("+");
        }
     }
   else 
    {
     for(i=0;i<=d2;i++)
        {
         printf("%dx^%d",c[i].coe,i);
         printf("+");
        }
     }
  }
