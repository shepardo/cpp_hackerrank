// Day 17
// https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here

class descriptive_exception : public std::exception {
public:
    descriptive_exception(std::string const &message) : msg_(message) { }
    virtual char const *what() const noexcept { return msg_.c_str(); }

private:
    std::string msg_;
};

class Calculator {
public:
    int power(int n, int p) {
        int result = 1;
        if (n < 0 || p < 0)
            throw descriptive_exception("n and p should be non-negative");
        while (p--) {
            result *= n;
        }
        return result;
    }
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl;
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }

}
