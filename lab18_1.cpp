#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1,Rect R2){
    double a,b,x0,y0;
    
    if(R1.x < R2.x){
        a = R1.x+R1.w;
        if(a > R2.x) x0 = R1.w-(R2.x-R1.x);
        else x0 = 0;
        if(a > R2.x+R2.w) x0 = R2.w;
    }
    else{
        a = R2.x+R2.w;
        if(a > R1.x) x0 = R2.w-(R1.x-R2.x);
        else x0 = 0;
        if(a > R1.x+R1.w) x0 = R1.w;
    }
    
    if(R1.y > R2.x){
        b = R1.y-R1.h;
        if(b < R2.y) y0 = R1.h-(R1.y-R2.y);
        else y0 = 0;
        if(b < R2.y-R2.h) y0 = R2.h;
    }
    else{
        b = R2.y-R2.h;
        if(b < R1.y) y0 = R2.h-(R2.y-R1.y);
        else y0 = 0;
        if(b < R1.y-R1.h) y0 = R1.h;
    }
    
    return x0*y0;
}