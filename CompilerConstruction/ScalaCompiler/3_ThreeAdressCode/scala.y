%{
	#include <stdio.h>
	#include <stdlib.h>
%}
%token Num ID Relop op Type Pkg obj blockClose blockOpen start iftkn elsetkn braceOpen braceClose fortkn whiletkn to forRange comma semicolon

%%
//package  greeter  object  Hello  {  def main ( args : Array [ String ] ) {  if  (  x  <  2  )  {  var  y  }  else  {  var  z  x  =  3  }  var  aada21  }  }

S		: P //1
		;
P		: PN obj ID blockOpen start StList blockClose blockClose //2
		;
PN		: Pkg ID _PN  //3
		;
_PN		: PN  //4
		|//5
		;

StList	: Stmt _StList//6
		;
_StList	: StList//7
		|//8
		;

Stmt	: Decl//9
		| Assign//10
		| IfSt//11
		| WhileSt//12
		| ForSt//13
		;
Decl	: Type IDList//15
		;
IDList	: ID _IDList //16
		;
_IDList	: comma IDList//17
		|//18
		;

Assign	: ID '=' Expr//19
		;
Expr	: ID _Expr//20
		| Num _Expr//21
		;
_Expr	: op Expr//22
		|//23
		;

IfSt	: iftkn braceOpen LogExpr braceClose blockOpen StList blockClose elsetkn blockOpen StList blockClose//24
		;
WhileSt	: whiletkn braceOpen LogExpr braceClose blockOpen StList blockClose//25
		;
ForSt	: fortkn braceOpen ForExpList braceClose blockOpen StList blockClose//26
		;
ForExpList: ID forRange Num to Num _ForExpList//27
		;
_ForExpList: ForExpList2//28
		|//29
		;

ForExpList2: semicolon ForExpList//30
		;
LogExpr	: ID _LogExpr//31
		| Num Relop __LogExpr//32
		;
_LogExpr: Relop __LogExpr//33
		|//34
		;

__LogExpr: ID//35
		| Num//36
		;

%%

int yyerror(char *msg){
	printf("Invalid string!\n");
}

main(){
	printf("Enter string:\n");
	if(!yyparse())
		printf("Valid string!\n");
}
