// https://www.hackerrank.com/challenges/box-it/problem
#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {
public:
    Box() : l(0), b(0), h(0) {}
    Box(long length, long breadth, long height) : l(length), b(breadth), h(height) {
    }
    Box(const Box& box): l(box.l), b(box.b), h(box.h) {
    }
    long getLength() { return l; }
    long getBreadth() { return b; }
    long getHeight() { return h; }
    long long CalculateVolume() { return b * h * l; }
    bool operator <(Box &b) {
        if (this->l < b.l) return true;
        else if (this->l < b.l) return false;
        else {
            if (this->b < b.b) return true;
            else if (this->b > b.b) return false;
            else {
                if (this->h < b.h) return true;
                else return false;
            }
        } 
    }
    friend ostream& operator<<(ostream& out, Box& b);
private:
    long l, b, h;
};

ostream& operator<<(ostream& out, Box& b) {
    return out << b.l << " " << b.b << " " << b.h;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
