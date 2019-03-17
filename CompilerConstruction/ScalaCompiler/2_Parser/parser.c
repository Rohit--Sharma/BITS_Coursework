#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[100][100];
int top = -1;
int lno;

#define ERROR_CODE -1
#define ERROR {printf("Error : Line %d\n", lno); exit(ERROR_CODE);}

void push(char s[]) {
	top++;
	strcpy(stack[top], s);
}

void pop() {
	top--;
}

int main() {
	char lexeme[50];

//	scanf("%d", &lno);
	scanf("%s", lexeme);
//	scanf("%s", lexeme);
	push("$");
	push("S");

	while(1) {
		while(!strcmp(lexeme, stack[top])) {
			pop();
			//if(scanf("%d", &lno) != EOF) {
				//scanf("%s", lexeme);
			if(!strcmp(lexeme,"$"))
				{
					goto finish;
				}
				scanf("%s", lexeme);
				printf("Current: %s %s\n", lexeme,stack[top]);

			//} else break;
		}

		int L = strlen(lexeme);

		if(!strcmp(stack[top], "S"))
		{
			if(!strcmp(lexeme,"package"))
			{
					pop();
					push("P");
			}
			else ERROR;
		}
		else if(!strcmp(stack[top], "P"))
		{
			if(!strcmp(lexeme, "package"))
			{
				pop();
				push("}");
				push("}");
				push("StList");
				push("start");
				push("{");
				push("ID");
				push("object");
				push("PN");
			}
			else ERROR;

		} else if(!strcmp(stack[top], "PN")) {

			if(!strcmp(lexeme, "package")) {
				pop();
				push("_PN");
				push("ID");
				push("package");
			}
			else ERROR;
		} else if(!strcmp(stack[top], "_PN")) {

			if(!strcmp(lexeme, "package")) {
				pop();
				push("P");
			}
			else if(!strcmp(lexeme, "object"))
			{
				pop();
			}
			 else ERROR;

		} else if(!strcmp(stack[top], "StList")) {

			if(!strcmp(lexeme, "ID")||!strcmp(lexeme, "type")||!strcmp(lexeme, "if")||!strcmp(lexeme, "for")||!strcmp(lexeme, "while")) 		{
				pop();
				push("_StList");
				push("Stmt");
			}
			else ERROR;

		} else if(!strcmp(stack[top], "_StList")) {

			if(!strcmp(lexeme, "ID")||!strcmp(lexeme, "type")||!strcmp(lexeme, "if")||!strcmp(lexeme, "for")||!strcmp(lexeme, "while")) {
				pop();
				push("StList");
			}
			else if(!strcmp(lexeme, "}"))
			{
				pop();
			}
			else ERROR;

		} else if(!strcmp(stack[top], "Stmt")) {

			if(!strcmp(lexeme, "ID")) {
				pop();
				push("Assign");
			}
			else if(!strcmp(lexeme, "type")) {
				pop();
				push("Declare");
			}
			else if(!strcmp(lexeme, "if")) {
				pop();
				push("IfSt");
			}
			else if(!strcmp(lexeme, "for")) {
				pop();
				push("ForSt");
			}
			else if(!strcmp(lexeme, "while")) {
				pop();
				push("WhileSt");
			}
			else ERROR;

		} else if(!strcmp(stack[top], "Declare")) {

			if(!strcmp(lexeme, "type")) {
					pop();
					push("IDList");
					push("type");
			}
			else ERROR;


		} else if(!strcmp(stack[top], "IDList")) {

			if(!strcmp(lexeme, "ID")) {
					pop();
					push("_IDList");
					push("ID");
			}
			else ERROR;

		} else if(!strcmp(stack[top], "_IDList")) {

			if(!strcmp(lexeme, "ID")||!strcmp(lexeme, "type")||!strcmp(lexeme, "}")||!strcmp(lexeme, "if")||!strcmp(lexeme, "for")||!strcmp(lexeme, "while")) {
					pop();
				}
			else if(!strcmp(lexeme, ","))
			{
					pop();
					push("IDList");
					push(",");
			}
			else ERROR;

		} else if(!strcmp(stack[top], "Assign")) {

			if(!strcmp(lexeme, "ID")) {
					pop();
					push("Expr");
					push("=");
					push("ID");
			}
			else ERROR;
		} else if(!strcmp(stack[top], "Expr")) {

			if(!strcmp(lexeme, "Num")) {
					pop();
					push("_Expr");
					push("Num");
			}
			else if(!strcmp(lexeme, "ID")) {
					pop();
					push("_Expr");
					push("ID");
			}
			else ERROR;

		} else if(!strcmp(stack[top], "_Expr")) {

			if(!strcmp(lexeme, "ID")||!strcmp(lexeme, "type")||!strcmp(lexeme, "if")||!strcmp(lexeme, "for")||!strcmp(lexeme, "while")||!strcmp(lexeme, "}")) {
				pop();
			}
			else if(!strcmp(lexeme, "op"))
			{
				pop();
				push("Expr");
				push("op");
			}
			else ERROR;

		} else if(!strcmp(stack[top], "IfSt")) {

			if(!strcmp(lexeme, "if")) {
					pop();
					push("}");
					push("StList");
					push("{");
					push("else");
					push("}");
					push("StList");
					push("{");
					push(")");
					push("LogExpr");
					push("(");
					push("if");
			}
			else ERROR;
		} else if(!strcmp(stack[top], "WhileSt")) {

			if(!strcmp(lexeme, "while")) {
					pop();
					push("}");
					push("StList");
					push("{");
					push(")");
					push("LogExpr");
					push("(");
					push("while");
			}
			else ERROR;
		} else if(!strcmp(stack[top], "ForSt")) {

			if(!strcmp(lexeme, "for")) {
					pop();
					push("}");
					push("StList");
					push("{");
					push(")");
					push("ForExpList");
					push("(");
					push("for");
			}
			else ERROR;
		} else if(!strcmp(stack[top], "ForExpList")) {

			if(!strcmp(lexeme, "ID")) {
					pop();
					push("_ForExpList");
					push("Num");
					push("to");
					push("Num");
					push("<-");
					push("ID");
			}
			else ERROR;
		} else if(!strcmp(stack[top], "_ForExpList")) {

			if(!strcmp(lexeme, ")")) {
					pop();
			}
			else if(!strcmp(lexeme, ";"))
			{
					pop();
					push("ForExpList2");
			}
			else ERROR;
		} else if(!strcmp(stack[top], "ForExpList2")) {

			if(!strcmp(lexeme, ";"))
			{
					pop();
					push("ForExpList");
					push(";");
			}
			else ERROR;
		} else if(!strcmp(stack[top], "LogExpr")) {

			if(!strcmp(lexeme, "ID"))
			{
					pop();
					push("_LogExpr");
					push("ID");
			}
			else if(!strcmp(lexeme, "Num"))
			{
					pop();
					push("__LogExpr");
					push("Relop");
					push("Num");
			}
			else ERROR;
		} else if(!strcmp(stack[top], "_LogExpr")) {

			if(!strcmp(lexeme, "Relop"))
			{
					pop();
					push("__LogExpr");
					push("Relop");
			}
			else if(!strcmp(lexeme, ")"))
			{
					pop();
			}
			else ERROR;
		}  else if(!strcmp(stack[top], "__LogExpr")) {

			if(!strcmp(lexeme, "ID"))
			{
					pop();
					push("ID");
			}
			else if(!strcmp(lexeme, "Num"))
			{
					pop();
					push("Num");
			}
			else ERROR;
		}
		else ERROR;
	}
	finish: printf("The parser gave positive result.\n");

	return 0;
}
