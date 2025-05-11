#include <iostream> 
#include <algorithm> 
#include <string>  
using namespace std; 
class Student {  
public: 
int dob; 
long tel; 
string name; 
void input() { 
cout << "Enter Name: "; 
getline(cin, name);  
cout << "Enter Birth date: "; 
cin >> dob; 
cout << "Enter telephone: "; 
cin >> tel; 
cin.ignore(); 
} 
void display() { 
cout << name << " " << dob << " " << tel << endl; 
} }; 
bool compareName(const Student& s1, const Student& s2) {  
return s1.name < s2.name; 
} 
int main() { 
Student students[10];  
string nameToSearch; 
int n; 
cout << "Enter the number of students (up to 10): "; 
cin >> n; 
if (n < 1 || n > 10) { 
cout << "Invalid number of students. Please enter a value between 1 and 10." << endl; 
return 1; // Exit with error code if invalid input 
} 
for (int i = 0; i < n; i++) { 
students[i].input(); 
} 
sort(students, students + n, compareName); // Sort students by name 
cout << "NAME BIRTH DATE TELEPHONE" << endl; 
for (int i = 0; i < n; i++) { 
students[i].display(); 
} 
cout << "Enter the record to be searched (name): "; 
getline(cin, nameToSearch); 
bool found = binary_search(students, students + n, Student{nameToSearch}, 
[](const Student& s1, const Student& s2) { return s1.name < s2.name; }); 
if (found) { 
cout << "Record found." << endl; 
} else { 
cout << "Record not found." << endl; 
} 
return 0; 
}
