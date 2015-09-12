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
   table t2 = d.selection("nights_watch", "age", "==", "65");

   //   d.show(t1);
   d.show(t2);

   //       d.print_db();
 // d.show(d.set_diff("nights_watch", "old_people"));
   //d.renaming("name", "NAME");
}
  
