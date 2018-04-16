//// User.h
#ifndef User_H

#define User_H

#include <string>
using namespace std;

class USER 

{

//constructor with default values if not provided
public:
USER(string = "need",string = "need",int = 0,int =0,int = 0); 
  

 //	USER (string inName, string inNickName, int inAge, int inDay, int inMonth);
       
	//********Get/Set
  	string getName();
	void setName(string inName);
   
    string getNickName();
	void setNickName(string inNickName);
        
	int getAge();
	void setAge(int inAge);

	int getBDay();
	void setBDay(int inBDay);

	int getBMonth();
	void setBMonth(int inMDay);
          
	//********member functions
	
	
public:
	string name;
    string nickName;
    int age;
    int bDay;
    int bMonth;
 

};

#endif
