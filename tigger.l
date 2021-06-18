%option yylineno
%option noyywrap
%option noinput
%option nounput
%{
#include "node.hpp"
#include "symtab.hpp"
%}

whitespace      [ \n\t\r\v\f]
t_var           t[0-9]+
T_var           T[0-9]+
p_var           p[0-9]+
function        f_[a-zA-Z][_a-zA-Z0-9]*
digit           [0-9]
num             (-)?[0-9]+
op              [\+\-\*\/%!<>]
label           l[0-9]+

%%

{whitespace}            {/* ignore it. */}