// COMSC-210 | Lab 19 | Jeremiah Ortiz
#include <iostream>
#include <string>
#include <fstream> 
#include <vector> 
#include <iomanip> 
using namespace std; 

struct Node {

    float value; 

    Node *next; 

    string comment; 

};

class Movie {

        private:
            string title; 

            Node *head; 

        public: 

            Movie(string title) : title(title), head(nullptr) {}

            ~Movie() {
                while (head) {
                    Node *temp = head; 

                    head = head->next; 

                    delete temp; 
                }
            }

             void review(double rating, const string &comment) {

                Node *newNode = new Node; 

                newNode->value = rating; 

                newNode->comment = comment; 

                newNode->next = head; 

                head = newNode; 
            }

             void output() {

                cout << "Movie: " << title << endl; 

                Node *current = head; 

                int reviews = 1; 

                while (current) {

                    cout << fixed << setprecision(1); 

                    cout << "Review# " << reviews++ << ": " << current->value << ": " << current->comment << endl; 

                    current = current->next; 
                }
            }

            
}; 
