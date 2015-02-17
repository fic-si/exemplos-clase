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
	
	int assigntmp;
	
	//-------------------------------	
	read(0, prog, 1000);
	printf("%s", prog);
	//-------------------------------
	
	i=0; // File
	j=0; // Compile
	
	sen=p[j];
	while (prog[i] != 0) {
		sen[0]=0;
	
		if ( (prog[i+0] <= 96) || (prog[i+0] >= (96+30))){
		 printf ("Sintax Error line 1\n");
		 return;
		} else
			sen[0]=prog[i+0]-96;

		if (prog[i+1] != ':') {
		 printf ("Sintax Error line 1\n");
		 return;
		}
		 
		if (prog[i+2] != '-') {
		 printf ("Sintax Error line 1\n");
		 return;
		}
	
		if (prog[i+3] == '.') sen[1]=0; //Fin de sentencia
		else {
			if ( (prog[i+3] <= 96) || (prog[i+3] >= (96+30))){
			 printf ("Sintax Error line 1\n");
			 return;
			} else
				sen[1]=prog[i+3]-96;
			
			sen[2]=0;
		}
		if (prog[i+4]!='\n') {
			printf ("Sintax Error line 1\n");
			return;
		}
		else i = i+5;
		j++;
		sen=p[j];	
	}
	// Fin del programa

	sen[0] = 0;
	
	//-------------------------------
	/*
	sen=p[0];
	sen[0] = 2;
	sen[1] = 4;
	sen[2] = 0;

	sen=p[1];
	sen[0] = 3;
	sen[1] = 0;
	sen[2] = 0;

	sen=p[2];
	sen[0] = 5;
	sen[1] = 3;
	sen[2] = 0;
	
	sen=p[3];
	sen[0] = 3;
	sen[1] = 6;
	sen[2] = 2;
	sen[3] = 0;
		
	sen=p[4];
	sen[0] = 0; // Fin del programa
	*/

	//-------------------------------
	//PRINT COMPILED PROGRAM
	
	i = 0;
	sen = p[i];
	while (sen[0] != 0)
	{
		var[sen[0]] = 1;
		printf ("\n%c :-", (char)(sen[0] + 96));
		j = 1;
		while (sen[j] != 0)
		{
			printf ("%c ", (char)(sen[j] + 96));
			j++;
		}
			i++;
			sen=p[i];
	}
	
	//-------------------------------
	
	//PROGRAM EXEC
	for (j=0; j<30; j++) {
		var[j] = 0;
	}
	
	while ( goagain==1 ) {
	
		for (j=0; j<30; j++) {
			varprev[j] = var[j];
		}
		
		//-------------------------------
		//if (a==1) b=1;
		i = 0;
		sen = p[i];
		while (sen[0] != 0)
		{
			assigntmp = 1; // var[sen[0]] = 1;
			j = 1;
			while (sen[j] != 0)
			{
				if (var[sen[j]] == 0) {
					//printf("\n%c %u %u",(char)(sen[j]+96), var[sen[j]], varprev[sen[j]]);
					
					assigntmp = 0; //var[sen[0]] = 0;
				}
				j++;
			}
			if (assigntmp && var[sen[0]] == 0) 
				var[sen[0]] = 1;
			i++;
			sen=p[i];
		}
		
		//-------------------------------
		//if (b==1) c=1;
		//a=1;

		//-------------------------------
		printf("\nRESULT\n");
		for (i=1;i<30;i++)
		{
			if (var[i]==1)
				printf("%c ",(char)(i+96));
				
		}
		//printf("\n-----a:%u b:%u c:%u d:%u e:%u \n",var[1],var[2],var[3], var[4], var[5]);
		
		printf("\n");
		
		//-------------------------------
		goagain=0;
		for (j=0; j<30; j++) {
			if (var[j] != varprev[j]) goagain=1;
		}
	}	
	return 0;
}

