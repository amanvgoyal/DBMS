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
	table projection(table tbl, std::vector<std::string> attributes);				// returns the specified attributes
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
	table create(std::vector<std::string> attributes);								// creates a new table with the specified name
	table insert_tuple(table dest_tbl, table tuples);								// inserts a new row into the table
	table delete_tuple(table tbl, std::string attribute, std::string value);		// deletes the specified row
	void print_db();
	void update_mat();
private:
	std::fstream fs;
	table_list db_copy;
	table private_keys;
	bool mat_updated;
};

#endif
