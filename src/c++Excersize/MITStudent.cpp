/*






 * MITStudent.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: indresh
 */


#include <iostream>


using namespace std;
MITStudent::MITStudent() {

 StudentId=0;
 name="";
}




//Why make a copy constructor? Assigning all fields
//(default copy constructor) may not be what you want
//
//So make own Copy Constructor
//
MITStudent::MITStudent(MITStudent &o){
 StudentId=o.StudentId;
 name=strdup(o.name);
}
int main(){
	MITStudent student;
	student.StudentId=10;
	char n[]="foo";
	student.name=n;
	MITStudent student2=student;
	student2.name[0]='b';
	cout<<student.name<<endl;// boo
	return 0;

}
