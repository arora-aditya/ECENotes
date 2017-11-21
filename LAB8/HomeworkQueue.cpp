//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <stdio.h>
#include <string.h>
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

  seconds = difftime(now,mktime(&AssignmentDate));
  return (int) seconds/86400;
}

bool isEarlier(Assignment assn1, Assignment assn2){
	/*
	Is assignment1 due before assignment2?
	*/
  if(assn1.dueMonth < assn2.dueMonth){
    return true;
  }
  else if(assn1.dueMonth == assn2.dueMonth && assn1.dueDay < assn2.dueDay){
		return true;
  }
	else{
		return false;
	}
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
  if(assignment.description == NULL){
    return true;
  }
  return false;
}

bool enqueue(HomeworkQueue*& queue, const Assignment& assignment) {
  if(legalAssn(assignment)){
    return false;
  }
	int len = 0;
	Assignment *assignmentCopy = new Assignment;
		assignmentCopy->course = assignment.course;
		assignmentCopy->assnNum = assignment.assnNum;
		assignmentCopy->dueMonth = assignment.dueMonth;
		assignmentCopy->dueDay = assignment.dueDay;
		assignmentCopy->description = assignment.description;

	HomeworkQueue* queueCopy = queue;
	HomeworkQueue* toInsert= new HomeworkQueue;
	toInsert = new HomeworkQueue;
	toInsert->nextInQueue = NULL;
	toInsert->assn = assignmentCopy;

  bool isNotInserted = true;
	if(queue->nextInQueue == NULL && queue->assn == NULL){
		queue->assn = assignmentCopy;
		queue->nextInQueue = new HomeworkQueue;
		queue->nextInQueue->assn = NULL;
		queue->nextInQueue->nextInQueue = NULL;
	}
	else{
		while(queueCopy->nextInQueue->nextInQueue != NULL && isNotInserted){
			len++;
			if(isEarlier(assignment,*queueCopy->nextInQueue->assn)){
				toInsert->nextInQueue = queueCopy->nextInQueue;
			 	queueCopy->nextInQueue = toInsert;
			 	isNotInserted = false;
				break;
			}
			queueCopy = queueCopy->nextInQueue;
		}
		if(isEarlier(*queueCopy->assn, assignment) && isNotInserted){
			toInsert->nextInQueue = queueCopy->nextInQueue;
			queueCopy->nextInQueue = toInsert;
		 	isNotInserted = false;
		}
		if(isNotInserted){
			toInsert->nextInQueue = queue;
			queue = toInsert;
			isNotInserted = false;
		}
	}
	delete toInsert;
	// queue = queueCopy;
  return !isNotInserted;
}

const Assignment* dequeue(HomeworkQueue*& queue) {
	if(queue == NULL || (queue->nextInQueue) == NULL){
	return NULL;
	}
	Assignment * assignment = queue->assn;
	queue = queue->nextInQueue;
	return assignment;
}

int daysTillDue(const HomeworkQueue* q, const COURSE course) {
	if(q == NULL){
		return INT_MAX;
	}
	HomeworkQueue * qCopy = new HomeworkQueue;
	qCopy->assn = q->assn;
	qCopy->nextInQueue = q->nextInQueue;
	if(qCopy->assn->course == course){
		int date = qCopy->assn->dueDay, month = qCopy->assn->dueMonth;
		// delete qCopy;
		return daysBetween(date, month);
	}
	while(qCopy->nextInQueue->nextInQueue != NULL){
		if(qCopy->assn->course == course){
			int date = qCopy->assn->dueDay, month = qCopy->assn->dueMonth;
			// delete qCopy;
			return daysBetween(date, month);
		}
		qCopy = qCopy->nextInQueue;
	}
	if(qCopy->assn->course == course) {
		int date = qCopy->assn->dueDay, month = qCopy->assn->dueMonth;
		// delete qCopy;
		return daysBetween(date, month);
	}
	delete qCopy;
	return INT_MAX;
}
const Assignment* dueIn(const HomeworkQueue* q, const int numDays)
{
	return NULL;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {
  		// Some test driver code here ....
	//std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;

	HomeworkQueue* p_queue = new HomeworkQueue;
	p_queue->nextInQueue = NULL;
	p_queue->assn = NULL;
	// cout<<daysBetween(20,12);
	char sampleDescription[] = "Sequential Execution";
	Assignment assn1 =
	{
		.course = ECE150,
		.assnNum = 0,
		.dueMonth = 9,
		.dueDay = 15,
		.description = "ECE150"
	};

	Assignment assn2 =
	{
		.course = ECE105,
		.assnNum = 0,
		.dueMonth = 10,
		.dueDay = 15,
		.description = "ECE105"
	};

	Assignment assn3 =
	{
		.course = MATH115,
		.assnNum = 0,
		.dueMonth = 10,
		.dueDay = 10,
		.description = "MATH115"
	};

	Assignment assn4 =
	{
		.course = MATH117,
		.assnNum = 0,
		.dueMonth = 9,
		.dueDay = 15,
		.description = "MATH117"
	};

	Assignment assn5 =
	{
		.course = ECE190,
		.assnNum = 0,
		.dueMonth = 11,
		.dueDay = 15,
		.description = "ECE190"
	};

	bool enqueueSuccess = enqueue(p_queue, assn1);
	enqueueSuccess = enqueue(p_queue, assn2);
	enqueueSuccess = enqueue(p_queue, assn3);
	enqueueSuccess = enqueue(p_queue, assn4);
	enqueueSuccess = enqueue(p_queue, assn5);
	// p_queue->print();

	if(enqueueSuccess)
	{
		std::cout << "assn1 enqueued successfully" << std::endl << std::endl;

	}
	else
	{
		std::cout << "enqueue() failed" << std::endl << std::endl;
	}
	cout<<daysTillDue(p_queue, ECE190);
	// const Assignment* p_firstAssignmentInQueue = dequeue(p_queue);
  //
	// if (p_firstAssignmentInQueue)
	// {
	// 	std::cout << "Dequeue successful..." << std::endl;
	// 	std::cout << "Course: " << p_firstAssignmentInQueue->course << std::endl;
	// 	std::cout << "Assignment #: " << p_firstAssignmentInQueue->assnNum << std::endl;
	// 	std::cout << "Day due: " << p_firstAssignmentInQueue->dueDay << std::endl;
	// 	std::cout << "Month due: " << p_firstAssignmentInQueue->dueMonth << std::endl;
	// 	std::cout << "Description: " << p_firstAssignmentInQueue->description << std::endl;
	// }
	// else
	// {
	// 	std::cout << "dequeue() failed" << std::endl;
	// }
  //
  //

	delete p_queue;

	return 0;
}

#endif
