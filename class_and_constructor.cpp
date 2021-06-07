#include<iostream>
using namespace std;

class Rectangle {

    private: 
        int length;
        int breath;

    public:
        Rectangle(){length=breath=1;}
        Rectangle(int l, int b);

        int area();
        int perimeter();
        void setlength(int l) {length=l;}
        int getlength() {return length;}     
        ~Rectangle();

};

Rectangle::Rectangle (int l, int b)
    {   length =l;
        breath =b;}

int Rectangle::area(){
    return length*breath;
}

int Rectangle::perimeter(){
    return 2*(length+breath);
}

Rectangle::~Rectangle()
{}

int main(){
    Rectangle r(2,4);
    cout<<r.area()<<endl;
    cout<<r.perimeter()<<endl;
    r.setlength(20);
    cout<<r.getlength()<<endl;
}