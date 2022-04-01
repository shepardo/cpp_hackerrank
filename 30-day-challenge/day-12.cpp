// Day 12
// https://www.hackerrank.com/challenges/30-inheritance/problem?isFullScreen=true


#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
		}

};

class Student :  public Person{
	private:
		vector<int> testScores;
	public:
        /*
        *   Class Constructor
        *
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student(const string& cfirstName, const string& clastName, int cid,
            const vector<int>& ctestScores):
                Person(cfirstName, clastName, cid),
                testScores(ctestScores) {
        }

        /*
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        string calculate() {
            // #include <numeric>
            // int total = std::reduce(this->testScores.begin(), this->testScores->end());
            int total = 0;
            for (
                vector<int>::const_iterator it = testScores.begin();
                it != testScores.end();
                it++) {
                total += *it;
            }
            total = total / testScores.size();
            if (total >= 90 && total <= 100) return "O";
            else if (total >= 80 && total < 90) return "E";
            else if (total >= 70 && total < 80) return "A";
            else if (total >= 55 && total < 70) return "P";
            else if (total >= 40 && total < 55) return "D";
            else return "T";

        }
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}
