#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

typedef std::map<std::string, std::map<std::string, std::vector<std::string> > > table;

class Database {
public:
	Database();
	void selection();
	table projection(string table, std::vector<std::string> attributes);	// returns the specified attributes
	void renaming();
	void set_union();	//
	void set_diff();
	void cross_product();	//

	void open();
	void close();
	void delete_table(std::string);	//
	void save();
	void exit();
	void show(std::string);	//
	void create(std::string);	//
	void update();
	void insert();	//
	void delete_tuple();	//
private:
	void update_mat();
	std::fstream fs;
	table db_copy;
	bool mat_updated;
};

#endif
