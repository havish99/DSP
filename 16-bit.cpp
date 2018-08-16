#include <iostream>
#include <stdint.h>
#include <math.h>
using namespace std;

# define pi  3.14159265358979323846
int no_of_bits(int a){
	int i=0;
	while(a>0){
		a=a/2;
		i++;
	}
	return i+1;
}

int main(){
	float a1;
	float a2;
	cout << "Enter the numbers a1,a2" << endl;
	cin >> a1 >> a2; 
	// min number of bits for addition required in integer part(for signed numbers) change to 16 for unsigned
	int bits_number=15-no_of_bits(floor(max(a1,a2)));
	if(bits_number<0){
		cout << "overflow" << endl;
		return 0;
	}
	cout << "number of fraction bits: "<< bits_number <<endl;
	// change to uint16_t for unsigned
	int16_t a1_16=(int16_t)(a1*(1<<(bits_number)));
	int16_t a2_16=(int16_t)(a2*(1<<(bits_number)));
	int16_t add,sub;
	add=a1_16+a2_16;
	sub=a1_16-a2_16;
	cout << "Addition   : " << add/(float(1<<bits_number)) << endl;
	cout << "Subtraction: " << sub/(float(1<<bits_number)) << endl;

}