#include <iostream>
#include <math.h>

using namespace std;
# define fraction_bits 14


int main(){

    float a[10]={-8.31662009587695e-13,0.634029328751641,-0.767445067471676,1.21423064425930,-0.398089786809545,0.577773754381422,0.836673932101677,-0.308971047587158,1.58778525229245,-0.182021563971272};
		float b[10]={0.256258710000824,-0.299311523023751,1.18013824251201,-0.724526570403471,0.963365491184473,0.0611683879836982,-0.126424722362053,1.08772832230303,-0.743741290000000,1.08772832230147};

    short int a1[10];
    short int a2[10];

    for(int i=0;i<10;i++){
      a1[i]=(short int)(a[i]*(1<<fraction_bits));
    }
    for(int i=0;i<10;i++){
      a2[i]=(short int)(b[i]*(1<<fraction_bits));
    }

		int c[10];
    float c1[10];
		for(int i=0;i<10;i++){
			c[i]=0;
      c1[i]=0;
		}
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
		 		if(j<10 && j-i>=0){
					c[i]=c[i]+((a1[j]*a2[j-i]));
          c1[i]=c1[i]+((a[j])*b[j-i]);
        }
		 	}
	 }
	 for(int i=0;i<10;i++){
		 cout << c[i]/float(1<<2*fraction_bits) << endl;
	 }

}
