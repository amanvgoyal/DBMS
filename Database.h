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
	table selection(std::string,
		std::string, std::string, std::string);//
	table projection(table, std::vector<std::string>);						// returns the specified attributes
	void renaming(std::string, std::string, std::string); //
	table set_union(table, table);											// returns the combined data and removes duplicates
	table set_diff(std::string, std::string);//
	table cross_product(table, table);										// returns a table that pairs every row of both tables

	void open(std::string); //......
	void close(std::string); //
	void exit();
	void delete_table(std::string);											// deletes the specified table
	void save(table, std::string);
	void show(table); //
	table update(table, std::string, std::string, std::string, 
		std::vector<std::string>, std::vector<std::string>); 				// updates rows that match the condition
	table update(std::string, std::string, std::string, std::string, 
		std::vector<std::string>, std::vector<std::string>);				// overload of update that accepts the table name as a string
	table create(std::vector<std::string>);									// creates a new table with the specified name
	table insert_tuple(table, table);										// inserts a new row into the table
	table insert_tuple(std::string, table);									// overload of insert_tuple that accepts string
	table delete_tuple(table, std::string, std::string,	std::string);		// deletes rows that match the condition
	table delete_tuple(std::string, std::string, std::string, std::string);	// overload of delete_tuple that accepts the table name as a string
	void print_db();
	// private:
	void update_mat(std::string); //

private:
	std::fstream fs;
	table_list db_copy;
	table private_keys;
	bool mat_updated;

	bool numerical_str(std::string&);
	bool file_exists(std::string);
};

#endif
