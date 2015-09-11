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

table Database::set_union(string table_name_1, string table_name_2){
	// check if tables exist in the database
	table_list::iterator tl_it1 = db_copy.find(table_name_1);
	table_list::iterator tl_it2 = db_copy.find(table_name_2);
	table result;
	if (tl_it1 != db_copy.end() && tl_it2 != db_copy.end())
	{
		table table_1 = db_copy[table_name_1];
		table table_2 = db_copy[table_name_2];
		table::iterator it1 = table_1.begin();
		table::iterator it2 = table_2.begin();
		/* key_compares might not be needed */
		//table::key_compare kc1 = table_1.key_comp;
		//table::key_compare kc2 = table_2.key_comp;
		// check if the two tables have the same columns
		bool same_attributes = true;
		for (it1; it1 != table_1.end(); ++it1)
		{
			same_attributes = (it1->first != it2->first) ? false : true;
			++it2;
		}
		if (same_attributes)
		{
			it1 = table_1.begin();
			it2 = table_2.begin();
			// insert tuples from first table
			for (it1; it1 != table_1.end(); ++it1)
			{
				result[it1->first] = it1->second;
			}
			// insert tuples from second table and check if duplicates exist
			table::iterator r_it = result.begin();
			bool duplicate_tuple = true;
			for (int i = 0; i < r_it->second.size(); ++i)
			{	// start comparing the values of the first attribute in result
				for (int j = 0; j < it2->second.size(); ++j)
				{	// to the values of the first attribute of table_2
					if (r_it->second[i] != it2->second[j]) duplicate_tuple = false;
					else
					{	// check if the tuple is a duplicate
						for (r_it; r_it != result.end(); ++r_it)
						{	// iterate through all the columns and compare
							// the values of the tuples
							if (r_it->second[i] != it2->second[j]) duplicate_tuple = false;
							++it2;
						}
					}
					if (!duplicate_tuple)
					{	// add the row from table_2 to result if not a duplicate
						for (r_it; r_it != result.end(); ++r_it)
						{	// iterate through all the columns and add 
							// the value of the correct row
							r_it->second.push_back(it2->second[j]);
							++it2;
						}
						// reset variables
						r_it = result.begin();
						it2 = table_2.begin();
						duplicate_tuple = true;
					}
				}
			}
		}
	}

	return result;
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

