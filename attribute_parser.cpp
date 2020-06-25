// https://www.hackerrank.com/challenges/attribute-parser/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctype>
using namespace std;


class tag;

class tag_parser {
private:
    const string& _input;
    int pos = 0;
public:
    tag_parser(const string& input) : _intput(input) {

    }

    unique_ptr<tag> parse() {
        if (!test('<')) return NULL;
        string open_tag = parse_open_tag();
        if (open_tag == "") return NULL;
        tag t(open_tag);
        parse_attrs(t);
        if (!test('>')) return NULL;
        unique_ptr<tag> child;
        while (child = parse()) {
            tag.children.push_back(child);
        }
        parse_close_tag(t);
    }

    bool test(char c, bool skip_blank = true) {
        if (skip_blank)
            skip_blanks();
        if (pos < _input.size()) {
            if (_input[pos++] == c) return true;
        }
        return false;
    }

    bool test(const string& s, bool skip_blank = true) {
        if (skip_blank)
            skip_blanks();
        if (_input.substr(pos, s.size()) == s) {
            pos += s.size();
            return true;
        }
    }

    string parse_open_tag() {
        int pos_prev = pos;
        string id;
        if (test('<') && (id = parse_id())) {
            //if (test('>'))
                return id;
        }
        pos = pos_prev;
        return "";
    }
    bool parse_close_tag(const tag &t) {
        int pos_prev = pos;
        if (test('<') && test('/') && test(t.name) && test('>')) {
            return true;
        }
        return false;
    }

    string parse_id() {
        skip_blanks();
        int pos_prev = pos;
        while (pos < _input.size() && (isalnum(_input[pos]))) {
            pos++;
        }
        return _input.substr(pos_prev, pos);
    }

    void parse_attrs(const tag &t) {
        int pos_prev = pos;
        string attr, value;
        while ((attr = parse_attr()) && (value = parse_value()))
        {
            t.attrs.push_back(attr);
            t.values.push_back(value);
        }
    }

    string parse_attr() {
        skip_blanks();
        int pos_prev = pos;
        string name;
        if (test('"') && (name = parse_id()) && test('"') && test('=')) {
            return name;
        }
        pos = pos_prev;
        return "";
    }

    string parse_value() {
        skip_blanks();
        int pos_prev = pos;
        string name;
        if (test('"') && (name = parse_id()) && test('"'))
            return name;
        pos = pos_prev;
        return "";
    }

    void skip_blanks() {
        while (pos < _input.size() && _input[i] == ' ')
            pos++;
    }
}

class tag {
public:
    tag(const string& _name) : name(_name) {
    }

    tag(const tag& src): 
        name(src.name), attrs(src.attrs), values(src.values), children(src.children) {

    }

    bool query(const string& q, string &value) {
        int i = 0;
        while (i < q.size() && isalnum(q[i]))
            i++;
        if (i < q.size()) {
            if (q[i] == '.') {
                const vector<unique_ptr<tag>>::iterator it;
                it = children.cbegin();
                while (it) {
                    if ((**it).name == q.substr(0, i - 1)) {
                        const string new_q = q.substr(i + 1);
                        return (**it).query(new_q, value);
                    }
                    ++it;
                }
            } else if (q[i] == '~') {
                const string field = q.substr(i + 1);
                const vector<string>::iterator it;
                if ((it = attrs.find(field))) {
                    value = *it;
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
        return false;
    }

    string name;
    vector<string> attrs;
    vector<string> values;
    vector<unique_ptr<tag>> children;


    static tag parse(string &s) {
        tag_parser parser(s);
        return parse();
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int i, j;
    cin >> i >> j;
    string s, line;
    while (i--) {
        cin >> line; 
        s += line;
        s += "\n";
    }

    const tag t = tag.parse(s);
    string query;
    string value;
    while (j--) {
        cin >> query;
        if (tag.query(query, value)) {
            cout << value << endl;
        } else {
            count << "Not Found!" << endl;
        }
    }
    
    return 0;
}
