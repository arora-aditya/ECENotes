//
//  HomeworkQueue.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-11-19.
//
//

//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <stdio.h>
#include <time.h>
//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// struct definitions
//
#ifndef MARMOSET_TESTING

using namespace std;

enum COURSE {CHE102, MATH115, MATH117, ECE105, ECE150, ECE190, Null};

struct Assignment {
	COURSE course; // CHE102, MATH117, etc.
	int assnNum; // Assignment Number
	int dueMonth; // Month due (1-12)
	int dueDay; // Day due (1-31)
	char* description; // Assignment description

	void p(){
		cout<<course<<'\t'<<assnNum<<'\t'<<dueMonth<<'\t'<<dueDay<<"->";
	}
};

struct HomeworkQueue {
	Assignment* assn;
	HomeworkQueue* nextInQueue;
	void print(){
		cout<<(this->assn);
		HomeworkQueue* Copy = this;
		while(Copy->assn != NULL){
			(Copy->assn->p());
			Copy = Copy->nextInQueue;
		}
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
//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//

bool enqueue(HomeworkQueue*& queue, const Assignment& assignment);
const Assignment* dequeue(HomeworkQueue*& queue);
int daysTillDue(const HomeworkQueue* q, const COURSE course);
const Assignment* dueIn(const HomeworkQueue* q, const int numDays);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//

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

int isEarlier(Assignment assn1, Assignment assn2){
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

bool isEqual(Assignment assn1, Assignment assn2){
	return (assn1.course == assn2.course && assn2.dueMonth == assn1.dueMonth && assn2.dueDay == assn1.dueDay && assn1.assnNum == assn2.assnNum);
}

bool legalAssn(const Assignment assignment){
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

bool enqueue(HomeworkQueue*& queue, const Assignment& assignment) {
	if(legalAssn(assignment)){
		return false;
	}
	if(daysBetween(assignment.dueDay,assignment.dueMonth) < 0){
		return false;
	}
	Assignment * assignmentCopy = new Assignment;
	assignmentCopy->course = assignment.course;
	assignmentCopy->assnNum = assignment.assnNum;
	assignmentCopy->dueDay = assignment.dueDay;
	assignmentCopy->dueMonth = assignment.dueMonth;
	assignmentCopy->description = assignment.description;

	HomeworkQueue * transverse = queue;
	HomeworkQueue * previous = queue;
		if(transverse->assn != NULL){
			while(transverse != NULL){
				if(isEqual(*assignmentCopy, *transverse->assn)){
					return false;
				}
				transverse = transverse->nextInQueue;
			}
		}

	transverse = queue;
	HomeworkQueue* toInsert = new HomeworkQueue;
	toInsert->nextInQueue = NULL;
	toInsert->assn = assignmentCopy;

	bool isNotInserted = true;
	if(queue->nextInQueue == NULL && queue->assn == NULL){
		queue->assn = assignmentCopy;
		queue->nextInQueue = NULL;
		isNotInserted = false;
	}
	else{
		while(transverse != NULL){
			if(isEarlier(*assignmentCopy, *transverse->assn)){
				while(transverse != NULL && isEarlier(*assignmentCopy, *transverse->assn) == 2){
					previous = transverse;
					transverse = transverse->nextInQueue;
				}
				break;
			}
			previous = transverse;
			transverse = transverse->nextInQueue;
		}
		if(transverse == queue){
			toInsert->nextInQueue = queue;
			queue = toInsert;
			isNotInserted = false;
		}
		else{
			toInsert->nextInQueue = previous->nextInQueue;
			previous->nextInQueue = toInsert;
			isNotInserted = false;
		}
	}
	return !isNotInserted;
}

const Assignment* dequeue(HomeworkQueue*& queue) {
	if(queue == NULL){
	return NULL;
	}
	Assignment * assignment = queue->assn;
	HomeworkQueue * head = queue;
	queue = queue->nextInQueue;
	delete head;
	return assignment;
}

int daysTillDue(const HomeworkQueue* q, const COURSE course) {
	if(q == NULL || q->assn == NULL){
		return 2147483647;
	}
	HomeworkQueue * qCopy = new HomeworkQueue;
	qCopy->assn = q->assn;
	qCopy->nextInQueue = q->nextInQueue;
	if(qCopy->assn->course == course){
		int date = qCopy->assn->dueDay, month = qCopy->assn->dueMonth;
		// delete qCopy;
		return daysBetween(date, month) + 1;
	}
	while(qCopy->nextInQueue != NULL){
		// cout<<qCopy->assn->course<<endl;
		if(qCopy->assn->course == course){
			int date = qCopy->assn->dueDay, month = qCopy->assn->dueMonth;
			// delete qCopy;
			return daysBetween(date, month) + 1;
		}
		qCopy = qCopy->nextInQueue;
	}
	if(qCopy->assn->course == course) {
		int date = qCopy->assn->dueDay, month = qCopy->assn->dueMonth;
		// delete qCopy;
		return daysBetween(date, month) + 1;
	}
	delete qCopy;
	return 2147483647;
}

const Assignment* dueIn(const HomeworkQueue* q, const int numDays){
	if(q == NULL || numDays < 0 || q->assn == NULL){
		return NULL;
	}
	HomeworkQueue * qCopy = new HomeworkQueue;
	qCopy->assn = q->assn;
	qCopy->nextInQueue = q->nextInQueue;
	Assignment * A = new Assignment;
	A->course = Null;
	A->dueDay = -25;
	int size = 1;
	int date, month;

	while(qCopy != NULL && qCopy->assn != NULL){
		// cout<<qCopy->assn->course<<endl;
		int date = qCopy->assn->dueDay, month = qCopy->assn->dueMonth;
		// delete qCopy;
		if(daysBetween(date, month) < numDays){
			AssignmentAppend(qCopy->assn, A, size);
		}
		qCopy = qCopy->nextInQueue;
	}
	return A;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {
	// cout<<"here";
  		// Some test driver code here ....
	//std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;

	HomeworkQueue* p_queue = new HomeworkQueue;
	p_queue->assn = NULL;
	p_queue->nextInQueue = NULL;
  //
	// // cout<<daysBetween(20,12);
	char sampleDescription[] = "Sequential Execution";
	const Assignment * A = NULL;
	Assignment assn1 =
	{
		.course = ECE150,
		.assnNum = 8,
		.dueMonth = 11,
		.dueDay = 27,
		.description = "LMOA"
	};
	Assignment assn2 =
	{
		.course = ECE105,
		.assnNum = 8,
		.dueMonth = 11,
		.dueDay = 28,
		.description = "ECE105"
	};
	Assignment assn3 =
	{
		.course = MATH115,
		.assnNum = 0,
		.dueMonth = 11,
		.dueDay = 29,
		.description = "MATH115"
	};
	Assignment assn4 =
	{
		.course = MATH117,
		.assnNum = 0,
		.dueMonth = 11,
		.dueDay = 30,
		.description = "MATH117"
	};
	Assignment assn5 =
	{
		.course = ECE190,
		.assnNum = 0,
		.dueMonth = 12,
		.dueDay = 29,
		.description = "ECE190"
	};
	Assignment assn6 =
	{
		.course = CHE102,
		.assnNum = 0,
		.dueMonth = 12,
		.dueDay = 30,
		.description = "ECE190"
	};
	bool enqueueSuccess = enqueue(p_queue, assn1);
	cout<<enqueueSuccess<<'\n';
	enqueueSuccess = enqueue(p_queue, assn2);
	cout<<enqueueSuccess<<endl;
	enqueueSuccess = enqueue(p_queue, assn3);
	cout<<enqueueSuccess<<endl;
	enqueueSuccess = enqueue(p_queue, assn1);
	cout<<enqueueSuccess<<endl;
	enqueueSuccess = enqueue(p_queue, assn4);
	cout<<enqueueSuccess<<endl;
	enqueueSuccess = enqueue(p_queue, assn5);
	cout<<enqueueSuccess<<endl;
	enqueueSuccess = enqueue(p_queue, assn6);
	cout<<enqueueSuccess<<'\n';
	// // enqueueSuccess = enqueue(p_queue, assn5);
	// // cout<<enqueueSuccess<<'\n';
	// // enqueueSuccess = enqueue(p_queue, assn3);
	// // cout<<enqueueSuccess<<'\n';
  //
	// if(enqueueSuccess)
	// {
	// 	std::cout << "assn1 enqueued successfully" << std::endl << std::endl;
  //
	// }
	// else
	// {
	// 	std::cout << "enqueue() failed" << std::endl << std::endl;
	// }
	// cout<<daysTillDue(p_queue, ECE190);
  //
  //
	A = dueIn(p_queue,3);
	cout<<endl;
	cout<<(*(A)).dueDay<<'\t'<<(*(A+1)).dueDay<<'\t'<<(*(A+2)).dueDay<<'\t'<<(*(A+3)).dueDay<<'\t'<<(*(A+4)).dueDay<<'\t'<<(*(A+5)).dueDay<<'\t'<<(*(A+6)).dueDay<<'\n';
	delete A;
	// cout<<daysTillDue(p_queue, ECE150);
  //
  //
	// delete p_queue;
  //
	// return 0;
}

#endif
