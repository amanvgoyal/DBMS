#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

typedef std::map<std::string, std::vector<std::string> > table;
typedef std::map<std::string, table> table_list;

class Database {
public:
	Database();
	table selection(std::string, std::string, std::string, std::string);
	table projection(std::string table_name, std::vector<std::string> attributes);	// returns the specified attributes
	void renaming();
	table set_union(table tbl1, table tbl2);										// returns the combined data and removes duplicates
	table set_diff(std::string, std::string);
	table cross_product(table tbl1, table tbl2);									// returns a table that pairs every row of both tables

	void open();
	void close();
	void delete_table(std::string table_name);										// deletes the specified table
	void save();
	void exit();
	void show(table tbl);
	void create(std::string table_name);											// creates a new table with the specified name
	void insert_tuple(table tuple);													// inserts a new row into the table
	void delete_tuple(std::string attribute, std::string value);					// deletes the specified row
	void print_db();
	void update_mat();
private:
	std::fstream fs;
	table_list db_copy;
	table private_keys;
	bool mat_updated;
};

#endif
