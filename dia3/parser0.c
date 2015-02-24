#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
	int num_bytes=0;
	
	int var[30];
	int varprev[30];

	int i=0;
	int j=0;
	int e=0;
	//int c=0;
	int condmore=0;
	int condtmp=0;
	int goagain=1;
	
	char prog[1000];
	char *progtmp;
	char *progtmptmp;
	int sensen[10];
	int p[100][10];
	int *sen;

int syntaxerror(int e,int n){
	printf("\nSyntax error %u: line %u >%s<",e,n+1,progtmp);
	
}

int main (int argc,char **argv)
{
	
	//-------------------------------
	num_bytes=read(0, prog, 1000);
	//printf("%s", prog,num_bytes);
	//-------------------------------
	i=0;	//file
	j=0;	//compile
	sen=p[j];
	progtmp=prog;
	
	while(*progtmp!=0)
	{
		sen[0]=0;
		if((*progtmp<=96) || (*progtmp>=96+30))
		{
			syntaxerror(0,j);
			return;
		}
		else
			sen[0]= *progtmp-96;
		progtmp++;
		if(*progtmp!=':')
		{
			syntaxerror(1,j);
			return;
		}
		progtmp++;
		if(*progtmp!='-')
		{
			syntaxerror(1,j);
			return;
		}
		
		condmore=1;
		//c=i+3;
		e=1;
		progtmp++;	
		if (*progtmp=='.')
		{
			sen[1]=0; //fin de sentencia
			//c++;
		}
		else
		{
			while(condmore)
			{
				if((*progtmp<=96) || (*progtmp>=96+30))
				{
					syntaxerror(2,j);
					return;
				}
				else
				{
					
					sen[e]= *progtmp-96;
					progtmp++;
					if (*progtmp!=',')
					{
						condmore=0;
						if(*progtmp!='.')
						{
							syntaxerror(19,j);
							return;
						}
						progtmp++;						
					}
										
				}
				e++;
			}
			sen[e+1]=0;

		}
		//i=c+1;
		//if(prog[i]!='\n')
		progtmptmp=strchr(progtmp,'\n');
		if (progtmptmp==NULL)
		{
			syntaxerror(10,j);
			return;
		}
		else
		{
			progtmp=progtmptmp;
			progtmp++;
		}
		j++;
		sen=p[j];
	}	
	//fin del programa
	//sen=p[1];			//Solo leemos una linea por eso al comenzar la siguiente linea ponemos un cero 
	//sen[0]=0;			//para forzar la salida del while
	//-------------------------------
	
/*	sen=p[0];
	sen[0] = 2;
	sen[1] = 4;
	sen[2] = 0;

	sen=p[1];
	sen[0] = 3;
	sen[1] = 0;
	sen[2] = 0;

	sen=p[2];
	sen[0] = 4;
	sen[1] = 0;
	sen[2] = 0;
	
	sen=p[3];
	sen[0] = 3;
	sen[1] = 5;
	sen[2] = 2;
	sen[3] = 0;
	
	sen=p[4];
	sen[0] = 0; // fin del programa
*/	
	
	//-------------------------------
	//print compiled program
	i=0;
	sen=p[i];
	while (sen[0]!=0)
	{
		var[sen[0]]=1;
		printf("%u",(sen[0]));
		j=1;
		while (sen[j] !=0)
		{
			printf("%u",(sen[j]));
			j++;
		}
		printf("%u\n",0);
		i++;
		sen=p[i];
	}
	printf("%u\n",0);
		
	//-------------------------------
	//-------------------------------
	
	printf("\n\n");
	
	//-------------------------------
	//print compiled program
	i=0;
	sen=p[i];
	while (sen[0]!=0)
	{
		var[sen[0]]=1;
		printf("\n%c:- ",(char)(sen[0]+96));
		j=1;
		while (sen[j] !=0)
		{
			printf("%c ",(char)(sen[j]+96));
			j++;
		}
		i++;
		sen=p[i];
	}
		
	//-------------------------------
	//-------------------------------
	
	return 0;
}

