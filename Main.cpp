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
  
}
  
