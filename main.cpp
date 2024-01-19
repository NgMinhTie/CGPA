#include "main.h"

/**
 * FOR NODE IMPLEMENT
*/

Node::Node(Student* student){
    this->student = student;
    this->next = nullptr;
}

Node* Node::getNext(){
    return this->next;
}

Student* Node::getStudent(){
    return this->student;
}

/**
 * FOR LINKLIST IMPLEMENT
*/


Student* LinkList::getStudent(){
    return this->head->getStudent();
}

Node* LinkList::insertNode(Student* student){
    
    if(head == nullptr){
        head = new Node(student);
        return head;
    }
        
    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Node(student);
    return head;
}

Node* LinkList::getList(){
    if(head == nullptr)
        return nullptr;
    return this->head;
}

/**
 * FOR COURSE IMPLEMENT
*/
Course :: Course (Course* course){
    this->nameCourse = course->nameCourse;
    this->credits = course->credits;
    this->score_30 = course->score_30;
    this->score_20 = course->score_20;
    this->score_50 = course->score_50;
    this->next = nullptr;
}
Course::Course(){
    this->next = nullptr;
}
CourseList::CourseList(){
    this->head = nullptr;
}

Course* CourseList::insertNode(Course* course){
    if(this->head == nullptr){
        head = new Course(course);
        return head;
    }

    Course *temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new Course(course);
    return head;
}
void Course::setVariable(string line){
    string temp = "";
    int i = 0;
    for (; i < line.length(); i++){
        if(line[i] == ',')
            break;
        temp += line[i];
    }
    this->nameCourse = temp;
    temp = "";
    i += 1;
    for (; i < line.length();i++){
        if (line[i] == ',')
            break;
        temp += line[i];
    }
    this->credits = stoi(temp);
    temp = "";
    i += 1;
    for (; i < line.length(); i++)
    {
        if (line[i] == ',')
            break;
        temp += line[i];
    }
    this->score_20 = stof(temp);
    temp = "";
    i += 1;
    for (; i < line.length(); i++)
    {
        if (line[i] == ',')
            break;
        temp += line[i];
    }
    this->score_30 = stof(temp);
    temp = "";
    i += 1;
    for (; i < line.length(); i++)
    {
        if (line[i] == ',')
            break;
        temp += line[i];
    }
    this->score_50 = stof(temp);
    
    ////cout << this->credits << " " << this->nameCourse << " " << this->score_20 << " " << this->score_30 << " " << this->score_50 << endl;
}

Course* CourseList::getList(){
    return this->head;
}

string Course::getName(){
    return this->nameCourse;
}
int Course::getCredits(){
    return this->credits;
}
float Course::TotalScore(){
    return (this->score_20*20 + this->score_30*30 + this->score_50*50)/100;
}
/**
 * FOR STUDENT IMPLEMENT
*/
Student::Student(){
    this->name = "";
    this->numberOfCourses = 0;
    this->course = nullptr;
    this->TotalCredit = 0;
}
string Student::getNameStu(){
    return this->name;
}
void Student::courselist(){
    this->course = new CourseList();
}
void Student ::setNameStu(string line){
    cout << line << endl;
    string result = "";
    for (int i = 0; i < line.length(); i++){
        if(line[i] == ',')
            break;
        result += line[i];
    }

    this->name = result;
    ////cout << this->name;
}
void Student::setNumCourse(string line){
    int result = 0;
    size_t commaPos = line.find(',');
    if(commaPos != string::npos){
        string temp = line.substr(commaPos + 1);
        result = stoi(temp);
        this->numberOfCourses = result;
    }
}
int Student :: getNumCourse(){
    return this->numberOfCourses;
}

void Student::setUpCourse(string line){
    Course *temp = new Course();
    temp->setVariable(line);
    this->course->insertNode(temp);
    this->setTotalCredit(temp);
}

void Student::setTotalCredit(Course* course){
    this->TotalCredit += course->getCredits();
}
int Student :: getTotalCredits(){
    return this->TotalCredit;
}

CourseList* Student::getCourse(){
    return this->course;
}
/**
 * FOR IMPLEMENTATION implement
*/

void Implementation::print(LinkList* node){
    ofstream outputFile("C:/Users/Admin/Personal_Projects/Basic/CGPA/output.txt");
    if(outputFile.is_open()){
    Node *temp = node->getList();
    while(temp!=nullptr){
        outputFile << "--------------------" << endl;
        outputFile << "Student'name: " 
            << temp->getStudent()->getNameStu() 
            << endl;
        outputFile << "The total credits "
                   << temp->getStudent()->getNameStu()
                   << " finish are: "
                   << temp->getStudent()->getTotalCredits()
                   << endl;
        outputFile << setw(30) << std::left << "The Subject'name"
                   << setw(30) << "The numbers of Credits"
                   << setw(30) << "The Average Score" << endl;
        int num = temp->getStudent()->getNumCourse();
        Course *tep = temp->getStudent()->getCourse()->getList();
        for (int i = 0; i < num; i++){
            outputFile << setw(30) << tep->getName()
                       << setw(30) << tep->getCredits()
                       << setw(30) << tep->TotalScore() << endl;
            tep = tep->next;
        }
        temp = temp->getNext();
    }
    }
    outputFile.close();
}
void Implementation::readOutput(LinkList* list){
    Student **student;
    ifstream inputFile("C:/Users/Admin/Personal_Projects/Basic/CGPA/input.txt");
    if (inputFile.is_open())
    {
        ////stringstream ss;
        string line;
        int numStudent = 0;
        if (getline(inputFile, line))
        {
            // ss << line;
            // string word;
            // ss >> word;
            numStudent = stoi(line);
            // ss.str("");
        }
        ////line = "";
        student = new Student *[numStudent];
        for (int i = 0; i < numStudent; i++)
        {
            //cout << 1;
            student[i] = new Student();
            if (getline(inputFile, line))
            {
                student[i]->setNameStu(line);
                ////cout << student[i]->getNameStu();
                student[i]->setNumCourse(line);
                ////cout << student[i]->getNumCourse();
            }
            student[i]->courselist();
            int numCourse = student[i]->getNumCourse();
           
            for (int j = 0; j < numCourse; j++){
                if(getline(inputFile, line))
                    {
                        student[i]->setUpCourse(line);
                    }
            }
            
            list->head = list->insertNode(student[i]);
        }
    }
    inputFile.close();
}
int main(){
    /**
     * Read file
    */
    Implementation *implement = new Implementation();
    LinkList *list = new LinkList();
    implement->readOutput(list);
    implement->print(list);
    return 0;
}