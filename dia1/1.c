#include <stdio.h>
 
int main (int argc,char **argv)
{
	int a=0;
	int b=0;
	int c=0;
	int i=0;
	for ( i; i< 10; i++) {
		if (a==1) b=1;
		if (b==1) c=1;
		a=1;
		printf("a:%u b:%u c:%u \n",a,b,c);
	}	
	return 0;
}

