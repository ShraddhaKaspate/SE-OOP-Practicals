Imagine a publishing company which does marketing for book and audio cassette versions. Create 
a class publication that stores the title (a string) and price (type float) of publications. From this 
class derive two classes: book which adds a page count (type int) and tape which adds a playing 
time in minutes (type float). Write a program that instantiates the book and tape class, allows user 
to enter data and displays the data members. If an exception is caught, replace all the data 
member values with zero values. 
#include <stdio.h> 
#include <string.h> 
 
// Base Class 
class Publication { 
protected: 
    char title[100]; 
    float price; 
 
public: 
    // Base class methods 
    virtual void getData() { 
        printf("Enter the Title of Publication: "); 
        gets(title);  // Use gets to read the title as a string 
        printf("Enter the price: "); 
        scanf("%f", &price); 
    } 
 
    virtual void putData() const { 
        printf("\nTitle: %s\n", title); 
        printf("Price: $%.2f\n", price); 
    } 
 
    // Reset method to zero values if an exception occurs 
    void reset() { 
        strcpy(title, "N/A"); 
        price = 0.0; 
    } 
}; 
 
// Derived Class - Book 
class Book : public Publication { 
private: 
    int pageCount; 
 
public: 
    // Method to input book details 
    void getData() override { 
        Publication::getData(); 
        printf("Enter the number of pages: "); 
        scanf("%d", &pageCount); 
    } 
 
    // Method to output book details 
    void putData() const override { 
        Publication::putData(); 
        printf("Page Count: %d\n", pageCount); 
    } 
 
    void reset() { 
        Publication::reset(); 
        pageCount = 0; 
    } 
}; 
 
// Derived Class - Tape 
class Tape : public Publication { 
private: 
    float playTime; 
 
public: 
    // Method to input tape details 
    void getData() override { 
        Publication::getData(); 
        printf("Enter the play time in minutes (xx.xx): "); 
        scanf("%f", &playTime); 
    } 
 
    // Method to output tape details 
    void putData() const override { 
        Publication::putData(); 
        printf("Play Time: %.2f minutes\n", playTime); 
    } 
 
    void reset() { 
        Publication::reset(); 
        playTime = 0.0; 
    } 
}; 
 
int main() { 
    Book playBook; 
    Tape playTape; 
    char choice; 
 
    try { 
        printf("\nBOOK\n"); 
        playBook.getData(); 
        getchar(); // Consume newline left in buffer 
 
        printf("\nTAPE\n"); 
        playTape.getData(); 
        getchar(); // Consume newline left in buffer 
 
    } catch (...) { 
        printf("An error occurred. Resetting all data to default values.\n"); 
        playBook.reset(); 
        playTape.reset(); 
    } 
 
    // Display the menu for the user to choose between book and tape data 
    printf("\n\nMENU\n"); 
    printf("1. Book\n"); 
    printf("2. Tape\n"); 
    printf("Enter your choice: "); 
    choice = getchar(); 
 
    switch (choice) { 
        case '1': 
            printf("\nBOOK DETAILS\n"); 
            playBook.putData(); 
            break; 
 
        case '2': 
            printf("\nTAPE DETAILS\n"); 
            playTape.putData(); 
            break; 
 
        default: 
            printf("Invalid choice!\n"); 
    } 
 
    return 0; 
}
