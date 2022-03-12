#include<stdio.h>
#define displayBits(x,n) for(int i=n;i>0;i--)putchar(((x>>i-1)&1)?'1':'0')

int main()
{
	unsigned int multiplicand = 15;
	unsigned int multiplier =11;
	unsigned int accumulator=0;
	unsigned int product=0;
	int i=4;
	
	printf("Multiplier: "); displayBits(multiplier,4);printf("\t");	
	printf("Multiplicand: "); displayBits(multiplicand,4);printf("\n");

	product=product| multiplier;
	printf("SC\t");printf("E A\tQ\t");printf(" Remarks");printf("\n");
	printf("4\t");displayBits(accumulator,5);printf(" ");displayBits(multiplier,4);printf("\t Initialization");printf("\n");
	
	while(i>0)
	{
		if(product & 0x01)  // Check LSB of Q
		{
			accumulator=accumulator + multiplicand;  //Add Multiplicand
			product=(product & 0xFF0F)|(accumulator<<4); //Update product EAQ, first clear accumulator bits then update
			printf("%d\t",i);displayBits(accumulator,5);printf(" ");displayBits(product,4);printf("\t A+M");printf("\n");
		}	
		product=product>>1; //Right Shift
		accumulator=(product>>4) & 0x000f; // Update Accumulator
		printf("%d\t",i);displayBits(accumulator,5);printf(" ");displayBits(product,4);printf("\t Shift Right");printf("\n");
		i--;
	}
	printf("%d\t",i);displayBits(accumulator,5);printf(" ");displayBits(product,4);printf("\t Product AQ");printf("\n");
		
}
