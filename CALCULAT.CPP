#include<stdio.h>
#include<conio.h>
#include<iostream.h>

int main()
{
	char op;
	float num1,num2;
	clrscr();

	cout<<"enter operators(+,-,*,/):";
	cin>>op;

	cout<<"enter two numbers: ";
	cin>>num1>>num2;

	switch(op)
	{
		case'+':
		     cout<<"result= "<<num1+num2;
		     break;

		case'-':
		     cout<<"result= "<<num1-num2;
		     break;

		case'*':
		     cout<<"result= "<<num1*num2;
		     break;

		case'/':
		     if(num2 !=0)
			 cout<<"result= "<<num1/num2;
		     else
			 cout<<"error!division by zero.";
		     break;

		default:
		     cout<<"invalid operator!";
	}
	getch();
	return 0;
}
