#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Student{
  char firstName[15];
  char lastName[15];
  int id;
  float gpa;
};
void addToList(vector<Student*> &students, Student* &newStudent);
void remove(vector<Student*> &students, int id);
void printOut(vector<Student*> students);
int main(){
  bool stillRunning = true;
  while (stillRunning == true){
    cout << "hi";
    vector<Student*> students;
    char add [4];
    add[0] = 'A';
    add[1] = 'D';
    add[2] = 'D';
    add[3] = '\0';
    char print [6];
    print[0] = 'P';
    print[1] = 'R';
    print[2] = 'I';
    print[3] = 'N';
    print[4] = 'T';
    print[5] = '\0';
    char remove [7];
    remove[0] = 'R';
    remove[1] = 'E';
    remove[2] = 'M';
    remove[3] = 'O';
    remove[4] = 'V';
    remove[5] = 'E';
    remove[6] = '\0';
    char quit [5];
    quit[0] = 'Q';
    quit[1] = 'U';
    quit[2] = 'I';
    quit[3] = 'T';
    quit[4] = '\0';

    char input[7];
    for(int i = 0; i < 7; i++){
      input[i] = '\0';
    }
  
    //Student steph
    cin.get(input, 15);
    cin.ignore(15, '\n');

    Student* newStudent = new Student();
    if(strcmp(input, add) == 0){
      cout << "Steph curry is on drugs";
      addToList(students, newStudent);
    }
    else if(strcmp(input, print) == 0){

      cout << "Levi Lao's GPA is unfortunately low";
      printOut(students);
    }
    else if(strcmp(input, remove) == 0){
      cout << "Remove";
    }
    else if(strcmp(input, quit) == 0){
      stillRunning = false;
    }
  }
 

}

void remove(vector <Student*> &students, int id){
  //vector <int> ::iterator iter = students.begin();

  



}
void printOut(vector<Student*> students){
  cout << "PRINT has been called";
  vector<Student*>::iterator ptr;
  for(ptr = students.begin(); ptr < students.end(); ptr++){
    cout << (*ptr)->id << endl;
  }
  
}
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
