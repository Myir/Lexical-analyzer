%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[10]="int";
char b[10]="float";
char c[10]="for";
char d[10]="while";
char e[10]="if";
char f[10]="include";
char g[10]="define";
char h[15]="\"stdio.h\"";
char i[15]="\"conio.h\"";
char j[10]="void";
int PD(char yytext[]);
int PDX(char yytext[]);
int SH(char yytext[]);
%}

%%

[\n]                  ;

[0-9]+                   printf("Int        : %s\n",yytext);

[0-9]*\.[0-9]+           printf("Float      : %s\n",yytext);

\"([^\"]*)\"             SH(yytext);

[\!-\/\:-\@\{-\~\[-\`]   printf("Symbol     : %s\n",yytext);

"++"                     printf("Symbol     : %s\n",yytext);

"--"                     printf("Symbol     : %s\n",yytext);

"+="                     printf("Symbol     : %s\n",yytext);

"-="                     printf("Symbol     : %s\n",yytext);

">="                     printf("Symbol     : %s\n",yytext);

"<="                     printf("Symbol     : %s\n",yytext);

[a-zA-Z][a-zA-Z0-9]*       PD(yytext);

%%
int PD(char yytext[])
{
  
 if(stricmp(yytext,a)==0||stricmp(yytext,b)==0||stricmp(yytext,c)==0||stricmp(yytext,d)==0||stricmp(yytext,e)==0)
  {
   printf("Keyword    : %s\n",yytext);
   }
  else if(stricmp(yytext,f)==0||stricmp(yytext,g)==0||stricmp(yytext,j)==0)
   {
   return 0;
   }
else
   {
    printf("Iden       : %s\n",yytext);
    }
}
int SH(char yytext[])
{
int i;
printf("Str         :");
for(i=1;i<strlen(yytext)-1;i++)
 {
    printf("%c",yytext[i]);
	
 }
 printf("\n");
}
void main()
{
	yylex();
}

int yywrap()
{
	return 1;
}
