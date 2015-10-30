#include <iostream>
#include <fstream>

using namespace std;


struct StudentData
{

    int fn;
    char name[100];
};

struct SubjectData
{
  int code;
  char name[100];
  char teacher[100];

};

struct GradeData
{
  int studentFn, subjectCode;
  int d,m,y;
  double value;

};

void createStudents ()
{
    ifstream inpStud ("students.txt");
    ofstream StudBinO ("binaryout.bin",ios::binary);

    StudentData student;

    while (inpStud >> student.fn)
    {
        inpStud.getline (student.name,100);
        cout << "Read stundet:" << student.name << endl;

        StudBinO.seekp((student.fn-1000)*sizeof(StudentData));
        StudBinO.write ((char*)&student,sizeof(StudentData));
    }

    inpStud.close();
}

void readStudent(int fn,ostream& outpStud )
{
        StudentData student;
        ifstream StudBinI ("binaryout.bin",ios::binary);

        StudBinI.seekg((fn-1000)*sizeof(StudentData));
        StudBinI.read((char*)&student,sizeof(StudentData));


        outpStud<<student.fn;
        outpStud<<student.name<<endl;

        StudBinI.close();



}


void createSubjects ()
{

    ifstream inpSubj ("subjects.txt");
    ofstream outpSubj ("subjects.bin",ios::binary);

    SubjectData subj;

    while (inpSubj >> subj.code)
    {
        inpSubj.getline (subj.name,100);
        inpSubj.getline (subj.teacher,100);
        //cout << "Read subject:" << subj.name << endl;

        outpSubj.seekp (subj.code*sizeof(SubjectData));
        outpSubj.write ((char*)&subj,sizeof(SubjectData));

    }


}


int main()
{
    ofstream outpStud ("studentsOut.txt");

    createStudents();
    createSubjects();

    readStudent(1000,outpStud);
    readStudent(1002,outpStud);

    outpStud.close();
    return 0;
}
