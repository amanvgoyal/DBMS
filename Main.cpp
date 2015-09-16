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
	db.update_mat("old_people.db");
	db.update_mat("dead_nw.db");
	db.update_mat("white_walker.db");

	// Test selection

	// Test projection
	cout << "project from nights_watch the member, broken_vows, and age\n";
	vector<string> projection_list;
	projection_list.push_back("member");
	projection_list.push_back("broken_vows");
	projection_list.push_back("age");
	table proj_test = db.projection("nights_watch", projection_list);
	db.show(proj_test);

	// Test renaming

	// Test set_union
	cout << "set_union of nights_watch and old_people\n";
	table union_test = db.set_union("nights_watch", "old_people");
	db.show(union_test);

	// Test set_diff

	// Test cross_product
	cout << "cross_product of human and nights_watch\n";
	table cross_product = db.cross_product("human", "nights_watch");
	db.show(cross_product);

	// Test close

	// Test save
	cout << "save union_test\n";
	db.save(union_test, "union_test");

	// Test delete_table
	cout << "delete_table union_test (if save failed, this should fail as well)\n";
	db.delete_table("union_test");

	// Test update
	// Test "=="
	cout << "update from old_people where death == n";
	vector<string> attributes;
	vector<string> values;
	attributes.push_back("age");
	values.push_back("85");
	db.update("old_people", "death", "==", "n", attributes, values);
	// Test "!="
	cout << "update from old_people where death != n";
	attributes.push_back("age");
	values.push_back("85");
	db.update("old_people", "death", "==", "n", attributes, values);
	// Test "<"
	cout << "update from old_people where age < 55";
	attributes.clear();
	values.clear();
	attributes.push_back("brother");
	values.push_back("n");
	attributes.push_back("broken_vows");
	values.push_back("n");
	db.update("old_people", "age", "<", "55", attributes, values);
	// Test ">"
	cout << "update from old_people_where age > 55";
	db.update("old_people", "age", ">", "55", attributes, values);
	// Test "<="
	cout << "update from old_people_where age <= 55";
	db.update("old_people", "age", "<=", "55", attributes, values);
	// Test ">="
	cout << "update from old_people_where age >= 55";
	db.update("old_people", "age", ">=", "55", attributes, values);

	// Test create
	cout << "create table with name, nationality, and age\n";
	attributes.clear();
	attributes.push_back("name");
	attributes.push_back("nationality");
	attributes.push_back("age");
	table create_test = db.create(attributes);
	db.show(create_test);

	// Test insert_tuple
	cout << "insert into the newly created table\n";
	table tuples;
	vector<string> names;
	vector<string> nationalities;
	vector<string> ages;
	names.push_back("Ovidio");
	names.push_back("Aman");
	names.push_back("Haris");
	names.push_back("Ronilo");
	nationalities.push_back("Salvadoran");
	nationalities.push_back("Indian");
	nationalities.push_back("Pakistani");
	nationalities.push_back("U.S. Citizen");
	ages.push_back("20");
	ages.push_back("20");
	ages.push_back("21");
	ages.push_back("19");
	tuples["name"] = names;
	tuples["nationalities"] = nationalities;
	tuples["age"] = ages;
	db.insert_tuple(create_test, tuples);
	db.show(create_test);

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


