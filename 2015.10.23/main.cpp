#include <iostream>
#include <fstream>

using namespace std;


struct StudentData
{

    int fn;
    char name[100];
};

void createStudents ()
{
    ifstream inpStud ("students.txt");
    ofstream outpStud2 ("studentsOut.txt");

    StudentData student;

    while (inpStud >> student.fn)
    {
        inpStud.getline (student.name,100);
        //cout << "Read student:" << student.name << endl;

        outpStud2<<student.fn;
        outpStud2<<student.name<<endl;

    }

}

int main()
{

    createStudents();
    
    return 0;
}
