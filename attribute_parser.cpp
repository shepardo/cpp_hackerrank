// https://www.hackerrank.com/challenges/attribute-parser/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <cctype>
using namespace std;



class tag;
string& name(tag &);
vector<string>& attrs(tag &);
vector<string>& values(tag &);
vector<shared_ptr<tag>> children(tag &);

tag* create_tag(const string&);
//vector<unique_ptr<tag>>& tag::children();

/*
class tag {
public:
  tag(const string& _name);
  tag(const tag& src);
  bool query(const string& q, string &value) const;
  string& name();
  vector<string>& attrs();
  vector<string>& values();
  vector<unique_ptr<tag>> children();
};*/

/*
{
public:
  tag(const string& _name);
  tag(const tag& src);
  bool query(const string& q, string &value) const;
  string name;
  vector<string> attrs;
  vector<string> values;
  vector<unique_ptr<tag>> children;
};*/

class tag_parser {
private:
    const string& _input;
    string::size_type pos = 0;
public:
    tag_parser(const string& input) : _input(input) {

    }

    shared_ptr<tag> parse() {
        if (!test('<')) return NULL;
        const string open_tag = parse_open_tag();
        if (open_tag == "") return NULL;
        shared_ptr<tag> t(create_tag(open_tag));
        parse_attrs(t);
        if (!test('>')) return NULL;
        shared_ptr<tag> child;
        while ((child = parse())) {
            children(*t).push_back(child);
        }
        parse_close_tag(t);
        return t;
    }

    bool test(const char c, bool skip_blank = true) {
        if (skip_blank)
            skip_blanks();
        string::size_type pos_prev = pos;
        if (pos < _input.size()) {
            if (_input[pos++] == c) return true;
        }
        pos = pos_prev;
        return false;
    }

    bool test(const string& s, bool skip_blank = true) {
        if (skip_blank)
            skip_blanks();
        string::size_type pos_prev = pos;
        if (_input.substr(pos, s.size()) == s) {
            pos += s.size();
            return true;
        }
        pos = pos_prev;
        return false;
    }

    string parse_open_tag() {
        string::size_type pos_prev = pos;
        string id;
        if ( ((id = parse_id()) != "")){
            //if (test('>'))
            return id;
        }
        pos = pos_prev;
        return "";
    }
    bool parse_close_tag(const shared_ptr<tag> &t) {
        if (test('<') && test('/') && test(name(*t)) && test('>')) {
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

    void parse_attrs(shared_ptr<tag> &t) {
        string::size_type pos_prev = pos;
        string attr, value;
        while (((attr = parse_attr()) != "") && ((value = parse_value()) != ""))
        {
            attrs(*t).push_back(attr);
            values(*t).push_back(value);
        }
    }

    string parse_attr() {
        skip_blanks();
        string::size_type pos_prev = pos;
        string name;
        if (((name = parse_id()) != "") && test('=')) {
            return name;
        }
        pos = pos_prev;
        return "";
    }

    string parse_value() {
        skip_blanks();
        string::size_type pos_prev = pos;
        string name;
        if (test('"') && ((name = parse_id()) != "") && test('"'))
            return name;
        pos = pos_prev;
        return "";
    }

    void skip_blanks() {
        while (pos < _input.size() && _input[pos] == ' ')
            pos++;
    }
};

class tag {
public:
    tag(const string& name) : _name(name) {
    }

    tag(const tag& src): 
        _name(src._name), _attrs(src._attrs), _values(src._values), _children(src._children) {

    }

    //friend tag* create_tag(const string&);
    friend string& name(tag &);
    friend vector<string>& attrs(tag &);
    friend vector<string>& values(tag &);
    friend vector<shared_ptr<tag>> children(tag &);

    bool query(const string& q, string &value) {
        string::size_type i = 0;
        while (i < q.size() && isalnum(q[i]))
            i++;
        if (i < q.size()) {
            if (q[i] == '.') {
                const string field = q.substr(0, i - 1);
                if (field != _name) return false;
                vector<shared_ptr<tag>>::iterator it = _children.begin();
                while (it != _children.end()) {
                    //if ((**it)._name == q.substr(0, i - 1)) {
                        const string new_q = q.substr(i + 1);
                        return (**it).query(new_q, value);
                    //}
                    ++it;
                }
            } else if (q[i] == '~') {
                const string field = q.substr(i + 1);
                vector<string>::iterator it;
                if ((it = find(_attrs.begin(), _attrs.end(), field)) != _attrs.end()) {
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

    void dump() const {
        cout << "tag: " << _name << endl;
        return;
        cout << "attrs: " << endl;
        for (int i = 0; i < _attrs.size() && i < _values.size(); i++) {
            cout << _attrs[i] << "=" << _values[i] << endl;
        }
        for (auto it = _children.begin(); it != _children.end(); it++) {
            (**it).dump();
        }
    }

    string _name;
    vector<string> _attrs;
    vector<string> _values;
    vector<shared_ptr<tag>> _children;

    string& name() { return _name; }
    vector<string>& attrs() { return _attrs; }
    vector<string>& values() { return _values; }
    vector<shared_ptr<tag>> children() { return _children; }


    static shared_ptr<tag> parse(string &s) {
        tag_parser parser(s);
        return parser.parse();
    }
};

string& name(tag &t) { return t.name(); }
vector<string>& attrs(tag &t) { return t.attrs(); }
vector<string>& values(tag &t) { return t.values(); }
vector<shared_ptr<tag>> children(tag &t) { return t.children(); }

tag* create_tag(const string& name) {
    return new tag(name);
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

    const shared_ptr<tag> t = tag::parse(s);
    t->dump();
    string query;
    string value;
    while (j--) {
        cin >> query;
        if (t->query(query, value)) {
            cout << value << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }
    
    return 0;
}
