// https://www.hackerrank.com/challenges/c-tutorial-class/problem
#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
private:
    int _age;
    int _standard;
    string _first_name;
    string _last_name;
public:
    Student() {}
    int get_age() const { return _age; }
    void set_age(int v) { _age = v; }
    const string& get_first_name() const { return _first_name; }
    void set_first_name(string& v) { _first_name = v; }
    const string& get_last_name() const { return _last_name; }
    void set_last_name(string &v) { _last_name = v; }
    int get_standard() { return _standard; }
    void set_standard(int v) { _standard = v; }

    string to_string() {
        stringstream ss;
        ss << _age << "," << _first_name << "," << _last_name << "," << _standard << endl;
        return ss.str();
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
