#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int SumLine(){
    string line;
    while (getline(cin,line)){
        int sum=0,x;
        stringstream ss(line);
        while(ss>>x)sum+=x;
        cout<<sum<<endl;
    }
}

struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
}

Point operator + (const Point& A,const Point& B){
    return Point(A.x+B.x,A.y+B.y);
}

ostream& operator << (ostream& out,const Point& p){
    out<<"("<<p.x<<","<<p.y<<")";
    return out;
}

template<typename T>
T sum(T* begin,T* end){
    T* p=begin;
    T ans=0;
    for(T* p=begin;p!=end;p++)
        ans=ans+p;
    return ans;
}

