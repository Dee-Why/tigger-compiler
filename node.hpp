#ifndef __NODE_H__
#define __NODE_H__
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

extern int yylineno;
extern bool has_err;
void yyerror(const char *msg, int lineno = yylineno);

enum data_t { VOID, INT };
enum op_t { NONE, EQ, NE, GE, LE, G, L, ADD, SUB, NEGATE, MUL, DIV, MOD, AND, OR, NOT, MEM };

struct node;

typedef union {
    const char *name;
    int num;
    op_t op;
    data_t dtype;
    node *node;
} yylval_t;
#define YYSTYPE yylval_t

extern node *root;

// conversion
char *namestr(const char *s);
op_t str2op(const char *s);
data_t str2dtype(const char *s);
int str2num(const char *s, int base);

struct node {
	node *next = nullptr; // next node
	node *child = nullptr; // child node
	string code; // code to eeyore
	int lineno = yylineno; // line number of the node
	virtual void gen_code();
	virtual void set_next(node *_next);
};