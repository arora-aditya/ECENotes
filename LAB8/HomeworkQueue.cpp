//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

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

struct Assignment
{
	COURSE course; // CHE102, MATH117, etc.
	int assnNum; // Assignment Number
	int dueMonth; // Month due (1-12)
	int dueDay; // Day due (1-31)
	char* description; // Assignment description
};

struct HomeworkQueue
{
	Assignment* assn;
	HomeworkQueue* nextInQueue;

	void print(){
		cout<<(this->assn);
		HomeworkQueue* Copy = this;
		while(Copy->assn != NULL){
			cout<<Copy->assn<<"->";
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

bool isEarlier(Assignment assn1, Assignment assn2){
	/*
	Is assignment1 due before assignment2?
	*/
  if(assn1.dueMonth > assn2.dueMonth){
    return true;
  }
  else if(assn1.dueMonth == assn2.dueMonth && assn1.dueDay > assn2.dueDay){
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

bool enqueue(HomeworkQueue*& queue, const Assignment& assignment)
{
  if(legalAssn(assignment)){
    return false;
  }
  bool isInserted = false;
  Assignment nullAssignment = {
                                .course = Null,
                                .assnNum = 0,
                                .dueMonth = 12,
                                .dueDay = 32,
                                .description = NULL
                              };
	Assignment assignmentCopy = {
                                .course = assignment.course,
                                .assnNum = assignment.assnNum,
                                .dueMonth = assignment.dueMonth,
                                .dueDay = assignment.dueDay,
                                .description = assignment.description
                              };
  HomeworkQueue* queueCopy = queue;
	HomeworkQueue* toInsert= new HomeworkQueue;
	toInsert->nextInQueue = NULL;
	toInsert->assn = &assignmentCopy;
  while(queueCopy->nextInQueue != NULL && !isInserted){
		if(isEarlier(assignment, *queueCopy->nextInQueue->assn)){
			toInsert->nextInQueue = queueCopy->nextInQueue;
			queueCopy->nextInQueue = toInsert;
			isInserted = true;
		}
		queueCopy = queueCopy->nextInQueue;
		cout<<(queueCopy->nextInQueue);
  }
	if(isInserted == false){
		toInsert->nextInQueue = queue;
		queue = toInsert;
		isInserted = true;
	}
	return isInserted;
}
const Assignment* dequeue(HomeworkQueue*& queue)
{
	return NULL;
}
int daysTillDue(const HomeworkQueue* q, const COURSE course)
{
	return -1;
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

	char sampleDescription[] = "Sequential Execution";
	Assignment assn1 =
	{
		.course = ECE150,
		.assnNum = 0,
		.dueMonth = 9,
		.dueDay = 15,
		.description = sampleDescription
	};

	Assignment assn2 =
	{
		.course = ECE150,
		.assnNum = 0,
		.dueMonth = 10,
		.dueDay = 15,
		.description = sampleDescription
	};

	Assignment assn3 =
	{
		.course = ECE150,
		.assnNum = 0,
		.dueMonth = 10,
		.dueDay = 10,
		.description = sampleDescription
	};

	bool enqueueSuccess = enqueue(p_queue, assn1);
	p_queue->print();
	enqueueSuccess = enqueueSuccess && enqueue(p_queue, assn2);
	p_queue->print();

	if(enqueueSuccess)
	{
		std::cout << "assn1 enqueued successfully" << std::endl << std::endl;

	}
	else
	{
		std::cout << "enqueue() failed" << std::endl << std::endl;
	}

	const Assignment* p_firstAssignmentInQueue = dequeue(p_queue);

	if (p_firstAssignmentInQueue)
	{
		std::cout << "Dequeue successful..." << std::endl;
		std::cout << "Course: " << p_firstAssignmentInQueue->course << std::endl;
		std::cout << "Assignment #: " << p_firstAssignmentInQueue->assnNum << std::endl;
		std::cout << "Day due: " << p_firstAssignmentInQueue->dueDay << std::endl;
		std::cout << "Month due: " << p_firstAssignmentInQueue->dueMonth << std::endl;
		std::cout << "Description: " << p_firstAssignmentInQueue->description << std::endl;
	}
	else
	{
		std::cout << "dequeue() failed" << std::endl;
	}

	delete p_queue;

	return 0;
}

#endif
