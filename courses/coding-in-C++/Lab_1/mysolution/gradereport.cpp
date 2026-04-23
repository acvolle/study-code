#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <iomanip>


using namespace std;

void readStudentData(string &name, int_least16_t &homework, int_least16_t &midterm, int_least16_t &finalExam){
    
    int homeworkInput = 0;
    int midtermInput = 0;
    int finalInput= 0;
    finalExam = -1;

    cout << "Enter student name: ";
    getline(cin, name);
    

    cout << "Enter homework grade: ";
    cin >> homeworkInput;
    if(!cin.fail() && (homeworkInput >= 0) && (homeworkInput <= 100)){
        homework = homeworkInput;
    } else{
        cout << "Fail"; 
        return;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Enter midterm grade: ";
    cin >> midtermInput;
    if(!cin.fail() && (midtermInput >= 0) && (midtermInput <= 100)){
        midterm = midtermInput;
    } else{
        cout << "Fail"; 
        return;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Enter final exam grade: ";
    cin >> finalInput;
    if(!cin.fail() && (finalInput >= 0) && (finalInput <= 100)){
        finalExam = finalInput;
    } else{
        cout << "Fail"; 
        return;
    }

}

void calculateGrade(int homework, int midterm, int finalExam, double &finalGrade, string &letterGrade){
    double tempGrade = 0;
    tempGrade += (40*homework);
    tempGrade += (25*midterm);
    tempGrade += (35*finalExam);
    tempGrade = (tempGrade / 100);
    finalGrade = tempGrade;

    if(finalGrade < 50){
        letterGrade = "F";
    } else if(finalGrade < 60){
        letterGrade = "E";
    } else if(finalGrade < 70){
        letterGrade = "D";
    } else if(finalGrade < 80){
        letterGrade = "C";
    } else if(finalGrade < 90){
        letterGrade = "B";
    } else {
        letterGrade = "A";
    }
}

void printReport(string name, int homework, int midterm, int finalExam, double finalGrade, string letterGrade){
    
    cout << "-------------------------------------" << endl;
    cout << "Student Report" << endl;
    cout << "-------------------------------------" << endl;

    cout << std::left << setw(20) << "Name: " << name << endl << endl;
    cout << "Scores" << endl;
    cout << "-------------------------------------" << endl;

    
    std::cout << std::left << std::setw(20) << "Homework" << ": "
    << std::fixed << std::setprecision(2) << static_cast<double>(homework) << std::endl;
    std::cout << std::left << std::setw(20) << "Midterm" << ": "
    << std::fixed << std::setprecision(2) << static_cast<double>(midterm) << std::endl;
    std::cout << std::left << std::setw(20) << "Final Exam" << ": "
    << std::fixed << std::setprecision(2) << static_cast<double>(finalExam) << std::endl << std::endl;

    
    std::cout << std::left << std::setw(20) << "Final Grade" << ": "
              << std::fixed << std::setprecision(2) << finalGrade << std::endl;
    std::cout << std::left << std::setw(20) << "Letter Grade" << ": " << letterGrade << std::endl;

    string status;

    if(letterGrade == "A" || (letterGrade == "B") || (letterGrade == "C")){
        status = "Pass";
    } else if( letterGrade == "D" || (letterGrade == "E")){
        status = "COnditional Pass";

    } else {
        status = "Fail";
    }
    std::cout << std::left << std::setw(20) << "Status" << ": " << status << std::endl;

    // Print footer
    std::cout << "-------------------------------------" << std::endl;

    
}

int main(){
    string name;
    int_least16_t homework;
    int_least16_t midterm;
    int_least16_t finalExam;
    double finalGrade;
    string letterGrade;
    readStudentData(name, homework, midterm, finalExam);
    
    if(finalExam == -1){
        return 0;
    }

    calculateGrade(homework, midterm, finalExam, finalGrade, letterGrade);

    printReport(name, homework, midterm, finalExam, finalGrade, letterGrade);


   

}

