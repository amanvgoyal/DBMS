#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

typedef std::map<std::string, std::vector<std::string> > table;
typedef std::map<std::string, table> table_list;

class Database{
 public:
        Database();
        table selection(std::string, 
			     std::string, std::string, std::string);//
	void projection();
	void renaming(std::string, std::string); //
	void set_union();
	table set_diff(std::string, std::string);//
	void cross_product();

	void open(); //......
	void close(); //
	void save(); 
	void exit(); //
	void show(table); //
	void create(std::string); //
	void update(); //
	void insert();
	void delete_tuple();

	void print_db();
	// private:
	void update_mat(); //

 private:
	std::fstream fs;

	std::map<std::string, std::map<std::string, 
	  std::vector<std::string> > > db_copy;
	
	std::map<std::string, std::vector<std::string> > private_keys;

	bool mat_updated;

	bool numerical_str(std::string&);
};

#endif
