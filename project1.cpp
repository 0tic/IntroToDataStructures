#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//creates the base class Linear
class Linear{
    private:
        int a;
        int b;
        //print class that displays the linear properties
        friend void print(Linear);
    public:
        //constructor
        Linear(int,int);
        //destructor
        ~Linear();
        double root();
        string y_intercept();
        Linear derivative();
        Linear constant_multiple(int);
        Linear larger_slope(Linear,Linear);
        Linear operator + (Linear other){
            Linear z(this->a+other.a, this->b+other.b);
            return z;
        }
};

//constructor
Linear::Linear(int A, int B){
    a = A;
    b = B;
}

//destuctor
Linear::~Linear(){};

//prints the Linear equation
void print(Linear B){
    //if a is equal to 0, get rid of x
    if (B.a == 0){
        cout<<to_string(B.b)<<endl;
    //if b is less than 0
    } else if(B.b < 0){
        cout<<to_string(B.a)<<"x - "<<to_string(abs(B.b))<<endl;
    // if b is greater than 0
    } else if (B.b > 0) {
        cout<<to_string(B.a)<<"x + "<<to_string(abs(B.b))<<endl;
    } else {
        cout<<to_string(B.a)<<"x"<<endl;
    } 
}

//calcuates the root of the linear equation
double Linear::root(){
    double root = (double)(-b)/(double)a;
    return root;
}

//gives the y-intercept of the linear equation
string Linear::y_intercept(){
    return "(0, " + to_string(b) + ")";
}

//calculates the derivative of the linear equation
Linear Linear::derivative(){
    Linear Z(0,a);
    return Z;
}

//multiples the linear equation by a constant
Linear Linear::constant_multiple(int c){
    Linear Z(a*c,b*c);
    return Z;
}

//compares two linear equations and returns the one with a larger slope
Linear Linear::larger_slope(Linear A, Linear B){
    if (abs(A.a) < abs(B.a)){
        return B;
    } else {
        return A;
    }
}

int main(){
    Linear P(-7,5);
    Linear Q(8,-3);
    Linear R(4,0);
    print(P);
    print(Q);
    print(R);
    cout<<to_string(P.root())<<endl;
    cout<<P.y_intercept()<<endl;
    cout<<"This is the derivative "; print(P.derivative());
    print(P.constant_multiple(3));
    print(P+Q);
}