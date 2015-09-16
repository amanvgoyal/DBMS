#include <iostream>
#include "Database.h"
#include "Parser.h"
#include "Token.h"

using namespace std;

int main(){
  try {
    Database d;
    //d.open("nights_watch.db");
    d.update_mat("nights_watch.db");
    d.update_mat("human.db");
    d.update_mat("old_people.db");
    // d.show(d.selection("nights_watch", "death", "==", "y")); 
    //  table t1 = d.selection("nights_watch", "death", "==", "y");  
    //table t2 = d.selection("nights_watch", "age", "==", "65");
    //d.save(t1, "dead_nw.db");
    //    d.update_mat("old_people.db");
    // d.print_db();
    // d.show(t1);
    //d.show(t2);
int main() {
	// Initialize Database class
	Database db;
	db.update_mat("nights_watch.db");
	db.update_mat("human.db");
	db.update_mat("old_people");

    //   d.print_db();
    //  d.show(d.set_diff("nights_watch", "old_people"));
    //d.show(d.set_diff("nights_watch", "old_people"));
    //  d.delete_tuple("nights_watch", "age");
    //d.show("nights_watch");
    //  d.renaming("human.db", "name", "NAME");
    //  d.print_db();
    d.renaming("asdfasdf.db", "name", "NAME");
  }

  catch (exception& e) {
    cerr << e.what() << endl;
  }

  catch (...) {
    cerr << "Something went wrong!" << endl;
  }
  
	// Test projection
	//db.projection()

	// Test delete_tuple
	// using "==" operation
	cout << "delete from human where name == eddard\n";
	table human_del_eddard = db.delete_tuple("human", "name", "==", "eddard");
	db.show(human_del_eddard);
	// using "!=" operation
	cout << "delete from human where death != y\n";
	table human_del_no_death = db.delete_tuple("human", "death", "!=", "y");
	db.show(human_del_no_death);
	// using "<" operation
	cout << "delete from human where age < 2\n";
	table human_del_age_lt_2 = db.delete_tuple("human", "age", "<", "2");
	db.show(human_del_age_lt_2);
	// using ">" operation
	cout << "delete from human where age > 2\n";
	table human_del_age_gt_2 = db.delete_tuple("human", "age", ">", "2");
	db.show(human_del_age_gt_2);
	// using "<=" operation
	cout << "delete from human where age <= 2\n";
	table human_del_age_leq_2 = db.delete_tuple("human", "age", "<=", "2");
	db.show(human_del_age_leq_2);
	// using ">=" operation
	cout << "delete from human where age >= 2\n";
	table human_del_age_get_2 = db.delete_tuple("human", "age", ">=", "2");
	db.show(human_del_age_get_2);
	cin.get();
return 0;
}
  
