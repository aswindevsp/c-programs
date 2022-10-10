#include <stdio.h>
struct poly {
	int coeff;
	int expo;
}a[10], b[10], c[10];

int main() {
	int deg1, deg2;
	printf("Enter the max degree of poly 1: ");
	scanf("%d", &deg1);
	for(int i=0; i<=deg1; i++) {
		printf("Enter the coeff of x^%d: " , i);
		scanf("%d", &a[i].coeff);
		a[i].expo = i;
	}
	
	printf("Enter the max degree of poly 2: ");
	scanf("%d", &deg2);
	for(int i=0; i<=deg2; i++) {
		printf("Enter the coeff of x^%d: " , i);
		scanf("%d", &b[i].coeff);
		b[i].expo = i;
	}
	
	int k=0,i;
		if(deg1>deg2)
		{
			for(i=0;i<=deg2;i++)
			{
				c[k].coeff=a[i].coeff+b[i].coeff;
				c[k].expo=a[i].expo;
				k++;
			}
			for(i=deg2+1;i<=deg1;i++)
			{
				c[k].coeff=a[i].coeff;
				c[k].expo=a[i].expo;
				k++;
			}
		}
		else
		{
			for(i=0;i<=deg1;i++)
			{
				c[k].coeff=a[i].coeff+b[i].coeff;
				c[k].expo=b[i].expo;
				k++;
			}
			for(i=deg1+1;i<=deg2;i++)
			{
				c[k].coeff=b[i].coeff;
				c[k].expo=b[i].expo;
				k++;
			}
		}
		
		
		
	
	
	int max;
	if(deg2 > deg1){
		max = deg2;
	} else {
		max = deg1;
	}
	
	
	for(int i=max; i>=0; i--) {
		printf("%dx^%d ", c[i].coeff, i);
	}
	
	
	



	

	
	
}
