// USER.cpp
#include "User.h"

USER::USER (string inName, string inNickName, int inAge, int inBDay, int inMDay)
{
  string name = inName;
  string nickName = inNickName; 
  int age = inAge;
  int bDay = inBDay;
  int mDay = inMDay;
  
  for (int i = 0; i<3; i++);
 
}

string USER::getName() {     return name;}
void USER::setName(string inName){ name = inName;}
   
string USER::getNickName() {return nickName;}
void USER::setNickName(string inNickName) {nickName = inNickName;}
        
int USER::getAge() {return age;}
void USER::setAge(int inAge) {age = inAge;}

int USER::getBDay() {return bDay;}
void USER::setBDay(int inBDay) {bDay = inBDay;}

int USER::getBMonth() {return bMonth;}
void USER::setBMonth(int inBMonth) {bMonth = inBMonth;}
