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
	void selection();
	table projection(std::string table_name, std::vector<std::string> attributes);	// returns the specified attributes
	void renaming();
	table set_union(std::string table_name_1, std::string table_name_2);			// returns the combined data and removes duplicates
	void set_diff();
	table cross_product(std::string table_name_1, std::string table_name_2);		// returns a table that pairs every row of both tables

	void open();
	void close();
	void delete_table(std::string table_name);										// deletes the specified table
	void save();
	void exit();
	void show(std::string);
	void create(std::string table_name);											// creates a new table with the specified name
	void update();
	void insert_tuple(table tuple);													//
	void delete_tuple(std::string attribute, std::string value);															//
private:
	void update_mat();
	std::fstream fs;
	table_list db_copy;
	bool mat_updated;
};

#endif
