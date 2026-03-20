#include <iostream>
#include <cmath>
using namespace std;

float distance(float x1, float y1, float x2, float y2){
    float x = pow((x2-x1),2);
    float y = pow((y2-y1),2);
    return sqrt(x+y);
}

float time(float dist, float u, float a, float v){
    float t1 = (v-u)/a;
    float s1 = u*t1 + 0.5*a*t1*t1;
    if (s1>=dist) {
        float t = (-u+sqrt(u*u+2*a*dist))/a;
        return t;
    }
    float s2 = dist-s1;
    float t2 = s2/v;
    return t1 + t2;
}

int main(){
    float a,b,c,d, vel, accl, speed, dist, t;
    cout<<"Enter x1 y1 and x2 y2: ";
    cin>>a>>b>>c>>d;
    if(a==b && c==d){
        cout<<"Same coordinates 0 distance";
        return 1;
    }
    else{
        dist = distance(a,b,c,d);
        cout<<"The distance is: "<<dist<<endl;
    }

    cout<<"Enter initial velocity, acceleration and max speed: ";
    cin>>vel>>accl>>speed;
    if(accl<0){
        cout<<"-ve Acceleration";
        return 1;
    }
    else{
        t = time(dist, vel, accl, speed);
    }
    cout << "Time to reach destination: " <<t<<"s"<< endl;

    return 0;
}