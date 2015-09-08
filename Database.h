#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Database{
 public:
        Database();
        void selection();
	void projection();
	void renaming();
	void set_union();
	void set_diff();
	void cross_product();

	void open();
	void close();
	void save();
	void exit();
	void show();
	void create();
	void update();
	void insert();
	void delete_tuple();
 private:
	std::fstream fs;

	std::vector<std::vector<std::string> > db_copy; 

};

#endif
