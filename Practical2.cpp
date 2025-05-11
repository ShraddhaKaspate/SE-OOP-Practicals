/* 
Develop a program in C++ to create a database of student’s information system containing 
thefollowing information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact 
address, Telephone number, Driving license no. and other. Construct the database with suitable 
member functions. Make use of constructor, default constructor, copy constructor, destructor, 
static member functions, friend class, this pointer, inline code and dynamic memory allocation 
operators-new and delete as well as exception handling. 
*/ 
#include <iostream> 
#include <cstring> 
using namespace std; 
class Info { 
public: 
char dob[10]; 
char add[30]; 
char name[30]; 
char year[3]; 
float marks; 
long tel_no; 
static int cnt; 
Info(); // Default constructor 
Info(const Info &p); // Copy constructor 
void accept(); 
void display(); 
static int count(); 
}; 
// Static member initialization 
int Info::cnt = 0; 
// Default constructor 
Info::Info() { 
strcpy(name, "Default"); 
strcpy(year, "FE"); 
strcpy(add, "Default"); 
marks = 0; 
tel_no = 1000000000; 
strcpy(dob, "1/1/90"); 
} 
// Copy constructor 
Info::Info(const Info &p) { 
strcpy(name, p.name); 
strcpy(year, p.year); 
strcpy(add, p.add); 
marks = p.marks; 
tel_no = p.tel_no; 
strcpy(dob, p.dob); 
} 
// Accept method 
void Info::accept() { 
cout << "Enter the name: "; 
cin >> name; 
cout << "Enter the address: "; 
cin >> add; 
cout << "Enter the year: "; 
cin >> year; 
cout << "Enter telephone number: "; 
cin >> tel_no; 
cout << "Enter Marks: "; 
cin >> marks; 
cout << "Enter date of birth: "; 
cin >> dob; 
} 
// Display method 
void Info::display() { 
    cout << "\nName: " << name; 
    cout << "\nAddress: " << add; 
    cout << "\nYear: " << year; 
    cout << "\nTelephone number: " << tel_no; 
    cout << "\nMarks: " << marks; 
    cout << "\nDate of birth: " << dob << endl; 
} 
 
// Static count method to increment and return count 
int Info::count() { 
    cnt++; 
    return cnt; 
} 
 
int main() { 
    int ch, n = 0, ch1, pos, temp; 
    bool flag = false; 
    Info o[50]; 
    char search_name[30]; 
 
    do { 
        cout << "\n\nMENU"; 
        cout << "\n1. Accept"; 
        cout << "\n2. Display"; 
        cout << "\n3. Insert record"; 
        cout << "\n4. Search record"; 
        cout << "\n5. Delete record"; 
        cout << "\n6. Exit"; 
        cout << "\nEnter your choice: "; 
        cin >> ch; 
 
        switch (ch) { 
            case 1: 
                cout << "\n1. Use default record?"; 
                cout << "\n2. Enter new record?"; 
                cin >> ch1; 
                if (ch1 == 1) { 
                    Info defaultInfo; 
                    o[n] = defaultInfo; 
                    cout << "\nDefault values initialized"; 
                    n = Info::count(); 
                } else if (ch1 == 2) { 
                    o[n].accept(); 
                    n = Info::count(); 
                } 
                break; 
 
            case 2: 
                for (int i = 0; i < n; i++) { 
                    o[i].display(); 
                } 
                break; 
 
            case 3: 
                cout << "\nEnter the position to insert record: "; 
                cin >> pos; 
                pos--;  // Convert to zero-indexed 
                n = Info::count(); 
                for (int i = n; i > pos; i--) { 
                    o[i] = o[i - 1]; 
                } 
                o[pos].accept(); 
                break; 
 
            case 4: 
                cout << "Enter the name to search: "; 
                cin >> search_name; 
                flag = false; 
                for (int i = 0; i < n; i++) { 
                    if (strcmp(search_name, o[i].name) == 0) { 
                        flag = true; 
                        o[i].display(); 
                        break; 
                    } 
                } 
                if (!flag) { 
                    cout << "Sorry, record not found.\n"; 
                } 
                break; 
 
            case 5: 
                cout << "\nEnter the position to delete record: "; 
                cin >> pos; 
                pos--;  // Convert to zero-indexed 
                for (int i = pos; i < n - 1; i++) { 
                    o[i] = o[i + 1]; 
                } 
                n--; 
                cout << "\nRecord deleted.\n"; 
                break; 
 
            case 6: 
                cout << "Exiting program...\n"; 
                break; 
 
            default: 
                cout << "Invalid choice. Please try again.\n"; 
                break; 
        } 
    } while (ch != 6); 
 
    return 0; 
}
