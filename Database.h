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
	table set_union(std::string table1, std::string table2);						// returns the combined data and removes duplicates
	void set_diff();
	void cross_product();	//

	void open();
	void close();
	void delete_table(std::string);													// deletes the specified table
	void save();
	void exit();
	void show(std::string);
	void create(std::string);	//
	void update();
	void insert();	//
	void delete_tuple();	//
private:
	void update_mat();
	std::fstream fs;
	table_list db_copy;
	bool mat_updated;
};

#endif
