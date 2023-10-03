#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Student{
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};

int main(){
  Student* kevin = new Student;
  kevin.id = 3;
  vector<Student*> info;
  info.push_back(kevin);
  cout << info.at(0).id<<endl;
  bool stillRunning = true;
  while (stillRunning == true){
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
    cin.get(input, 20);
    cin.get();

    if(strcmp(input, add) == 0){
      cout << "Steph curry is on drugs";
    }
    else if(strcmp(input, print) == 0){
      cout << "Kevin Yu's GPA is unfortunately low";
    }
    else if(strcmp(input, remove) == 0){
      cout << "Remove";
    }
    else if(strcmp(input, quit) == 0){
      cout << "Quit";
      stillRunning = false;
    }
  }
 


}
