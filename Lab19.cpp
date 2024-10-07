// COMSC-210 | Lab 19 | Jeremiah Ortiz
#include <iostream>
#include <string>
#include <fstream> 
#include <vector> 
#include <iomanip> 
using namespace std; 

  double generateNum();
 vector<string> commentReview(const string &filename);

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

            double average() {

                int a = 0; 

                double sum = 0.0; 

                Node *current = head; 

                while (current) {

                    sum += current->value; 

                    current = current->next; 
                  
                    a++; 
                }

                    return (a > 0) ? (sum / a) : 0.0; 

                   
            }

            string titleName() {

                return title; 
            }
}; 


  double generateNum() {

        return (rand() % 41 + 10) / 10.0;

    }

   vector<string> commentReview(const string &filename) {

        fstream file("Reviews.txt"); 

        vector<string> comments; 

        string l; 

        if (file.is_open()) {

            while (getline(file, l)) {
                comments.push_back(l); 
            }
            file.close(); 
        }

        return comments; 
    }

    int main() {

       srand(static_cast<unsigned int>(time(0)));

        vector<string> comments = commentReview("Reviews.txt"); 

        vector<Movie> listOfMovies {

            Movie("Interstellar"), Movie("Star Wars"), Movie("The Matrix"), Movie("Star Trek")
        }; 

         for (auto& movie : listOfMovies) {

     for (int i = 0; i < 3; ++i) {
         if (i < comments.size()) {
             double rate = generateNum();
             movie.review(rate, comments[i]);
         }
     }
 }

 for (const auto& movie : listOfMovies) {

     movie.output();

     cout << "Average Rating: " << fixed << setprecision(2) << movie.average() << endl;
 }

        return 0; 
    }

