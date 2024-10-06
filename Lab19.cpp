// COMSC-210 | Lab 19 | Jeremiah Ortiz
#include <iostream>
#include <string>
#include <fstream> 
#include <vector> 
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

            
}; 
