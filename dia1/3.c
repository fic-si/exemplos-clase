#include <stdio.h>
 
int main (int argc,char **argv)
{
	int a=0;
	int b=0;
	int c=0;
	
	int var[30];
	int varprev[30];

	int i=0;
	int j=0;
	int goagain=1;
	
	for (j=0; j<30; j++) {
		var[j] = 0;
	}
	
	while ( goagain==1 ) {
	
		for (j=0; j<30; j++) {
			varprev[j] = var[j];
		}
		
		if (b==1) c=1;
		if (a==1) b=1;
		a=1;

		printf("a:%u b:%u c:%u \n",a,b,c);
		var[1]=a;
		var[2]=b;
		var[3]=c;
		
		goagain=0;
		for (j=0; j<30; j++) {
			if (var[j] != varprev[j]) goagain=1;
		}
	}	
	return 0;
}

