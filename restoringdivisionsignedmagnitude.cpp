#include<stdio.h>
void displayBits(unsigned int value, int size)
{
	int i=0;
	for(i=0; i<16; i++){
		if(i<(16-size))
			value<<=1;
		else{
			putchar((value&0x8000)?'1':'0');
			value<<=1;
		//	if((i-1)%5==0) putchar(' ');
		}
	}
}

int main()
{
	int dividend =22;
	int divisor = 3;
	int accumulator=0;
	int quotient=0;
	int i;
	
	printf("dividend Q= "); displayBits(dividend,8);printf("\n");
	printf("divisor B= "); displayBits(divisor,4);printf("\t");	
	
	accumulator=(dividend & 0x00F0)>>4;
	
	accumulator = accumulator + ((~divisor+1)&0x0F);
	if(((accumulator&0x10)>>4)==1)  //Check E
	{	
		//E=1 A>B
		printf("%d\n",accumulator);
		printf("Divide Overflow");
		return 0;
	}
	//E=0 A<B
	accumulator = accumulator + (divisor&0x0F);
	quotient=(accumulator<<4)|(dividend&0x0F);
	printf("\nSC\t");printf("E A\tQ\t");printf("  Remarks");printf("\n");
	printf("4\t");displayBits(accumulator,5);printf("\t");displayBits(quotient,4); printf("\t Initialization");printf("\n");
	
	
	for(i=4;i>0;i--)
	{
	
		quotient = (quotient<<1); //Left Shift
		accumulator=(quotient>>4) & 0x001f; // Update Accumulator
		printf("%d\t",i-1);displayBits(accumulator,5);printf("\t");displayBits(quotient,4);printf("\tLeft Shift \n");
		
		if(((accumulator&0x10)>>4)==0)  //Check E
		{
			accumulator = accumulator + ((~divisor+1)&0x0F); //A+~B+1
			printf("%d\t",i-1);displayBits(accumulator,5);printf("\t");displayBits(quotient,4);printf("\tEA=A+B\'+1\n");
	
			if(((accumulator&0x10)>>4)==0)//Check E
			{
				//Restore A
				accumulator = accumulator + (divisor&0x0F);	
				printf("%d\t",i-1);displayBits(accumulator,5);printf("\t");displayBits(quotient,4);printf("\tRestore A\'+1\n");
			
			}
			else
			{
				quotient = quotient | 0x01; 
				printf("%d\t",i-1);displayBits(accumulator,5);printf("\t");displayBits(quotient,4);printf("\t Q0=1\n");
	
			}
		}
		else
		{
			accumulator=(quotient>>4) & 0x000f;
			accumulator = accumulator + ((~divisor+1)&0x0F);
			
			printf("%d\t",i-1);displayBits(accumulator,5);printf("\t");displayBits(quotient,4);printf("\tA=A+B\'+1\n");
			
			quotient = quotient | 0x01; 
			printf("%d\t",i-1);displayBits(accumulator,5);printf("\t");displayBits(quotient,4);printf("\t Q0=1\n");
	
		}
		quotient =(accumulator<<4)|(quotient&0x0F);

	}
	accumulator=(quotient>>4) & 0x000f;
	printf("Quotient: "); displayBits((quotient & 0xf),4);printf("\n");
	printf("Remainder: "); displayBits(accumulator,5);printf("\t");	
	
}
