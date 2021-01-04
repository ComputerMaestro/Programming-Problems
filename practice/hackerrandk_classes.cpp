#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <numeric>
class Person
{
    protected:
    char name[100];
    int age;
    
    public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person
{
    int publications;
    int id;
    static int cur_id;
    
    public:
    void getdata();
    void putdata();
    Professor()
    {
        cur_id++;
        id = cur_id;
    }
};

class Student : public Person
{
    int marks[6];
    int id;
    static int cur_id;
    
    public:
    void getdata();
    void putdata();
    Student()
    {
        cur_id++;
        id = cur_id;
    }
};

void Professor::getdata()
{
    scanf("%s %d %d", name, &age, &publications);
}

void Student::getdata()
{
    cin >> name;
    cin >> age;
    for(int i = 0; i< 6; i++){cin >> marks[i];}
}

void Professor::putdata()
{
    printf("%s %d %d %d\n", name, age, publications, id);
}

void Student::putdata()
{
    int sum = 0;
    printf("%s %d %d %d\n", name, age, accumulate(marks, marks+6, sum), id);
}

int Professor::cur_id;
int Student::cur_id;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
