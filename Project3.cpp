#include <iostream>
#include <cmath>
#include<vector>

using namespace std;

struct Vector {
    double x,y,z;
};

struct Vector generate_vector(double a,double b,double c)
{
        struct Vector v;
        v.x = a;
        v.y = b;
        v.z = c;
        return v;
}


void show(Vector v)
{
        cout << fixed;
        cout << "<" <<v.x<< ", " <<v.y<< ", " <<v.z<< ">\n";
}

struct Vector add(Vector &v1, Vector &v2){
        struct Vector fv;
        fv.x = v1.x + v2.x;
        fv.y = v1.y + v2.y;
        fv.z = v1.z + v2.z;
        return fv;
}

double dot_product(Vector &v1,Vector &v2)
{
        double product=v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
        return product;
}
  
struct Vector const_multiply(double const_m,Vector &v)
{
    struct Vector fv; 
    fv.x=v.x*const_m;
    fv.y=v.y*const_m;
    fv.z=v.z*const_m;
    return fv;
    
}
    
struct Vector normalize(Vector &v) 
{
    Vector fv;
    double magnitude=sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
    
    fv.x = v.x / magnitude;
    fv.y = v.y / magnitude;
    fv.z = v.z / magnitude;
     
    return fv;
}

struct Vector cross_product(Vector &v1, Vector &v2){
    struct Vector fv;
    fv.x = (v1.y * v2.z) - (v1.z * v2.y);
    fv.y =-1 * ((v1.x * v2.z) - (v1.z * v2.x));
    fv.z = (v1.x * v2.y) - (v1.y * v2.x);
    return fv;
}

int main() {
    Vector v1;
    Vector v2;

    v1 = generate_vector(1,2,3); 
    v2 = generate_vector(4,-5,8);

    show(v1); 
    show(v2);

    
    show(normalize(v1));
    cout << dot_product(v1, v2) << "\n";
    show(const_multiply(5, v1));
    show(cross_product(v1, v2));
    show(add(v1, v2));
    return 0;
}