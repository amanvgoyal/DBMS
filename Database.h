#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class Database{
 public:
        Database();
        void selection();//
	void projection();
	void renaming(); //
	void set_union();
	void set_diff();//
	void cross_product();

	void open(); 
	void close();
	void save();
	void exit();
	void show();
	void create(std::string);
	void update();
	void insert();
	void delete_tuple();

	void print_db();
	// private:
	void update_mat(); //
 private:
	std::fstream fs;

	std::map<std::string, std::map<std::string, 
	  std::vector<std::string> > > db_copy;

	bool mat_updated;
};

#endif
