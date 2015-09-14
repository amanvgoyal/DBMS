#include "Database.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef std::map<std::string, std::vector<std::string> > table;
typedef std::map<std::string, table> table_list;

bool Database::numerical_str(string& s) {
  string::const_iterator it = s.begin();
  while (it != s.end()) {
    if (!isdigit(*it)) {return false;}
    ++it;
  }
  return true;
}

Database::Database() {
  mat_updated = false;
}

bool Database::file_exists(string file_name) {
  ifstream ifs(file_name);
  if (ifs.good()) {return true;}
  return false;
}

// In relation 'table_name', if attribute 'lhs' exists,
// check entries 'x' satisfying x op rhs
// ADD SELECT ALL
table Database::selection(string table_name, 
			  string lhs, string op, string rhs) {
  table_list::iterator table_it = db_copy.find(table_name);
  table result;
  table t = db_copy[table_name];
  vector<string> selected;
    
  // Temporary - figure out why map is emptied
  //  update_mat();

  // If table exists
    if (db_copy.count(table_name) > 0) {
    // Add all tuples satisfying a op b to result
    // If attribute exists in table
    if (db_copy[table_name].count(lhs) > 0) {
      
      // Check if comparator is strictly numerical
      // if so, add fitting selection from db_copy to result
      vector<string> v = db_copy[table_name][lhs];
      for (int i = 0; i < v.size(); ++i) {
	if (op != "==") {
	  if (!numerical_str(rhs)) {
	    cout << "Non numerical input!" << endl;
	    return result;
	  }

	  else { 
	    if ((op == "<" && stod(v[i]) < stod(rhs)) ||
		(op == "<=" && stod(v[i]) <= stod(rhs)) ||
		(op == ">" && stod(v[i]) > stod(rhs)) ||
		(op == ">=" && stod(v[i]) >= stod(rhs))) {
	      for (auto it : db_copy[table_name]) {
		selected = db_copy[table_name][it.first];
		result[it.first].push_back(selected[i]);
	      }
	    }
	  }
	}
	
	// Handles equality for both words and strings
	else if (op == "==") {
	  if (v[i] == rhs) {
	    for (auto it : db_copy[table_name]) {
	      selected = db_copy[table_name][it.first];
	      result[it.first].push_back(selected[i]);
	    }
	  }
	}
	else if (op == "!=") {
	  if (v[i] != rhs) {
	    for (auto it : db_copy[table_name]) {
	      selected = db_copy[table_name][it.first];
	      result[it.first].push_back(selected[i]);
	    }
	  }
	}
	else if (op == "*") {
	  for (auto it : db_copy[table_name]) {
	    selected = db_copy[table_name][it.first];
	    result[it.first].push_back(selected[i]);
	  }
	}
      }
    }
    else{cout << "Attribute DNE!" << endl;}
  }
  else {cout << "Table DNE!" << endl;}

  return result;
}

void Database::projection(){

}

void Database::renaming(string table_name, string old_name, string new_name){
  if (!file_exists(table_name)) {return;} // Throw exp

  fstream fs(table_name);
  ofstream fs2("temp.db");
  string line;
  size_t pos = 0;
  vector<string> new_lines;

  // Replace attribute titles with new_name
  // on a 'by line' basis, rewriting new lines to new file
  // then destroying old database.txt and giving that name to the new one
  while (getline(fs, line)) {
    pos = line.find(old_name);
    while (pos != string::npos) {
      line.replace(pos, old_name.size(), new_name);
      break;
    }
    new_lines.push_back(line);
    fs2 << line << endl;
  }
  remove(table_name.c_str());
  fs.close();
   
  fs2.close();
  rename("temp.db", table_name.c_str());
  // update_mat();
}

void Database::set_union(){

}


// A \ B = {a in A | a not in b}
table Database::set_diff(string table_name_1, string table_name_2){
  table result;
  
  // check if tables exist in the database
  if (db_copy.count(table_name_1) > 0 && db_copy.count(table_name_2) > 0) {
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
    }
      
    // Case where attributes do not mach
    else {
      result[it1.first] = it1.second;
    }
  }
}

return result;
}

void Database::cross_product(){

}

void Database::open(string table_name) {
}

//Removes a table from db_copy
void Database::close(string table_name) {
  if (!file_exists(table_name)) {return;} // throw exp  

  if (db_copy.count(table_name) > 0) {
    db_copy.erase(table_name);
  }
}

// 
void Database::save(table t, string table_name) {
  if (file_exists(table_name)) {return;} // Throw exp

  fstream fs(table_name);

  // write table_name minus ".db"
  // write table contents
  fs << table_name.substr(0,table_name.size() - 3) << ' ' << endl;
  for (auto it1 : t) {
    fs << "*        " << it1.first << ' ';
    for (auto it2 : t[it1.first]) {
      fs << it2 << ' ';
    }
    fs << endl;
  }
  fs.close();
}

// Remove everything from db_copy
void Database::exit() {
  for (auto& it : db_copy) {
    db_copy.erase(it.first);
  }
}

void Database::show(table t) {
  for (auto it1 : t) {
    cout << it1.first << " - "; 
    for (auto it2 : t[it1.first]) {
      cout << it2 << ' ';
    }
    cout << endl;
  }
}

void Database::create(string s) {
  
}


void Database::insert() {
  
}
 
void Database::delete_tuple() {

}

void Database::print_db() {
  //  if (!mat_updated) {update_mat();}
  for (auto it1 : db_copy) {
    cout << it1.first << " - \n";

    for (auto it2 : db_copy[it1.first]) {
      cout << '\t' << it2.first << ": ";

      for (auto it3 : db_copy[it1.first][it2.first]) {
	cout << it3 << ' ';
      }
      cout << endl;
    }
  }
}

void Database::update_mat(string table_name) {
  string line, tok, new_name, attr_name;
  string delim = " ";
  vector<string> temp;
  
  size_t pos = 0;

  fstream fs(table_name);
  
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
      
      // Get table attribute name, put following data into vector
      else if (temp[0][0] == '*') {
	vector<string>::const_iterator beg = temp.begin() + 4;
	vector<string>::const_iterator end = temp.end();
	vector<string> data(beg, end); 

	// Remove whitespace entries
	for(int i=0; i < data.size();++i){
	  if (data[i].size() == 0) {
	    data.erase(data.begin() + i);
	  }
	}

	for(int i=0; i < data.size();++i) {
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
  fs.close();
}  
