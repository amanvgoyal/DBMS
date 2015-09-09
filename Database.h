#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Database{
 public:
        void selection();//
	void projection();
	void renaming(); //
	void set_union();
	void set_diff();//
	void cross_product();

	void open(); 
	void close();
	void delete();
	void save();
	void exit();
	void show();
	void create(std::string);
	void update();
	void insert();
	void delete_tuple();

	void print_db();
 private:
	void update_mat(); //

	std::fstream fs;

	std::vector<std::vector<std::string> > db_copy; 

	bool mat_updated;
};

#endif
