#include <iostream>
using namespace std;

struct SNode {
    int SNO;
    SNode* SNext;

    SNode(int id) {
        SNO = id;
        SNext = nullptr;
    }
};

struct CNode {
    int CNO;
    CNode* CNext;
    SNode* SList;   

    CNode(int id) {
        CNO = id;
        CNext = nullptr;
        SList = nullptr;
    }
};

CNode* Clist = nullptr;


void insertCourse(int id) {

    CNode* newCourse = new CNode(id);

    if (!Clist) {
        Clist = newCourse;
    }
    else {
        CNode* temp = Clist;
        while (temp->CNext)
            temp = temp->CNext;

        temp->CNext = newCourse;
    }

    cout << "Course " << id << " added.\n";
}


// -------- Insert Student --------
void insertStudent(int sno, int targetCourse) {

    CNode* course = Clist;

    // Find course
    while (course && course->CNO != targetCourse)
        course = course->CNext;

    if (!course) {
        cout << "Course not found!\n";
        return;
    }

    SNode* newStudent = new SNode(sno);

   
    newStudent->SNext = course->SList;
    course->SList = newStudent;

    cout << "Student " << sno << " added to Course " << targetCourse << endl;
}


void display() {

    CNode* ctemp = Clist;

    while (ctemp) {

        cout << "Course " << ctemp->CNO << ": ";

        SNode* stemp = ctemp->SList;

        while (stemp) {
            cout << stemp->SNO << " -> ";
            stemp = stemp->SNext;
        }

        cout << "NULL\n";
        ctemp = ctemp->CNext;
    }
}



int main() {

    insertCourse(101);
    insertCourse(102);

    insertStudent(1, 101);
    insertStudent(2, 101);
    insertStudent(3, 102);

    display();

    return 0;
}
