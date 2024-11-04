#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "getanA.hpp"
using namespace std;

int main () {

 Gradebook gradebook;

    gradebook.addStudent("Alec", "Carver", "21509");
    gradebook.addStudent("John", "Johnson", "32209");
    gradebook.addStudent("Sam", "Sammson", "92544");

    gradebook.addAssignment("You get an A lab", 100);
    gradebook.addAssignment("Tic tac toe project", 150);

    gradebook.addGrade("21509", "You get an A lab", 95);
    gradebook.addGrade("32209", "You get an A lab", 81);
    gradebook.addGrade("92544", "You get an A lab", 64);

    gradebook.addGrade("21509", "Tic tac toe project", 108);
    gradebook.addGrade("32209", "Tic tac toe project", 113);
    gradebook.addGrade("92544", "Tic tac toe project", 144);

    gradebook.printReport();

    return 0;
}
