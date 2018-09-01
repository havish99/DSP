# include <iostream>

using namespace std;

# define bits_number 14
int main(){
  float a[85];
  float con1=0.5;
  float con2=0.166666;
  float con3=0.2;
  for(int i=0;i<85;i++){
    cin >> a[i];
  }
  short int a1[85];
  for(int i=0;i<85;i++){
    a1[i]=(short int)(a[i]*(1<<bits_number));
  }
  short int con_1 = (short int)(con1*(1<<14));
  short int con_2 = (short int)(con2*(1<<14));
  short int con_3 = (short int)(con3*(1<<14));

  int c[85];
  float c1[85];
  for(int i=0;i<85;i++){
    c[i]=0;
    c1[i]=0;
  }

  for(int i=4;i<85;i++){
    c[i]=c[i]+con_3*a1[i]+con_3*(a1[i-1]+a1[i-2])+con_3*(a1[i-3]+a1[i-4]);
    c1[i]=c1[i]+con3*a[i]+con3*(a[i-1]+a[i-2])+con3*(a[i-3]+a[i-4]);
  }
  for(int i=0;i<85;i++){
    cout << c[i]/float(1<<28) << ',';
  }
}
