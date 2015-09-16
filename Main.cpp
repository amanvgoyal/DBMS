#include <iostream>
#include "Database.h"
#include "Parser.h"
#include "Token.h"

using namespace std;

int main() {
	// Initialize Database class
	Database db;
	db.update_mat("nights_watch.db");
	db.update_mat("human.db");
	db.update_mat("old_people");

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
