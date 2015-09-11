#include <iostream>
#include "Database.h"
#include "Parser.h"
#include "Token.h"

using namespace std;

int main(){
  Database d;
  //  d.update_mat();
  d.show(d.selection("nights_watch", "death", "==", "y")); 
}
