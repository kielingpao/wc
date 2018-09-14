#include "stdafx.h"
#include <iostream>
using namespace std;
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
//#define _CRT_SECURE_NO_DEPRECATE
//#define _CRT_SECURE_NO_WARNINGS
int charcalculate = 0;

int wordcalculate = 0;

int linecalculate = 0;

void calculate(char * file)
{
	FILE * fp;
	char a;
	if ((fp = fopen(file, "r")) == NULL)
	{
		cout << "无这个文件啊!";
		exit(-1);
	}
	while (!feof(fp))
	{
		a = fgetc(fp);
		if (a != ' '&&a != '\n'&&a != '\t'&&a != ','&&a != '.'&&a != '!'&&a != ';'&&a != '=')
			charcalculate++;
		if (a == ' ' || a == '\n' || a == '\t' || a == ',' || a == '.' || a == '!' || a == '=' || a == ';')
			wordcalculate++;
		if (a == '\n' || a == '\t')
			linecalculate++;
	}
	linecalculate++;
	charcalculate--;
	fclose(fp);
}

int main(int argc, char* argv[])
{
	FILE *fp;

	calculate(argv[2]);
	while (1)
	{

		 if (!strcmp(argv[1], "-c"))
			cout << "文件:" << argv[2] << "字符数量:" << charcalculate << endl;
		else if (!strcmp(argv[1], "-w"))
			cout << "文件:" << argv[2] << "单词数量:" << wordcalculate << endl;
		else if (!strcmp(argv[1], "-l"))
			cout << "文件:" << argv[2] << "行数量:" << linecalculate << endl;

		else
			exit(0);
		scanf("%s%s%s", argv[0], argv[1], argv[2]);
	}
	return 0;

}


