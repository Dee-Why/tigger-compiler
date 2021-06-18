/* symbol table attributes */
#ifndef __SYMTAB_H__
#define __SYMTAB_H__
#include "node.hpp"
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::unordered_map;
using std::vector;

struct var_entry;
struct func_entry;
using var_table_t = unordered_map<string, var_entry>;
using func_table_t = unordered_map<string, func_entry>;

// struct var_entry begin
struct var_entry {
	string eeyore_name; // name in eeyore
	string sysy_name; // name in sysy
	bool is_array; // true if the symbol is an array
	bool is_const; // true if the symbol is constant
	bool is_param; // true if the symbol is a parameter
	vector<int> dim; // dimension of the array (in int)
	vector<int> val; // const value of the array

	var_entry() = default;
	var_entry(bool _is_array, bool _is_const, bool _is_param,
		const vector<int> &_dim, const vector<int> &_val = vector<int>(),
		const string &_sysy_name = "");
};
// struct var_entry end

// struct func_entry begin
struct func_entry {
	string eeyore_name; // name in eeyore
	vector<var_entry> params; // all parameters in the function
	vector<var_entry> func_var_table; // variable table for the function
	data_t ret_type;

	func_entry() = default;
	func_entry(const string &sysy_name, data_t _ret_type);
};
// struct func_entry end

extern vector<var_table_t> var_stack;
extern func_table_t func_table;
extern string now_func_name;
extern int blk_id;
extern bool create;

void inc_blk();
void dec_blk();

void init_tables();

bool defined(const string &name); //check if the variable is defined in current block
void reg_var(const string &name, bool is_const = false, bool is_array = false,
	bool is_param = false, const vector<int> &dim = vector<int>(),
	const vector<int> &val = vector<int>()); //register a variable into the variable table
bool find_var(const string &name, var_entry &store); //find if variable exists and store the item
bool find_var(const string &name); //find the variable if exists

void reg_func(const char *_name, data_t ret_type); //register a function into function table

bool find_func(const string &name, func_entry &store); //find if function exists and store the item
bool find_func(const string &name); //find if function exists
bool check_main(); //check whether the main function is valid

#endif // __SYMTAB_H__ end