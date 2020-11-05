#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class LineSegment {

    private:
        int a,b,c,d;
        friend string show(LineSegment);
        friend float getSegmentLength(LineSegment *A);
        friend LineSegment getLongerSegment(LineSegment A, LineSegment B);
    
    public:
        LineSegment(int a = 0, int b = 0, int c = 0, int d = 0);
        float getSlope();
        float getYIntercept();

        LineSegment operator+(LineSegment A){
            LineSegment O;
            O.a = a + A.a;
            O.b = b + A.b;
            O.c = c + A.c;
            O.d = d + A.d;
            return O;
        }

};

LineSegment::LineSegment(int x, int y, int z, int w){
    a = x;
    b = y;
    c = z;
    d = w;
}

string show(LineSegment A){
    stringstream ss;
    ss << "Line segment between (" << A.a << ", " << A.b <<") and (" << A.c << ", " << A.d <<")";
    return ss.str();
}

float LineSegment::getSlope(){
    float difx = c-a;
    float dify = d-b;
    float slope = dify / difx;
    return slope;
}

float LineSegment::getYIntercept(){
    float y = -(getSlope() * a) +b;
    return y;
}

float getSegmentLength(LineSegment *A){
    float lengthsq = pow(A->c - A->a, 2) + pow(A->d - A->b, 2);
    float length = sqrt(lengthsq);
    return length;
}

LineSegment getLongerSegment(LineSegment A, LineSegment B){
    float lenA = getSegmentLength(&A);
    float lenB = getSegmentLength(&B);

    if(lenA > lenB){
        return A;
    } else {
        return B;
    }
}

int main(){
    LineSegment A(2,8,4,9);
    LineSegment B(3,11,6,21);

    cout << show(A) << endl;
    cout << show(B) << endl;

    cout << A.getSlope() << endl;
    cout << B.getYIntercept() << endl;
    cout << getSegmentLength(&A) << endl;
    cout << show(getLongerSegment(A, B)) << endl;
    cout << show(A+B) << endl;

    return 0;
}

/* ANSWERS:
Line segment between (2, 8) and (4, 9)
Line segment between (3, 11) and (6, 21)
0.5
1
2.23607
Line segment between (3, 11) and (6, 21)
Line segment between (5, 19) and (10, 30)
*/