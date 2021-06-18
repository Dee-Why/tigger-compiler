#include "node.hpp"
#include "eeyore.tab.hpp"
#include "symtab.hpp"
#include <cstdio>
#include <unistd.h>
#include <string>
extern FILE *yyin;
int yyparse(void);
int yylex(void);

node *root;

bool has_err = false;


int main(int argc, char **argv)
{
	FILE *output_f;
	yyin = fopen(argv[3], "r");
	output_f = fopen(argv[5], "w");

	// initialize symbol tables
	init_tables();
	// core routine
	do{ yyparse(); } while (!feof(yyin));
	//check_main
	check_main();
	if( has_err ) { return 1; }
	//output eeyore to file
	if(e){ fprintf(output_f, "%s", root->code.c_str()); fflush(output_f); printf("eeyore code generated!\n"); }
	return 0;
}