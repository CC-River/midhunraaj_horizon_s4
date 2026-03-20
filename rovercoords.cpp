#include <iostream>
#include <cmath>
using namespace std;

float distance(float x1, float y1, float x2, float y2){
    float x = pow((x2-x1),2);
    float y = pow((y2-y1),2);
    float dist = sqrt(x+y);
    return dist;
}

int main(){
    float a,b,c,d;
    cout<<"Enter x1 y1 and x2 y2: ";
    cin>>a>>b>>c>>d;
    float q = distance(a,b,c,d);
    cout<<"The distance is: "<<q;
    return 0;
}