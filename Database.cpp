#include "Database.h"
#include <iostream>

using namespace std;

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

void Database::update_mat() {

}

void Database::insert() {

}
 
void Database::delete_tuple() {

}

void Database::print_db() {
  if (!mat_updated) {update_mat();}
  
  for (int i = 0; i < db_copy.size(); ++ i) {
    for (int j = 0; j < db_copy[i].size(); ++j) {
      cout << db_copy[i][j] << endl;
    }
  }
}


