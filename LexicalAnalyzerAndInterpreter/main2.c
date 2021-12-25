#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *variables[1000]; int variableIndex = 0;
int integerList[1000] = { 0 }; int iIndex = 0;
bool isVariable(char* str);
void myParser(char* code,FILE* xx);
bool isKeyword(char* str);
bool isInteger(char* str);
bool isIntegerVariable(char* str);
void isComment(char* str,FILE* xx);
int substring(char *source, int from, int n, char *target);

bool isVariable(char* str)
{
	int len = strlen(str);

	if (len > 20) {
		return false;
	}

	for (int i = 0; i < len; i++) {
		if (str[0] == '_') {
			return false;
		}
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == '_'))) {
			return false;
		}
	}

	return true;
}

void myParser(char* code,FILE* xx) {
	int i = 0;
	int lineCounter = 0;
	char *line[1000];
	char *spliter = strtok(code, ".");
	do
	{
		line[lineCounter++] = spliter;
		spliter = strtok(NULL, ".");
	} while (spliter != NULL);
	

	do
	{
		int stage;
		int wordCount = 0;
		char *wordBuffer[1000];
		//use the strtok function to separate the delimeters.
		char *splitLine = strtok(line[i], " \n\r[]\"");
		while (splitLine != NULL) {
			wordBuffer[wordCount++] = splitLine;
			splitLine = strtok(NULL, " \n\r");
		}

		if (wordCount == 0) { break; }


		if (!strcmp(wordBuffer[0], "int"))
		{
			stage=0;
		}
		else if (!strcmp(wordBuffer[0], "move"))
		{
			stage=1;
		}
		else if (!strcmp(wordBuffer[0], "add"))
		{
			stage=2;
		}
		else if (!strcmp(wordBuffer[0], "sub"))
		{
			stage=3;
		}
		else if (!strcmp(wordBuffer[0], "out"))
		{
			stage=4;
		}
		else if (!strcmp(wordBuffer[0], "loop"))
		{
			stage=5;
		}
		switch (stage)
		{
		case 0:
			fprintf(xx,"'int' is a keyword.\n");


			//Variable
			if (wordBuffer[1] == NULL) {
				fprintf(xx,"Variable is expected.\n");
				break;
			}
			else if (isKeyword(wordBuffer[1])) {
				fprintf(xx,"'%s' is a keyword. Variable is expected.\n", wordBuffer[1]);
				break;
			}
			else if (isVariable(wordBuffer[1])) {
				fprintf(xx,"'%s' is a variable.\n", wordBuffer[1]);
				

				variables[variableIndex++] = wordBuffer[1];
				integerList[iIndex++] = 0;
			}
			else {
				fprintf(xx,"'%s' is not a variable. Variable is expected.\n", wordBuffer[1]);
				break;
			}

			//End Of Line
			if (wordCount == 2) {
				fprintf(xx,"'.' End of Line.\n");
			}
			else {
				fprintf(xx,"End of line is expected.\n");
				break;
			}
			break;

		//move keyword detects and performs operations	
		case 1:
			fprintf(xx,"'move' is a keyword.\n");
			

			//Integer Or Variable
			int moveInt = 0;
			if (wordBuffer[1] == NULL) {
				fprintf(xx,"Integer or variable are expected.\n");
				break;
			}
			else if (isKeyword(wordBuffer[1])) {
				fprintf(xx,"'%s' is a keyword. Integer or variable are expected.\n", wordBuffer[1]);
				break;
			}
			else if (isInteger(wordBuffer[1])) {
				fprintf(xx,"'%s' is an integer.\n", wordBuffer[1]);
				moveInt = atoi(wordBuffer[1]);
			}
			else if (isIntegerVariable(wordBuffer[1])) {
				fprintf(xx,"'%s' is a variable.\n", wordBuffer[1]);

				//it finds the value we will carry by traversing the values
				for (int i = 0; i < variableIndex; i++) {
					if (!strcmp(variables[i], wordBuffer[1])) {
						//assign the determined value in the integer list to the move parameter and print it
						moveInt = integerList[i];
						printf("%s , move to value %i \n ",wordBuffer[1],integerList[i]);
						fprintf(xx,"%s , move to value %i  \n ",wordBuffer[1],integerList[i]);
						break;
					}
				}
			}
			else {
				fprintf(xx,"'%s' is not a integer or variable. Integer or variable are expected.\n", wordBuffer[1]);
				break;
			}

			//To
			if (wordBuffer[2] == NULL) {
				fprintf(xx,"Keyword 'to' is expected.\n");

				break;
			}
			else if (!strcmp(wordBuffer[2], "to")) {
				fprintf(xx,"'to' is a keyword.\n");
			}
			else {
				fprintf(xx,"Keyword 'to' is expected.\n");

				break;
			}

			//Variable
			if (wordBuffer[3] == NULL) {
				fprintf(xx,"Variable is expected.\n");

				break;
			}
			else if (isKeyword(wordBuffer[3])) {
				fprintf(xx,"'%s' is a keyword. Variable is expected.\n", wordBuffer[3]);
				break;
			}
			else if (isIntegerVariable(wordBuffer[3])) {
				fprintf(xx,"'%s' is a variable.\n", wordBuffer[3]);

				//perform the specified operation with the assigned value
				for (int i = 0; i < variableIndex; i++) {
					if (!strcmp(variables[i], wordBuffer[3])) {
						integerList[i] = moveInt;
						fprintf(xx,"%s took the value %i \n",wordBuffer[3],integerList[i]);
						printf("%s took the value %i \n",wordBuffer[3],integerList[i]);
						break;
					}
				}
			}
			else {
				fprintf(xx,"'%s' is not a variable. Variable is expected.\n", wordBuffer[3]);
				break;
			}

			//End Of Line
			if (wordCount == 4) {
				fprintf(xx,"'.' End of Line.\n");
			}
			else {
				fprintf(xx,"End of line is expected.\n");
				break;
			}
			break;
		
		case 2:
			fprintf(xx,"'add' is a keyword.\n");

			//Integer Or Variable
			int addInt = 0;
			if (wordBuffer[1] == NULL) {
				fprintf(xx,"Integer or variable are expected.\n");
				break;
			}
			else if (isKeyword(wordBuffer[1])) {
				fprintf(xx,"'%s' is a keyword. Integer or variable are expected.\n", wordBuffer[1]);
				break;
			}
			else if (isInteger(wordBuffer[1])) {
				fprintf(xx,"'%s' is an integer.\n", wordBuffer[1]);

				addInt = atoi(wordBuffer[1]);
			}
			else if (isIntegerVariable(wordBuffer[1])) {
				fprintf(xx,"'%s' is a variable.\n", wordBuffer[1]);

				//We assign the specified value to add
				for (int i = 0; i < variableIndex; i++) {
					if (!strcmp(variables[i], wordBuffer[1])) {
						addInt = integerList[i];
						break;
					}
				}
			}
			else {
				fprintf(xx,"'%s' is not a integer or variable. Integer or variable are expected.\n", wordBuffer[1]);

				break;
			}

			//To
			if (wordBuffer[2] == NULL) {
				fprintf(xx,"Keyword 'to' is expected.\n");
				break;
			}
			else if (!strcmp(wordBuffer[2], "to")) {
				fprintf(xx,"'to' is a keyword.\n");
			}
			else {
				fprintf(xx,"Keyword 'to' is expected.\n");
				break;
			}

			//Variable
			if (wordBuffer[3] == NULL) {
				fprintf(xx,"Variable is expected.\n");
				break;
			}
			else if (isKeyword(wordBuffer[3])) {
				fprintf(xx,"'%s' is a keyword. Variable is expected.\n", wordBuffer[3]);
				break;
			}
			else if (isIntegerVariable(wordBuffer[3])) {
				fprintf(xx,"'%s' is a variable.\n", wordBuffer[3]);
				//the loop goes through all the indexes and adds
				for (int i = 0; i < variableIndex; i++) {
					//assigns the value in the result of the operation to sum
					if (!strcmp(variables[i], wordBuffer[3])) {
						integerList[i] += addInt;
						printf("%s addition result value  %i \n",wordBuffer[3],integerList[i]);
						fprintf(xx,"%s addition result value %i \n",wordBuffer[3],integerList[i]);
						break;
					}
				}
			}
			else {
				
				fprintf(xx,"'%s' is not a variable. Variable is expected.\n", wordBuffer[3]);
				break;
			}

			//End Of Line
			if (wordCount == 4) {
				
				fprintf(xx,"'.' End of Line.\n");
			}
			else {
				fprintf(xx,"End of line is expected.\n");
				break;
			}
			break;

		case 3:
			fprintf(xx,"'sub' is a keyword.\n");

			//Integer Or Variable
			int subInt = 0;
			if (wordBuffer[1] == NULL) {
				fprintf(xx,"Integer or variable are expected.\n");
				break;
			}
			else if (isKeyword(wordBuffer[1])) {
				fprintf(xx,"'%s' is a keyword. Integer or variable are expected.\n", wordBuffer[1]);
				break;
			}
			else if (isInteger(wordBuffer[1])) {
				fprintf(xx,"'%s' is an integer.\n", wordBuffer[1]);

				subInt = atoi(wordBuffer[1]);
			}
			else if (isIntegerVariable(wordBuffer[1])) {
				fprintf(xx,"'%s' is a variable.\n", wordBuffer[1]);

				//we are traversing the values in the loop and throwing the result of the operation
				for (int i = 0; i < variableIndex; i++) {
					if (!strcmp(variables[i], wordBuffer[1])) {
						subInt = integerList[i];
						break;
					}
				}
			}
			else {
				fprintf(xx,"'%s' is not a integer or variable. Integer or variable are expected.\n", wordBuffer[1]);
				break;;
			}

			//To
			if (wordBuffer[2] == NULL) {
				fprintf(xx,"Keyword 'from' is expected.\n");
				break;
			}
			else if (!strcmp(wordBuffer[2], "from")) {
				fprintf(xx,"'to' is a keyword.\n");
			}
			else {
				fprintf(xx,"Keyword 'from' is expected.\n");
				break;
			}

			//Variable
			if (wordBuffer[3] == NULL) {
				fprintf(xx,"Variable is expected.\n");
				break;
			}
			else if (isKeyword(wordBuffer[3])) {
				fprintf(xx,"'%s' is a keyword. Variable is expected.\n", wordBuffer[3]);
				break;
			}
			else if (isIntegerVariable(wordBuffer[3])) {
				fprintf(xx,"'%s' is a variable.\n", wordBuffer[3]);
				
				//loop performs the operation when the values are in the condition of hovering
				for (int i = 0; i < variableIndex; i++) {
					if (!strcmp(variables[i], wordBuffer[3])) {
						//we assign the value as index
						integerList[i] -= subInt;
						//and print it to the screen
						fprintf(xx,"%s subtraction value  %i \n",wordBuffer[3],integerList[i]);
						printf("%s subtraction value  %i \n",wordBuffer[3],integerList[i]);
						break;
					}
				}
			}
			else {
				fprintf(xx,"'%s' is not a variable. Variable is expected.\n", wordBuffer[3]);
				break;
			}

			//End Of Line
			if (wordCount == 4) {
				fprintf(xx,"'.' End of Line.\n");

			}
			else {
				fprintf(xx,"End of line is expected.\n");
				break;
			}
			break;

		//When it detects the out keyword, it enters this condition and performs the operations.
		case 4:
			fprintf(xx,"'out' is a keyword.\n");

			//Integer, Variable Or String
			if (wordBuffer[1] == NULL) {
				fprintf(xx,"Integer, variable or string are expected.\n");
				break;
				
			}
			else if (isInteger(wordBuffer[1])) {
				fprintf(xx,"'%s' is an integer.\n", wordBuffer[1]);
				fprintf(xx,"Integer Value: %s\n", wordBuffer[1]);
				
			}
			else if (isIntegerVariable(wordBuffer[1])) {
				fprintf(xx,"'%s' is a variable.\n", wordBuffer[1]);

				//The loop finds the value we will extract by browsing the indexes
				for (int i = 0; i < variableIndex; i++) {
					if (!strcmp(variables[i], wordBuffer[1])) {
						fprintf(xx,"'%s' variable value: %i\n", wordBuffer[1], integerList[i]);
						break;
					}
				}
			}
			else {
				fprintf(xx,"%s\n", wordBuffer[1]);
			}

			//End Of Line
			if (wordCount == 2) {
				fprintf(xx,"'.' End of Line.\n");
			}
			else {
				fprintf(xx,"End of line is expected.\n");
				break;
			}
			break;

			case 5:
				fprintf(xx,"'loop' is a keyword.\n");

			//Integer Or Variable
			int loopInt = 0;
			if (wordBuffer[1] == NULL) {
				fprintf(xx,"Integer or variable are expected.\n");
				break;
			}
			else if (isKeyword(wordBuffer[1])) {
				fprintf(xx,"'%s' is a keyword. Integer or variable are expected.\n", wordBuffer[1]);
				break;
			}
			else if (isInteger(wordBuffer[1])) {
				fprintf(xx,"'%s' is an integer.\n", wordBuffer[1]);

				loopInt = atoi(wordBuffer[1]);
			}
			else if (isIntegerVariable(wordBuffer[1])) {
				fprintf(xx,"'%s' is a variable.\n", wordBuffer[1]);

				//finds how many times to loop and we assign the value we found in the index
				for (int i = 0; i < variableIndex; i++) {
					if (!strcmp(variables[i], wordBuffer[1])) {
						loopInt = integerList[i];
						break;
					}
				}
			}
			else {
				fprintf(xx,"'%s' is not a integer or variable. Integer or variable are expected.\n", wordBuffer[1]);

				break;
			}

			//Times
			if (wordBuffer[2] == NULL) {
				fprintf(xx,"Keyword 'times' is expected.\n");
				break;
			}
			else if (!strcmp(wordBuffer[2], "times")) {
				fprintf(xx,"'times' is a keyword.\n");
			}
			else {
				fprintf(xx,"Keyword 'times' is expected.\n");
				break;
			}

			//Code
			for (int i = 0; i < loopInt; i++) {
				char newCode[100] = "";
				//It creating new  code for data in brackets  with the strcat() function.
				for (int i = 3; i < wordCount; i++) {
					strcat(newCode, " ");
					strcat(newCode, wordBuffer[i]);
				}
				strcat(newCode, ".");
				myParser(newCode,xx);
			}

			//End Of Line
			if (wordCount > 4) {
				fprintf(xx,"'.' End of Line.\n");
			}
			else {
				printf("End of line is expected.\n");
				fprintf(xx,"End of line is expected.\n");
				break;
			}
				break;
		default:
			fprintf(xx,"%s", wordBuffer[0]);
		
			break;
		}		
		i++;
	}while (i < lineCounter) ;
}

