//
//  HomeworkClass.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-11-28.
//
//

//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <stdio.h>
#include <time.h>
#include <iostream>
//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

using namespace std;

//////////////////////////////////////////////////////////////
//
// struct definitions
//
#ifndef MARMOSET_TESTING

enum COURSE {CHE102, MATH115, MATH117, ECE105, ECE150, ECE190, Null};

struct Assignment {
	COURSE course; // CHE102, MATH117, etc.
	int assnNum; // Assignment Number
	int dueMonth; // Month due (1-12)
	int dueDay; // Day due (1-31)
	char* description; // Assignment description

	void p() const{
    if(this == NULL){
      return;
    }
		cout<<'('<<course<<","<<dueDay<<","<<dueMonth<<')'<<endl;
	}
};
#endif


bool AssignmentAppend(Assignment * A, Assignment*& R, int& size){
	Assignment* k = new Assignment [size + 1];
	int i;
	for(i = 0; i < size - 1; i++){
		k[i] = *(R + i);
	}
	k[i] = *A;
	k[i+1] = *(R + i);
	if(R != NULL){
		delete R;
	}
	R = k;
	size++;
	return true;
}

int daysBetween(int date, int month) {
	time_t now;
  struct tm AssignmentDate;
  double seconds;

  time(&now);  /* get current time; same as: now = time(NULL)  */

  AssignmentDate = *localtime(&now);

  AssignmentDate.tm_hour = 0; AssignmentDate.tm_min = 0; AssignmentDate.tm_sec = 0;
  AssignmentDate.tm_mon = month-1;  AssignmentDate.tm_mday = date;

  seconds = difftime(mktime(&AssignmentDate), now);
  return (int) seconds/86400;
}

int isEarlier(Assignment assn1, Assignment assn2) {
	/*
	Is assignment1 due before assignment2?
	*/
  if(assn1.dueMonth < assn2.dueMonth){
    return 1;
  }
  else if(assn1.dueMonth == assn2.dueMonth && assn1.dueDay < assn2.dueDay){
		return 1;
  }
	else if(assn1.dueMonth == assn2.dueMonth && assn1.dueDay == assn2.dueDay){
		return 2;
  }
	else{
		return 0;
	}
}

bool isEqual(Assignment assn1, Assignment assn2) {
	return (assn1.course == assn2.course && assn2.dueMonth == assn1.dueMonth && assn2.dueDay == assn1.dueDay && assn1.assnNum == assn2.assnNum);
}

bool legalAssn(const Assignment assignment) {
  switch(assignment.dueMonth){
    case 1:
    if(assignment.dueDay < 1 || assignment.dueDay > 31){
      return true;
    }
		break;
    case 2:
    if(assignment.dueDay < 1 || assignment.dueDay > 28){
      return true;
    }
		break;
    case 3:
    if(assignment.dueDay < 1 || assignment.dueDay > 31){
      return true;
    }
		break;
    case 4:
    if(assignment.dueDay < 1 || assignment.dueDay > 30){
      return true;
    }
		break;
    case 5:
    if(assignment.dueDay < 1 || assignment.dueDay > 31){
      return true;
    }
		break;
    case 6:
    if(assignment.dueDay < 1 || assignment.dueDay > 30){
      return true;
    }
		break;
    case 7:
    if(assignment.dueDay < 1 || assignment.dueDay > 31){
      return true;
    }
		break;
    case 8:
    if(assignment.dueDay < 1 || assignment.dueDay > 31){
      return true;
    }
		break;
    case 9:
    if(assignment.dueDay < 1 || assignment.dueDay > 30){
      return true;
    }
		break;
    case 10:
    if(assignment.dueDay < 1 || assignment.dueDay > 31){
      return true;
    }
		break;
    case 11:
    if(assignment.dueDay < 1 || assignment.dueDay > 30){
      return true;
    }
		break;
    case 12:
    if(assignment.dueDay < 1 || assignment.dueDay > 31){
      return true;
    }
		break;
    default: return true;
		break;
  }
  if(assignment.description == NULL || *assignment.description == '\0'){
    return true;
  }
	if(assignment.course == Null){
		return true;
	}
  return false;
}


