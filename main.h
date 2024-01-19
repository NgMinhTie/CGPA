#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;
class Node;
class Student;
class LinkList;
class Implementation;

class Course{
    private:
        string nameCourse;
        int credits;
        float score_30;
        float score_20;
        float score_50;
        Course *next;
    public:
        //Course(string nameCourse, int credits, int score_30, int score_20, int score_50);
        Course(Course *course);
        Course();
        void setVariable(string line);
        string getName();
        //void setCredits(string line);
        int getCredits();
        //void setTotalScore(string line);
        float TotalScore();
        friend class CourseList;
        friend class Implementation;
};

class CourseList{
    private:
        Course *head;
    public:
        CourseList();
        Course *insertNode(Course *course);
        Course *getList();
};

class Student{
    private:
        string name;
        int numberOfCourses;
        CourseList *course;
        int TotalCredit;

    public:
        Student();
        string getNameStu();
        void setNameStu(string line);
        void setNumCourse(string line);
        int getNumCourse();
        void setUpCourse(string line);
        CourseList *getCourse();
        void setTotalCredit(Course* course);
        int getTotalCredits();
        void courselist();
        //Course *getCourse();
};

class Node{
    private:
        //Course *course;
        Student *student;
        Node *next;
    public:
        Node(Student* student);
        Student *getStudent();
        Node *getNext();
        friend class LinkList;
};

class LinkList{
    private:
        Node *head;
    public:
        //LinkList();
        Student *getStudent();
        Node *insertNode(Student *student);
        ////Node *deleteNode(Node *head, Student *student);
        Node *getList();
        friend class Implementation;
};

class Implementation{
    private:
        LinkList *node;
    public:
        void readOutput(LinkList* list);
        void print(LinkList* node);
};
