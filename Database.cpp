#include "Database.h"
#include <iostream>
#include <algorithm>

using namespace std;

typedef std::map<std::string, std::vector<std::string> > table;
typedef std::map<std::string, table> table_list;

Database::Database() {
	mat_updated = false;
}

// In relation 'table_name', if attribute 'lhs' exists,
// check entries 'x' satisfying x op rhs
table Database::selection(string table_name,
	string lhs, string op, string rhs) {
	table_list::iterator table_it = db_copy.find(table_name);
	table result;
	table t = db_copy[table_name];

	// Temporary - figure out why map is emptied
	update_mat();

	// If table exists
	//  if (table_it != db_copy.end()) {
	if (db_copy.count(table_name) > 0) {
		// Add all tuples satisfying a op b to result
		// If attribute exists in table
		if (db_copy[table_name].count(lhs) > 0) {
			// For each 
			//for (auto it : db_copy[table_name][lhs]) {
			vector<string> v = db_copy[table_name][lhs];
			for (int i = 0; i < v.size(); ++i) {
				if (op == "<") {}
				else if (op == "<=") {}
				else if (op == ">") {}
				else if (op == ">=") {}
				else if (op == "==") {
					if (v[i] == rhs) {
						for (auto it : db_copy[table_name]) {
							vector<string> v2 = db_copy[table_name][it.first];
							result[it.first].push_back(v2[i]);
						}
					}
				}
			}
		}
		else { cout << "Attribute DNE!" << endl; }
	}
	else { cout << "Table DNE!" << endl; }

	return result;
}

table Database::projection(string table_name, vector<string> attributes) {
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

void Database::renaming() {

}

table Database::set_union(table tbl1, table tbl2) {
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


// A \ B = {a in A | a not in b}
table Database::set_diff(string table_name_1, string table_name_2) {
	table_list::iterator t1_it1 = db_copy.find(table_name_1);
	table_list::iterator t1_it2 = db_copy.find(table_name_2);
	table result;

	// check if tables exist in the database
	if (t1_it1 != db_copy.end() && t1_it2 != db_copy.end()) {
		cout << "t1, t2 exist" << endl;
		table table_1 = db_copy[table_name_1];
		table table_2 = db_copy[table_name_2];

		vector<string> t2_data;

		// For each attribute check if corresponding vector in tb1 is not in tb2
		// If, so add that attribute and its vector into result
		for (auto& it1 : table_1) {
			// Case where attributes match
			if (table_2.count(it1.first) > 0) {
				for (int i = 0; i < it1.second.size(); ++i) {
					t2_data = table_2[it1.first];

					// If elem not in attr vector 2, but in attr vector 1, put in result 
					if (find(t2_data.begin(), t2_data.end(), it1.second[i])
						== t2_data.end()) {
						result[it1.first].push_back(it1.second[i]);
					}
				}
				//if (it1.second != table_2[it1.first]) {
				//  result[it1.first] = it1.second;
				//}
			}

			// Case where attributes do not mach
			else { result[it1.first] = it1.second; }
		}

	}

	return result;
}

table Database::cross_product(table tbl1, table tbl2) {
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
	table_list::iterator it;
	it = db_copy.find(table_name);
	db_copy.erase(it);
}

void Database::save() {

}

void Database::exit() {

}

void Database::show(table t) {
	for (auto it1 : t) {
		cout << it1.first << endl;
		for (auto it2 : t[it1.first]) {
			cout << "\t" << it2 << endl;
		}
	}
}

void Database::create(std::string table_name) {
	db_copy[table_name];
}

void Database::insert_tuple(table tuple) {

}

void Database::delete_tuple(string attribute, string value) {

}

void Database::print_db() {
	if (!mat_updated) { update_mat(); }

	for (auto it1 : db_copy) {
		cout << db_copy.count(it1.first) << endl;;
		cout << it1.first << " - \n";
		map<string, vector<string> > &inner1 = it1.second;
		for (auto it2 : inner1) {
			cout << '\t' << it2.first << ": ";
			vector<string>& innermost = it2.second;
			for (auto it3 : innermost) {
				cout << it3 << ' ';
			}
			cout << endl;
		}
	}
}

void Database::update_mat() {
	string line, tok, new_name, attr_name;
	string delim = " ";
	vector<string> temp;

	size_t pos = 0;

	fstream fs("database.txt");

	// Tokenize 
	while (getline(fs, line)) {
		while ((pos = line.find(delim)) != string::npos) {
			tok = line.substr(0, pos);
			temp.push_back(tok);
			line.erase(0, pos + delim.length());
		}

		// Grab table name if nontrivial line did not start with *. 
		// Grab table attribute name otherwise
		if (temp.size() != 0) {
			if (temp[0][0] != '*') {
				new_name = temp[0];
			}

			// Get tabble attribute name, put following data into vector
			else if (temp[0][0] == '*') {
				vector<string>::const_iterator beg = temp.begin() + 4;
				vector<string>::const_iterator end = temp.end();
				vector<string> data(beg, end);

				// Remove whitespace entries
				for (int i = 0; i < data.size(); ++i) {
					//cout<<i<<'-'<<data[i]<<'_'<<data[i].size()<<endl;
					//if (data[i].find_first_not_of(' ') != string::npos) {
					if (data[i].size() == 0) {
						data.erase(data.begin() + i);
					}
					// }
				}

				for (int i = 0; i < data.size(); ++i) {
					//cout<<i<<'-'<<data[i]<<'_'<<data[i].size()<<endl;
					if (data[i].size() != 0) {
						attr_name = data[i];
						data.erase(data.begin() + i);
						break;
					}
				}

				db_copy[new_name][attr_name] = data; // Add entry to db
			}
		}
		temp = {};
	}
	mat_updated = true;
}
