/*Ahan Bandyopadhyay  Roll No.:211210008 CSE Second Year OOPS 4th Semester*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//static variables to be used across the program
static int n;
static int num_sbj;
static int countf;

//date structure defined
typedef struct Date{
    int day;
    int month;
    int year;
}Date;

//Base class containing general info
class Geninfo{
    string name;
    int rollno;
    Date d;
    char gender;
    int year;
    string branch;

public:
    //setter function
    void setInfo(string nm, int rn, Date dt, char gnd, int yr, string brn)
    {
        name = nm;
        rollno = rn;
        d = dt;
        gender = gnd;
        year = yr;
        branch = brn;
    }

    //display all the general info
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Roll no.: " << rollno << endl;
        cout << "Date of Birth: " << d.day << "/" << d.month << "/" << d.year << endl;
        cout << "Gender: " << gender << endl;
        cout << "Year of study: " << year << endl;
        cout << "Branch: " << branch << endl;
        cout << endl;
    }
};

//derived class
class Result:public Geninfo{
    int total = 0;

public:
    int *marks = new int[num_sbj];

    //input marks of each subject
    void getMarks(){
        for(int i = 0; i < num_sbj; i++)
        {
            cin >> marks[i];
        }
    }

    //display marks
    void displayMarks(){
        for(int i = 0; i < num_sbj; i++)
            cout << "Marks obtained in subject " << i+1 << " are " << marks[i] << endl;
        cout << endl;
    }

    //POLYMORPHISM OPERATOR OVERLOADING to calculate total marks of each student
    int operator+(){
        for(int i = 0; i < num_sbj; i++){
            total += marks[i];
        }

        return total;
    }
};

//function to find grades
void grading(int tmks){
    if(tmks > 90)
        cout << "Grade: A+" << endl;
    else if(tmks <= 90 && tmks > 80)
        cout << "Grade: A" << endl;
    else if(tmks <= 80 && tmks > 70)
        cout << "Grade: B" << endl;
    else if(tmks <= 70 && tmks > 60)
        cout << "Grade: C" << endl;
    else if(tmks <= 60 && tmks > 50)
        cout << "Grade: D" << endl;
    else if(tmks <= 50 && tmks > 35)
        cout << "Grade: E" << endl;
    else if(tmks <= 35)
        cout << "Grade: F" << endl;
}

//function to find out who all failed
void fail(int tmks){
    if (tmks <= 35){
        cout << "Failed!" << endl;
        countf++;
    }
}

//function to display top 10% students
void tenprc(int *arr){
    int *temp = new int[n];

    for(int i = 0; i < n; i++)
        temp[i] = arr[i];

    sort(temp, temp + n);

    for(int i = n - 1; i >= n - ceil(0.1*n); i--){
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == temp[i])
                cout << "Student " << j+1 << endl;
        }
    }
}

//main function block;
int main(){
   cout << "Welcome to Banergy Student Database" << endl;

   cout << "\nEnter the number of students in the database: " << endl;
   cin >> n;

   //array of object of class Result created
   Result *students = new Result[n];

   //input all data
   for(int i = 0; i < n; i++)
   {
        string nm;
        int rn;
        Date dt;
        char gnd;
        int yr;
        string brn;

        cout << "\nEnter Name, Roll no., Date of Birth, Gender(M/F/O), Year of Study, Branch: " << endl;
        cin >> nm >> rn >> dt.day >> dt.month >> dt.year >> gnd >> yr >> brn;

        students[i].setInfo(nm, rn, dt, gnd, yr, brn);
        cout << endl;
   }

    cout << "\nEntered database: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Student " << i+1 << ": " << endl;
        students[i].displayInfo();
    }

    cout << "\nEnter the no. of subjects: " << endl;
    cin >> num_sbj;

    cout << "\nEnter the marks obtained in " << num_sbj << " subjects: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i+1 << endl;
        students[i].getMarks();
    }

    for(int i = 0; i < n; i++)
    {
        cout << "\nMarks obtained by student " << i+1 << endl;
        students[i].displayMarks();
    }

    int *sum = new int[n];
    for(int i = 0; i < n; i++)
    {
        cout << "\nTotal marks obtained by student " << i+1 << ": ";
        sum[i] = +students[i];
        cout << sum[i] << "\t";

        grading(sum[i]/num_sbj);
        fail(sum[i]/num_sbj);
    }

    cout << "\nNo. of students failed: " << countf << endl;

    cout << "\nTop 10% students are: " << endl;
    tenprc(sum);

    return 0;
}