bool isKeyword(char* str) {

	//define the keyword values and perform the control
	if (!strcmp(str, "int") ||
		!strcmp(str, "move") || !strcmp(str, "to") || !strcmp(str, "add") ||
		!strcmp(str, "sub") || !strcmp(str, "from") ||
		!strcmp(str, "loop") || !strcmp(str, "times") ||
		!strcmp(str, "out")) {
		return true;
	}

	return false;
}

bool isInteger(char* str) {

	int len = strlen(str);

	if (len > 100) {
		return false;
	}

	for (int i = 0; i < len; i++) {
		if (i > 0) {
			if (str[i] == '-' || len == 1) {
				return false;
			}
		}
		if (!(isdigit(str[i]) || str[i] == '-')) {
			return false;
		}
	}

	return true;
}

bool isIntegerVariable(char* str) {
	//Compares the string indicated by the first parameter with the string indicated by the second parameter.

	for (int i = 0; i < variableIndex; i++) {
		//Returns a zero value if all characters in both strings are the same, or a non-zero value otherwise.
		if (!strcmp(str, variables[i])) {
			return true;
		}
	}

	return false;
}
char commentLine[100]; char a[100]; char b[100];

void isComment(char* str,FILE* xx) {
	int i = 0;
	bool trueComment = false;
	int j;
	do
	{
	if (str[i] == '{') {
			j=i;
			while (j < strlen(str)) {
				if (str[j] == '}') {
					substring(str, i + 1, j - i - 1, commentLine);
					fprintf(xx,"Comment Line: '%s'\n", commentLine);
					substring(str, 0, i, a);
					substring(str, j + 1, strlen(str), b);
					strcat(a, b);
					strcpy(str, a);

					trueComment = true;

					isComment(str,xx);
				}
				j++;
			}
			if (!trueComment) {
				fprintf(xx,"Comment Line is not completed.\n");
				exit(0);
			}
		}
		i++;
	}while (i < strlen(str));
	
	
	
		
}
int substring(char *source, int from, int n,char *target) {
	int length;
	int k;
	int  i=0;
	for (length = 0; source[length] != '\0'; length++);
	k=0;
	if (from > length) {
		printf("Starting index is invalid.\n");
		return 1;
	}
	if ((from + n) > length) {
		n = (length - from);
	}
	do
	{
		target[i] = source[from + i];
		i++;
	} while (i < n);
		
	
	target[i] = '\0';
	return 0;
}

int main() {
	FILE *fp;
	FILE *xl;
	long lSize;
	char *code;
	char dosya[20];
	int m=0;
	
	printf("Dosya adini giriniz  ");
	scanf("%s",dosya);
	while (dosya[m]!='\0')
	{
		m++;
	}
	dosya[m]='.';
	dosya[m+1]='b';
	dosya[m+2]='a';
	dosya[m+3]='\0';
	fp = fopen(dosya, "rb");
	xl = fopen("myscript.lx", "w");
	if (!fp) perror("myscript.ba"), exit(1);

	fseek(fp, 0L, SEEK_END);
	lSize = ftell(fp);
	rewind(fp);

	code = calloc(1, lSize + 1);
	if (!code) fclose(fp), fputs("memory alloc fails", stderr), exit(1);

	if (1 != fread(code, lSize, 1, fp)) {
		fclose(fp), free(code), fputs("entire read fails", stderr), exit(1);
	}

	isComment(code,xl);
	myParser(code,xl);
}