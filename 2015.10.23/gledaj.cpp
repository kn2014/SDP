
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
    ifstream StudBinI ("binaryout.bin",ios::binary);
    ofstream StudBinO ("binaryout.bin",ios::binary);

    ofstream outpStud ("studentsOut.txt");


    StudentData student;

    StudentData student2;

    while (inpStud >> student.fn)
    {
        inpStud.getline (student.name,100);
        cout << "Read stundet:" << student.name << endl;

        StudBinO.write (reinterpret_cast<const char*>(&student),sizeof(StudentData));
        StudBinO.seekp (sizeof(StudentData),ios::cur);


        StudBinI.read((char*)&student2,sizeof(StudentData));
        StudBinI.seekg(sizeof(StudentData),ios::cur);




        cout<<student2.fn<<" "<<student2.name<<endl;

        outpStud<<student.fn;
        outpStud<<student.name<<endl;

    }



    outpStud.seekp(0,ios::end);
    //cout << "Number of all records =" << outpStud.tellp()/sizeof(StudentData) << endl;

    bool flag = true;
//    StudBin.seekg(0,ios::end);
   // int end = StudBin.tellg();
//
//    while (flag)
//    {
//       StudBin.seekg(0,ios::beg);
//       StudBin.read(reinterpret_cast<char*>(&student2),sizeof(StudentData));
//       StudBin.seekg(sizeof(StudentData),ios::cur);
//       cout<<student2.fn<<" "<<student2.name<<endl;
//        if(StudBin.tellg()>=end) {
//                flag = false;
//        }
//        else
//        {
//
//            outpStud<<student2.fn;
//            outpStud<<student2.name;
//        }
//    }


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

void createGrades ()
{
    ifstream inp ("grades.txt");
    ofstream outp ("grades.bin",ios::binary);

    GradeData gr;


    while (inp >> gr.studentFn)
    {
        inp >> gr.subjectCode >> gr.d >> gr.m >> gr.y >> gr.value;
        //cout << "Read grade of:" << gr.studentFn << endl;

        outp.write ((char*)&gr,sizeof(GradeData));

    }



}

int main()
{

    createStudents();
    createSubjects();
    createGrades();

    return 0;
}

