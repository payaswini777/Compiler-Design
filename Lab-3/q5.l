/*Recognize a string with three consecutive 0’s*/

%{
  #include<stdio.h>
  int c=0;
%}

%%
[01]*000*[01]*  {printf("accepted");}
[01]*[10|11]* {printf("rejected");}
stop {return 0;}
%%
yywrap(){};

int main()
{
  yylex();
  getchar();
  return 0;
}
