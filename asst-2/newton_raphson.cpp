#include <iostream>

 using namespace std;

 int main(){
   float x=0.32;
   float temp;
   int i=0;
   while(i<100){
     x=x-(x*x*x-x-1)/(3*x*x-1);
     i=i+1;
   }
   cout << x << endl;
 }
