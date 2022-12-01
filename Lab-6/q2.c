/*Construct Recursive Descent Parser for the grammar G = ({S, L}, {(, ), a, ,}, {S -> (L) | a ; L-> L, S | S}, S) and
verify the acceptability of the following strings: i. (a,(a,a)) ii. (a,((a,a),(a,a))) You can manually eliminate Left Recursion if any in the gramma*/


#include<stdio.h>
#include<string.h>
int s(),L(),Ldash();
char *ip;
char string[50];
int main()
{
printf("Enter the string\n");
scanf("%s",string);
ip=string;
printf("\n\nInput\tAction\n--------------------------------\n");

if(s() && *ip=='\0'){
printf("\n--------------------------------\n");
printf("\n String is successfully parsed\n");
}
else{
printf("\n--------------------------------\n");
printf("Error in parsing String\n");
}
}


int s()
{
if(*ip=='(')
{
printf("%s\tS->(L) \n",ip);
ip++;
if(L())
{
if(*ip==')')
{
ip++;
return 1;
}
else
return 0;
}
else
return 0;
}

else if(*ip=='a')
{
ip++;
printf("%s\tS->a \n",ip);
return 1;
}
else
return 0;
}

int L()
{
    printf("%s\tL->SL' \n",ip);
    if(s())
    {
    if(Ldash())
    {
        return 1;
    }
    else
    return 0;
    }
    else
    return 0;
}
int Ldash()
{
    if(*ip==',')
    {
        ip++;
        printf("%s\tL'->,SL' \n",ip);
        if(s())
        {
            if(Ldash())
            {
                return 1;
            }
            else
            return 0;
        }
        else
        return 0;
    }
    else
    {
        printf("%s\tL'->^ \n",ip);
        return 1;
    }
}
