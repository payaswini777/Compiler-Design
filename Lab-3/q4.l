/*Recognize strings ending with 00*/

%{
  #include<stdio.h>
%}

%%
[01]*00$  {printf("String Accepted\n");}
[01]*[10|11|01]  {printf("String Rejected\n");}
stop {return 0;}
%%
yywrap(){};
int main()
{
  yylex();
  getchar();
  return 0;
}
