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
	
	char prog[1000];
	int sensen[10];
	int p[100][10];
	int *sen;
	
	//-------------------------------	
	read(0, prog, 1000);
	printf("%s", prog);
	//-------------------------------

	sen=p[0];
	sen[0] = 2;
	sen[1] = 1;
	sen[2] = 0;

	sen=p[1];
	sen[0] = 3;
	sen[1] = 2;
	sen[2] = 0;

	sen=p[2];
	sen[0] = 1;
	sen[1] = 0;
	sen[2] = 0;
	
	//-------------------------------
	
	for (j=0; j<30; j++) {
		var[j] = 0;
	}
	
	//Mirar esto que no es seguro
	var[0] = 1;
	
	while ( goagain==1 ) {
	
		for (j=0; j<30; j++) {
			varprev[j] = var[j];
		}
		
		//-------------------------------
		//if (a==1) b=1;
		sen=p[0];
		if (var[sen[1]] == 1)  
			//var[2]=1;
			var[sen[0]]=1;
	
		sen=p[1];
		if (var[sen[1]] == 1)  
			//var[2]=1;
			var[sen[0]]=1;
		
		sen=p[2];		
		if (var[sen[1]] == 1)  
			//var[2]=1;
			var[sen[0]]=1;
		//-------------------------------
		//if (b==1) c=1;
		//a=1;

		//-------------------------------

		printf("-------------------------a:%u b:%u c:%u \n",var[1],var[2],var[3]);
		
		goagain=0;
		for (j=0; j<30; j++) {
			if (var[j] != varprev[j]) goagain=1;
		}
	}	
	return 0;
}

