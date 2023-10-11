/*
Author: Vikram Vasudevan
Date: 10/11/2023
Description: This program allows users to input students, and their corresponding ids and gpas. Those values can be printed out or removed
from the list.

*/
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

//Student struct
struct Student{
  char firstName[15];
  char lastName[15];
  int id;
  float gpa;
};
//initializing functions
void addToList(vector<Student*> &students, Student* &newStudent);
void demolish(vector<Student*> &students, int id);
void printOut(vector<Student*> students);
//main
int main(){
  bool stillRunning = true;
  //vector of student pointers
  vector<Student*> students;
  while (stillRunning == true){
    //prompt user to begin one of the functions
    cout << "Enter 'ADD', 'PRINT', 'REMOVE', or 'QUIT'" << endl;
    char input[15];
    for(int i = 0; i < 7; i++){
      input[i] = '\0';
    }
    cin.get(input, 15);
    cin.ignore(15, '\n');
    //create a new instance of the struct and assign a pointer to it.
    Student* newStudent = new Student();
    //calling functions
    if(strcmp(input, "ADD") == 0){
      addToList(students, newStudent);
    }
    else if(strcmp(input, "PRINT") == 0){

      printOut(students);
    }
    else if(strcmp(input, "REMOVE") == 0){
      cout << "Enter the id of the student you'd like to remove: " << endl;
      int tempID = 0;
      cin >> tempID;
      cin.get();
      demolish(students, tempID);
    }
    //ends program
    else if(strcmp(input, "QUIT") == 0){
      stillRunning = false;
    }
    else{
      cout << "Please enter a valid input: " << endl;
    }
  }
 

}

//this function removes a student from the list.
void demolish(vector <Student*> &students, int id){
  vector <Student*> ::iterator iter = students.begin();
  //iterate through the vector to find the student with the corresponding id.
  for(iter = students.begin(); iter < students.end(); iter++){
    if((*iter) ->id == id){
      //delete the student that the iterator is pointing to, and delete its space in the vector
      delete *iter;
      students.erase(iter);
      return;
    }

    
  }
 
}

//this function prints out the list of students
void printOut(vector<Student*> students){
  vector<Student*>::iterator ptr;
  for(ptr = students.begin(); ptr < students.end(); ptr++){
    cout<< "Name: " << (*ptr)->firstName << " " << (*ptr) -> lastName << endl;
    cout << "ID: "<< (*ptr)->id << endl;
    cout << "GPA: "<< fixed << setprecision(2) << (*ptr)->gpa << endl;
  }
  
}

//this function prompts users to enter information about a new student
void addToList(vector<Student*> &students, Student* &newStudent){
  cout << "Enter the student's first name" << endl;
  char inputFirstName[15];
  char inputLastName[15];
  
  for(int i = 0; i < 15; i++){
    inputFirstName[i] = '\0';
    inputLastName[i] = '\0';
  }
  cin.get(inputFirstName, 15);
  cin.get();
  cout << "Enter the student's last name" << endl;
  cin.get(inputLastName, 15);
  cin.get();

  strcpy(newStudent->firstName, inputFirstName);
  strcpy(newStudent->lastName, inputLastName);

  cout << "Enter the student's id number" << endl;
  int id = 0;
  cin >> id;

  newStudent->id = id;

  cout << "Enter the student's GPA" << endl;
  float gpa;
  cin >> gpa;

  cin.get();
  newStudent ->gpa = gpa;
  
  students.push_back(newStudent);
  return;

}
