#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct student {
    string name;
    int age;
    float average;
};

float average(vector<student> students) {
    float sum=0;
    float av;
    for (int i = 0;i < students.size();i++) {
        sum += students[i].average;
    }
    av = sum / students.size() ;
    return av;
}

int main()
{
    //declaration
    vector<student> students;
    int choice;
    bool exit = false;
    int n;
    string search;
    bool searching = false;
    int sindex;
    student best_student;
    bool found;




    

    //code:
    do {
        //main menu
        cout << "======Student management system======" << endl;
        cout << "1.Add student \n2.display students \n3.Search student \n4.Delete student \n5.Show best student \n6.Show class average \n7.Exit" << endl;
        cout << endl;
        cout << "choose : " << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "how many student are you going to add :" << endl;
            cin >> n;
            for (int i = 0;i < n; i++) {
                student s;
                cout << "student name :" << endl;
                cin >> s.name;
                cout << "student age : " << endl;
                do{
                    cin >> s.age;
                } while (s.age < 18 || s.age > 30);
                cout << "student average : " << endl;
                do{
                cin >> s.average;
                } while (s.average < 0 || s.average > 20);
                students.push_back(s);
            }
            break;
        case 2:
            for (int j = 0;j < students.size();j++) {
                cout << "student name : " << students[j].name <<" ; age :"<<students[j].age<<" ; average : "<<students[j].average << endl;

            }
            break;
        case 3:
            if(students.empty()==0){
            cout << "enter the name of the student you are searching for: " << endl;
            cin >> search;
            found = false;
            for (int i = 0;i < students.size();i++) {
                if (students[i].name == search) {
                    cout << "student found" << endl;
                    cout<< "student name : " << students[i].name << " ; age :" << students[i].age << " ; average : " << students[i].average <<" ; index :"<<i << endl;
                    found = true;
                }  
            }
            if (!found) {
                cout << "student not found" << endl;
            }
            }
            else { cout << "the class is empty"<<endl; }
            
            break;
        case 4:
            if (students.empty() == 0) {
            cout << "give the student index :" << endl;
            cin >> sindex;
            if (sindex >= 0 && sindex < students.size()) {
                students.erase(students.begin() + sindex);
            }
            else { cout << "index invalide"; }
            }
            else { cout << "the class is empty"<<endl; }
            break;
        case 5:
            if (students.empty() == 0) {
            best_student=students[0];
            for (int i = 1;i < students.size();i++) {
                if (students[i].average > best_student.average) {
                    best_student = students[i];
                }
            }
            cout << "best student : " << endl;
            cout << "Name : " << best_student.name <<" ; age : "<<best_student.age << " ; average : " << best_student.average << endl;
            }
            else { cout << "the class is empty"<<endl; }
            break;
        case 6:
            if (students.empty() == 0) {
            cout << "calss average : " << average(students) << endl;
            }
            else { cout << "the class is empty"<<endl; }
            break;
        case 7:
            exit = true;
            break;
        }



    } while (exit == false);

}

