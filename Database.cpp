#include "Database.h"
#include <iostream>

using namespace std;

typedef std::map<string, map<string, vector<string> > > table;

Database::Database() {
  // ...
}

void Database::selection(){
	
}

table Database::projection(string table_name, vector<string> attributes){
	table result;
	map<string, vector<string> >::iterator it;

	for (int i = 0; i < attributes.size(); ++i)
	{
		it = db_copy[table_name].find(attributes[i]);
		if (it != db_copy[table_name].end())
		{
			result[table_name][attributes[i]] = db_copy[table_name][attributes[i]];
		}
	}

	return result;
}

void Database::renaming(){

}

void Database::set_union(){

}

void Database::set_diff(){

}

void Database::cross_product(){

}

void Database::open() {

}

void Database::close() {

}

void Database::delete_table(string table_name) {
	table::iterator it;
	it = db_copy.find(table_name);
	db_copy.erase(it);
}

void Database::save() {

}

void Database::exit() {

}

void Database::show(string) {

}

void Database::create(std::string str) {

}

void Database::update() {

}

void Database::insert() {

}

void Database::delete_tuple() {

}

void Database::update_mat() {

}

