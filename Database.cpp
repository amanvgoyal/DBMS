#include "Database.h"
#include <iostream>

using namespace std;

typedef std::map<std::string, std::vector<std::string> > table;
typedef std::map<std::string, table> table_list;

Database::Database() {
  // ...
}

void Database::selection(){
	
}

table Database::projection(string table_name, vector<string> attributes){
	table result;
	table::iterator it;

	for (int i = 0; i < attributes.size(); ++i)
	{	// find the columns to get
		it = db_copy[table_name].find(attributes[i]);
		if (it != db_copy[table_name].end())
		{	// grab the values
			result[table_name][attributes[i]] = db_copy[table_name][attributes[i]];
		}
	}
	return result;
}

void Database::renaming(){

}

table Database::set_union(table tbl1, table tbl2){
	// check if tables exist in the database
	table result;
	table::iterator it1 = tbl1.begin();
	table::iterator it2 = tbl2.begin();
	/* key_compares might not be needed */
	//table::key_compare kc1 = table_1.key_comp;
	//table::key_compare kc2 = table_2.key_comp;
	// check if the two tables have the same columns
	bool same_attributes = true;
	for (it1; it1 != tbl1.end(); ++it1)
	{
		same_attributes = (it1->first != it2->first) ? false : true;
		++it2;
	}
	if (same_attributes)
	{
		it1 = tbl1.begin();
		it2 = tbl2.begin();
		// insert tuples from first table
		for (it1; it1 != tbl1.end(); ++it1)
		{
			result[it1->first] = it1->second;
		}
		// insert tuples from second table and check if duplicates exist
		table::iterator r_it = result.begin();
		bool duplicate_tuple = true;
		for (int i = 0; i < it2->second.size(); ++i)
		{	// start comparing the values of the first attribute in result
			for (int j = 0; (j < r_it->second.size()) || !duplicate_tuple; ++j)
			{	// to the values of the first attribute of table_2
				// check if the tuple is a duplicate
				for (r_it; (r_it != result.end()) || !duplicate_tuple; ++r_it)
				{	// iterate through all the columns and compare
					// the values of the tuples
					if (it2->second[i] != r_it->second[j]) duplicate_tuple = false;
					++it2;
				}
				r_it = result.begin();
				it2 = tbl2.begin();
			}
				
			if (!duplicate_tuple)
			{	// add the row from table_2 to result if not a duplicate
				for (r_it; r_it != result.end(); ++r_it)
				{	// iterate through all the columns and add 
					// the value of the correct row
					r_it->second.push_back(it2->second[i]);
					++it2;
				}
				// reset variables
				r_it = result.begin();
				it2 = tbl2.begin();
				duplicate_tuple = true;
			}
		}
	}

	return result;
}

void Database::set_diff(){

}

table Database::cross_product(table tbl1, table tbl2){
	// check if tables exist in the database
	table result;
	table::iterator it1 = tbl1.begin();
	table::iterator it2 = tbl2.begin();
	// add the attributes to the resulting table
	for (it1; it1 != tbl1.end(); ++it1) result[it1->first];
	for (it2; it2 != tbl2.end(); ++it2) result[it2->first];
	// add the values to the attibutes
	table::iterator r_it = result.begin();
	it1 = tbl1.begin();
	it2 = tbl2.begin();
	for (int i = 0; i < it1->second.size(); ++i)
	{
		for (int j = 0; j < it2->second.size(); ++j)
		{
			for (it1; it1 != tbl1.end(); ++it1)
			{
				r_it->second.push_back(it1->second[i]);
				++r_it;
			}
			for (it2; it2 != tbl2.end(); ++it2)
			{
				r_it->second.push_back(it2->second[j]);
				++r_it;
			}
			// reset iterators
			it1 = tbl1.begin();
			it2 = tbl2.begin();
			r_it = result.begin();
		}
	}
	return result;
}

void Database::open() {

}

void Database::close() {

}

void Database::delete_table(string table_name) {
	table_list ::iterator it;
	it = db_copy.find(table_name);
	db_copy.erase(it);
}

void Database::save() {

}

void Database::exit() {

}

void Database::show(string) {

}

void Database::create(std::string table_name) {
	db_copy[table_name];
}

void Database::update() {

}

void Database::insert_tuple(table tuple) {

}

void Database::delete_tuple(string attribute, string value) {

}

void Database::update_mat() {

}

