#include "Database.h"
#include <iostream>

using namespace std;

Database::Database() {
  mat_updated = false;
}

void Database::selection(){
	
}

void Database::projection(){

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

void Database::save() {

}

void Database::exit() {

}

void Database::show() {
  
}

void Database::create(string s) {
  
}


void Database::insert() {

}
 
void Database::delete_tuple() {

}

void Database::print_db() {
  if (!mat_updated) {update_mat();}

  for (auto it1 : db_copy) {
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
	for(int i=0; i < data.size();++i){
	  //cout<<i<<'-'<<data[i]<<'_'<<data[i].size()<<endl;
	  //if (data[i].find_first_not_of(' ') != string::npos) {
	  if (data[i].size() == 0) {
	    data.erase(data.begin() + i);
	  }
	    // }
	}

	for(int i=0; i < data.size();++i) {
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











