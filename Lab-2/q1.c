//Implementation of Lexical analyzer using C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main()
{
	char s[30];
	FILE* f;
	FILE* p;
	int i;
	f=fopen("week_2_file1.txt","r");
	p=fopen("week_2_file2.txt","w+");
	if(f==NULL)
	{
		printf("No file is found!!");
	}
	char l[30]="The tokens are : ";
	fprintf(p,"%s\n", l);
	while(!feof (f))
    {
    	int c=0;
    	fscanf (f, "%s", &s);
    	
    	for(i=0;i<strlen(s);i++)
    	{
    		if(isalpha(s[i]))
    		{
    			fprintf(p,"%c",s[i]);
			}
			else if(s[i]==';')
			{
				fprintf(p, "\n%c",s[i]);
			}
			else if(s[i]=='=')
			{
				fprintf(p,"\n%c\n",s[i]);
			}
			else if(isdigit(s[i]))
			{
				fprintf(p,"%c",s[i]);
			}
			else if(s[i]=='.')
			{
				if(c==0 && isdigit(s[i+1]))
				{
					fprintf(p,"%c",s[i]);
					c++;
				}
				else
				{
					fprintf(p," error! ");
				}
			}
			else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='(' || s[i]=='%' || s[i]==',' || s[i]=='{' || s[i]=='}')
			{
				fprintf(p,"\n%c\n",s[i]);
			}
			else if(s[i]==')')
			{
				fprintf(p,"\n%c",s[i]);
			}
		}
		fprintf(p,"\n");
    }
}