class HomeworkQueue {
  public:
    bool enqueue(const Assignment& assignment){
      if(legalAssn(assignment)){
    		return false;
    	}
    	if(daysBetween(assignment.dueDay,assignment.dueMonth) < 0){
    		return false;
    	}
      return this->Append(assignment);
    }
    const Assignment * dequeue(){
      if(HEAD == NULL){
        return NULL;
      }
      Assignment * returnAssignment;
      if(size == 1){
        returnAssignment = &HEAD[0];
        HEAD = NULL;
        size--;
      }
      else{
        returnAssignment = &HEAD[0];
        Assignment * newHEAD = new Assignment[size - 1];
        for(int i = 0; i < size -1; i++){
          newHEAD[i] = HEAD[i+1];
        }
        delete [] HEAD;
        HEAD = newHEAD;
        size--;
      }
      return returnAssignment;
    }
    int daysTillDue(const COURSE course){
      if(HEAD == NULL){
        return 2147483647;
      }
      for(int i = 0; i < size; i++){
        if(HEAD[i].course == course){
          return daysBetween(HEAD[i].dueDay, HEAD[i].dueMonth) + 1;
        }
      }
      return 2147483647;
    }
    const Assignment * dueIn(const int numDays){
      Assignment * A = new Assignment;
    	A->course = Null;
    	A->dueDay = 32;
      int returnSize = 1;
      for(int i = 0; i < size; i++){
        if(daysBetween(HEAD[i].dueDay, HEAD[i].dueMonth) < numDays){
    			AssignmentAppend(&HEAD[i], A, returnSize);
    		}
      }
      return A;
    }
    HomeworkQueue(){
      HEAD = NULL;
      size = 0;
    }
    ~HomeworkQueue(){
      if(HEAD != NULL){
        delete[] HEAD;
      }
      size = 0;
    }
    void p(){
      cout<<'\n'<<"LIST: ";
      cout<<'\t'<<size;
      for(int i = 0; i < size; i++){
        cout<<"\t("<<(HEAD+i)->course<<","<<(HEAD+i)->dueDay<<','<<(HEAD+i)->dueMonth<<")\t";
      }
      cout<<endl;
    }
    private:
      Assignment * HEAD;
      int size;
      bool Append(const Assignment& assignment){
        Assignment * assignmentCopy = new Assignment;
        assignmentCopy->course = assignment.course;
        assignmentCopy->assnNum = assignment.assnNum;
        assignmentCopy->dueDay = assignment.dueDay;
        assignmentCopy->dueMonth = assignment.dueMonth;
        assignmentCopy->description = assignment.description;
        if(HEAD == NULL){
          HEAD = new Assignment [size + 1];
          HEAD[0] = *assignmentCopy;
          size++;
          return true;
        }
        else{
          for(int i = 0; i < size; i++){
            if(isEqual(*assignmentCopy, HEAD[i])){
              return false;
            }
          }
          if(isEarlier(*assignmentCopy, HEAD[0]) == 1){
            Assignment * newHEAD = new Assignment [size + 1];
            newHEAD[0] = *assignmentCopy;
            for(int i = 1; i < size+1; i++){
              newHEAD[i] = HEAD[i-1];
            }
            delete [] HEAD;
            HEAD = newHEAD;
            size++;
            return true;
          }
          Assignment * newHEAD = new Assignment [size + 1];
          int i = 0;
          for(i = 0; i < size && isEarlier(HEAD[i], *assignmentCopy) == 1; i++){
            newHEAD[i] = HEAD[i];
          }
          while(isEarlier(HEAD[i], *assignmentCopy) == 2){
            newHEAD[i] = HEAD[i];
            i++;
          }
          newHEAD[i] = *assignmentCopy;
          i++;
          for(; i < size+1; i++){
            newHEAD[i] = HEAD[i-1];
          }
          delete [] HEAD;
          HEAD = newHEAD;
          size++;
          return true;
        }
      }

};

#ifndef MARMOSET_TESTING
int main(){
  HomeworkQueue q;
  const Assignment * a;
  Assignment assn1 =
	{
		.course = ECE150,
		.assnNum = 8,
		.dueMonth = 12,
		.dueDay = 13,
		.description = "LMOA"
	};
	Assignment assn2 =
	{
		.course = ECE105,
		.assnNum = 8,
		.dueMonth = 12,
		.dueDay = 29,
		.description = "ECE105"
	};
	Assignment assn3 =
	{
		.course = MATH115,
		.assnNum = 0,
		.dueMonth = 12,
		.dueDay = 5,
		.description = "MATH115"
	};
	Assignment assn4 =
	{
		.course = MATH117,
		.assnNum = 0,
		.dueMonth = 12,
		.dueDay = 4,
		.description = "MATH117"
	};
	Assignment assn5 =
	{
		.course = ECE190,
		.assnNum = 0,
		.dueMonth = 12,
		.dueDay = 31,
		.description = "ECE190"
	};
	Assignment assn6 =
	{
		.course = CHE102,
		.assnNum = 0,
		.dueMonth = 12,
		.dueDay = 10,
		.description = "ECE190"
	};
  //enum COURSE {CHE102, MATH115, MATH117, ECE105, ECE150, ECE190, Null};

  q.enqueue(assn1);//ECE150

  q.enqueue(assn2);//ECE105

  q.enqueue(assn3);//MATH115

  q.enqueue(assn4);//ECE150

  q.enqueue(assn5);//MATH117

  q.enqueue(assn6);//CHE102


	q.dequeue()->p();
	q.dequeue()->p();
	q.dequeue()->p();
	q.dequeue()->p();
	q.dequeue()->p();
	q.dequeue()->p();
	q.dequeue()->p();

	q.p();


  cout.flush();

  return 0;
}

#endif
