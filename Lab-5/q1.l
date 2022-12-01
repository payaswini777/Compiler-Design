/*Lexical analyser*/

%{
#include<stdio.h>
int n = 0 ;  
%} 


%% 


"while"|"if"|"then"|"else"|"int"|"float"|"print"|"endif"|"for"|"void"|"do"|"long"|"double"|"return"|"main" {n++;printf("\t keyword : %s\n", yytext);}   


[a-zA-Z_][a-zA-Z0-9_]* {n++;printf("\t identifier : %s\n", yytext);} 
  

"<="|"=="|"="|"++"|"-"|"*"|"+" {n++;printf("\t operator : %s\n", yytext);}


[(){}|, ;]    {n++;printf("\t separator : %s\n", yytext);} 


[0-9]*"."[0-9]+ {n++;printf("\t float : %s\n", yytext);}  


[0-9]+ {n++;printf("\t integer : %s\n", yytext);}                        

.    ;
%% 

int yywrap(){}
   
int main() 
  
{
    yyin=fopen("compiler_design.c","r");
    yylex();
      
    printf("\n total no. of token = %d\n", n);   
       
}
