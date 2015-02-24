//Hai que buscar na sentencia aquelas que sexan 0


#include <stdio.h>
#include <stdlib.h>

int syntaxerror(int e, int n){
    printf ("Sintax Error: %u _line: %u \n", e,n);
	exit(0);
}

 
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
	int queryvar;
	char querychar[1];
	char prog[1000];
	int sensen[10];
	int p[100][10];
	int *sen;
	
	int cond;
 
	
	if(argv[1][0] <=96 || argv[1][0] >=96+30){
	    printf("\n No valid query %s \n",argv[1] );
	}  else {
	    queryvar= argv[1][0] -96; 
	}
	
	//-------------------------------	
	read(0, prog, 1000);
	printf("%s", prog);
	//-------------------------------
	
	i=0; // File
	j=0; // Compile
	sen=p[j];

    //-------------------------------
    // Parseador
    //-------------------------------
	while (prog[i] != 0) {
		sen[0]=0;
	
		if ( (prog[i+0] <= 96) || (prog[i+0] >= (96+30))){
		    syntaxerror(0,i);
		} else
			sen[0]=prog[i+0]-96;

		if (prog[i+1] != ':') {
            syntaxerror(1,i);
		}
		 
		if (prog[i+2] != '-') {
		  syntaxerror(2,i);
		}

		if (prog[i+3] == '.') sen[1]=0; //Fin de sentencia
		else {
		    int condmore = 1; //Hai máis condicións
		    int c = i+3;
		    int e = 1;
		    while(condmore){
               if ( (prog[c] <= 96) || (prog[c] >= (96+30))){ //Es una letra?
			      syntaxerror(3,i);
			    } 
                else {
                    sen[1]=prog[c]-96;
                    //Hai unha coma?
                    if (prog[c+1] != ','){
                        condmore=0;
                    }
                }		    
		        e++;
		    }
			sen[e+1]=0; //Chegamos ao final da sentencia e pon un cero
		}
		if (prog[i+4]!='\n') {
		    syntaxerror(4,i);
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
	//Inicializacion de variables

	for (j=0; j<30; j++) {
		var[j] = 0;
	}
	//-------------------------------
	//PROGRAM EXEC
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
			cond = 1; // var[sen[0]] = 1;
			j = 1; //Posición inicial onde empeza a sentencia // esto es un test newvar = sen[0]
			while (sen[j] != 0)
			{
				if (var[sen[j]] == 0) {
					//printf("\n%c %u %u",(char)(sen[j]+96), var[sen[j]], varprev[sen[j]]);
					
					cond = 0; //var[sen[0]] = 0;
				}
				j++;
			}
			if (cond) //Se a condición se cumple facemos a variable igual = 1
				var[sen[0]] = 1;
			i++;
			sen=p[i]; //Collemos a seguinte sentencia
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

