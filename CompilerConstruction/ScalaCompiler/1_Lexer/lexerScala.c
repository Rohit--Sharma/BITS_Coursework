#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char lexeme[64];
	char type[64];
} entry;

char keywords[][32] = {"abstract", "case", "catch", "class", "def", "do", "else", "extends", "false", "final", "finally", "for", "forSome", "if", "implicit", "import", "lazy", "match", "new", "null", "object", "override", "package", "private", "protected", "return", "sealed", "super", "this", "throw", "trait", "try", "true", "type", "val", "var", "while", "with", "yield", "-", ":", "=", "=>", "<-", "<:", "<%", ">:", "#", "@", "Byte", "Short", "Int", "Long", "Float", "Double", "Char", "String", "Boolean", "Unit"};

// http://www.tutorialspoint.com/scala/scala_basic_syntax.htm
int isKeyword(char *buff)
{
	int i;
	for (i = 0; i < sizeof(keywords)/32; i += 1) {
		if (!strcmp(buff, keywords[i])) {
			return 1;
		}
	}
	return 0;
}

int isAlphanumericIdentifier(char *buff)
{
	if ((buff[0] >= 'a' && buff[0] <= 'z') || buff[0] == '_' || (buff[0] >= 'A' && buff[0] <= 'Z')) {
		int index = 1, len = strlen(buff);
		while (index < len) {
			if (!((buff[index] >= 'a' && buff[index] <= 'z') || buff[index] == '_' || (buff[index] >= '0' && buff[index] <= '9') || (buff[0] >= 'A' && buff[0] <= 'Z'))) {
				return 0;
			}
			index++;
		}
		return 1;
	}
	return 0;
}

int isOperatorIdentifier(char *buff)
{
	int index = 0, len = strlen(buff);
	while (index < len) {
		if (!(buff[index] == '+' || buff[index] == '-' || buff[index] == '/' || buff[index] == '*' || buff[index] == ':' || buff[index] == '<' || buff[index] == '>' || buff[index] == '?' || buff[index] == '~' || buff[index] == '#' || buff[index] == '&' || buff[index] == '|')) {
			return 0;
		}
		index++;
	}
	return 1;
}

int isMixedIdentifier(char *buff)
{
	char *part1, *part2;
	strcpy(part1, buff);
	int index = 0, len = strlen(buff);

	while (index < len) {
		if (buff[index] == '_') {
			break;
		}
		index++;
	}

	if (buff[index] == '_') {
		part2 = buff + index + 1;
		part1[index] = '\0';
		if (isAlphanumericIdentifier(part1) && isOperatorIdentifier(part2)) {
/*			printf("%s", "Mixed Identifier:\n");*/
			return 1;
		}
	}

	return 0;
}

int isLiteralIdentifier(char *buff)
{
	if (buff[0] == '\'' && buff[strlen(buff) - 1] == '\'') {
/*		printf("%s", "Literal Identifier:\n");*/
		return 1;
	}
	return 0;
}

// http://www.tutorialspoint.com/scala/scala_basic_syntax.htm
int isIdentifier(char *buff)
{
	if (isAlphanumericIdentifier(buff) || isOperatorIdentifier(buff) || isMixedIdentifier(buff) || isLiteralIdentifier(buff)) {
		return 1;
	} else {
		return 0;
	}
}

int isDelimiter(char *buff)
{
	if (*buff == '(' || *buff == ')' || *buff == '{' || *buff == '}') {
		return 1;
	}
	return 0;
}

int isLiteral(char *buff)
{
	int index = 0, len = strlen(buff);
	if (*buff == '"' && buff[len - 1] == '"') {
/*		printf("%s\n", "String Literal");*/
		return 1;
	} else if ('0' <= buff[index] && buff[index] <= '9') {
		index++;
		while (index < len) {
			if (!('0' <= buff[index] && buff[index] <= '9'))
				return 0;
			if (buff[index] == '.') {
				break;
			}
			index++;
		}
		if (buff[index++] == '.') {
			while (index < len) {
				if (!('0' <= buff[index] && buff[index] <= '9'))
					return 0;
				index++;
			}
		}
/*		printf("%s\n", "Numeric Literal");*/
		return 1;
	}
	return 0;
}

entry *scanner(char *buff)
{
	entry *answer = malloc(sizeof(entry));
	strcpy(answer->lexeme, buff);

	if (isKeyword(buff)) {
		strcpy(answer->type, "TK_KEYWORD");
	} else if (isIdentifier(buff)) {
		strcpy(answer->type, "TK_IDENTIFIER");
	} else if (isDelimiter(buff)) {
		strcpy(answer->type, "TK_DELIMITER");
	} else if (isLiteral(buff)) {
		strcpy(answer->type, "TK_LITERAL");
	} else if (!strcmp(buff, ";")) {
		strcpy(answer->type, "TK_SEMICOLON");
	}

	return answer;
}

int main (int argc, char *argv[])
{
	FILE *input_file = fopen("VarDecl.scala", "r");
	char *buffer = malloc(64);

	while (fscanf(input_file, "%s", buffer) != EOF) {
		entry *temp = malloc(sizeof(entry));
		temp = scanner(buffer);

		printf("%s\t|\t%s\n", temp->lexeme, temp->type);

		free(temp);
		bzero(buffer, 64);
	}

	if (input_file) {
		fclose(input_file);
	}
	return 0;
}
