#include <iostream>
#include <cmath>
#include <chrono>

using namespace std::chrono;
using namespace std;

#define whatis(x) cerr << #x " is " << x << endl

int fast_pow(int a, int b){

	if(b == 0)
		return 1;

	int half = fast_pow(a, b/2);
	if(b % 2 == 0)
		return half * half;
	return half * half * a;
}

int traditional_multi(int num1, int num2){
	return num1 * num2;
}

int karatsuba_multi(int num1, int num2){

	// cout << "-> ks(" << num1 << ", " << num2 << ") called.\n";
	if(num1 == 0 || num2 == 0)
		return 0;

	int digits_num1, digits_num2;
	
	digits_num1 = log10(num1) + 1;
	digits_num2 = log10(num2) + 1;
	
	// whatis(digits_num1);
	// whatis(digits_num2);
	
	// Base case
	// If any of the two number is single digit, return their product.
	if(digits_num1 == 1 || digits_num2 == 1)
		return num1 * num2;

	// Recursive Case
	/*  
		Divide both the numbers into two equal halves
		eg. say, x = 1234 and y = 5678, then
		a = 12, b = 34
		c = 56, d = 78
		
		x = a * 10^(n/2) + b
		y = c * 10^(n/2) + d

	*/

	// calculation of half_digits for a, b, c, d

	int a, b, c, d, digits_half_num1, digits_half_num2;

	digits_half_num1 = digits_num1 / 2;
	digits_half_num2 = digits_num2 / 2;
	int half_zeros_num1 = fast_pow(10, digits_half_num1);
	int half_zeros_num2 = fast_pow(10, digits_half_num2);

	a = num1 / half_zeros_num1;
	b = num1 % half_zeros_num1;
	c = num2 / half_zeros_num2;
	d = num2 % half_zeros_num2;

	// calculating ac, bd, (a+b)*(c+d)

	int ac, bd, ab_cd;

	ac = karatsuba_multi(a, c);
	bd = karatsuba_multi(b, d);
	ab_cd = karatsuba_multi(a + b, c + d);

	// padding zeros calculation

	int ac_padding_zeros, abcd_padding_zeros, half_digit_sum;

	half_digit_sum = digits_half_num1 + digits_half_num2;

	ac_padding_zeros = fast_pow(10, half_digit_sum);
	abcd_padding_zeros = fast_pow(10, half_digit_sum/2);
		
	return (ac * ac_padding_zeros) + bd + ((ab_cd - ac - bd) * abcd_padding_zeros);
}

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int num1, num2;
	cin >> num1 >> num2;

	int simple_multi, ks_multi;

	// simple_multi = traditional_multi(num1, num2);
	auto start = high_resolution_clock::now();
	simple_multi = num1 * num2;
	auto stop = high_resolution_clock::now();
	
	auto duration = duration_cast <nanoseconds> (stop - start);
	
	cout << "Simple multiplication \t\t= " << simple_multi << endl;
	cout << "Time: " << duration.count() << " nanoseconds\n\n";
	
	start = high_resolution_clock::now();
	ks_multi = karatsuba_multi(num1, num2);
	stop = high_resolution_clock::now();

	duration = duration_cast <nanoseconds> (stop - start);

	cout << "Karatsuba multiplication\t= " << ks_multi << endl;
	cout << "Time: " << duration.count() << " nanoseconds\n\n";
}