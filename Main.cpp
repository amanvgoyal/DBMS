#include <iostream>
#include "Database.h"
#include "Parser.h"
#include "Token.h"

using namespace std;

int main(){
	Database d;
	d.update_mat();
	//d.show(d.selection("nights_watch", "death", "==", "y")); 
	table t1 = d.selection("nights_watch", "death", "==", "y");  
	table t2 = d.selection("nights_watch", "death", "==", "n");
	table t3 = d.selection("nights_watch", "broken_vows", "==", "y");
	//d.show(d.set_diff("nights_watch", "old_people"));
	cout << "Table 1\n";
	d.show(t1);
	cout << "Table 2\n";
	d.show(t2);
	cout << "Table 3\n";
	d.show(t3);
	cout << "Table 1 union Table 2\n";
	table t1_and_t2 = d.set_union(t1, t2);
	d.show(t1_and_t2);
	cout << "Table 1 cross product Table 2\n";
	table t1_cross_t3 = d.cross_product(t1, t3);
	d.show(t1_cross_t3);
	cout << "Table 1 projection of member and age\n";
	vector<string> attributes;
	attributes.push_back("member");
	attributes.push_back("age");
	table t1_proj = d.projection(t1, attributes);
	d.show(t1_proj);
	return 0;
}
