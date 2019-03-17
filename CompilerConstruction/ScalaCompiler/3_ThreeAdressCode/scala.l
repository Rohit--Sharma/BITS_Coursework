%{
	#include "y.tab.h"
	extern int lineNumber=0;
%}

%%

[0-9]+												{ printf("Num\n"); return Num;}
"var"												{ printf("var\n"); return Type;}
"object"											{ printf("object\n"); return obj;}
"{"													{ printf("bl Open\n"); return blockOpen;}
"}"													{ printf("bl close\n"); return blockClose;}
"def main ( args : Array [ String ] ) {"			{ printf("staar\n"); return start;}
"package"											{ printf("pkg\n"); return Pkg;}
if													{ printf("if\n"); return iftkn;}
"else"												{ printf("else\n"); return elsetkn;}
"("													{ printf("brace open\n"); return braceOpen;}
")"													{ printf("braceClose\n"); return braceClose;}
"for" 												{ printf("for\n"); return fortkn;}
"while" 											{ printf("while\n"); return whiletkn;}
"to" 												{ printf("to\n"); return to;}
"<-" 												{ printf("forRange\n"); return forRange;}
[<>]												{ printf("relop\n"); return Relop;}
"," 												{ printf("comma\n"); return comma;}
";"													{ printf("semicolon\n"); return semicolon;}
[a-zA-Z]+[a-zA-Z0-9]*								{ printf("ID\n"); return ID;}
[-+*/]												{ printf("op\n"); return op;}
[ \t]+												{ printf("space\n"); ;}
\n													{ lineNumber++;printf("new line\n"); return 0;}
.													{ printf("else\n"); return yytext[0];}
