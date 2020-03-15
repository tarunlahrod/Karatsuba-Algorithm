#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;

#define ull cpp_int

int log10(ull num){

	int counter = 0;
    
    while(num /= 10){
        counter++;
    }

    return counter;
}

ull modular_exponentiation(ull base, ull power){
	
	// base case
	if(power == 0)
		return 1;

	// recursive case
	ull half_power = modular_exponentiation(base, power/2);
	ull half_ans;

	if(power % 2 == 0)
		half_ans = half_power * half_power;
	else
		half_ans = half_power * half_power * base;

	return half_ans;
}

ull karatsuba(ull num1, ull num2){

	int max_num_digits, min_num_digits, half_digits;

	max_num_digits = max(log10(num1), log10(num2)) + 1;
	half_digits = max_num_digits / 2;
	
	// base case

	if(num1 == 0 || num2 == 0)
		return 0;

	min_num_digits = min(log10(num1), log10(num2)) + 1;

	if(min_num_digits == 1)
		return num1 * num2;

	// recursive case

	ull a, b, c, d;
	ull half_divisor = modular_exponentiation(10, half_digits);

	a = num1 / half_divisor;
	b = num1 % half_divisor;
	c = num2 / half_divisor;
	d = num2 % half_divisor;

	ull ac, bd, abcd;

	ac = karatsuba(a, c);
	bd = karatsuba(b, d);
	abcd = karatsuba(a+b, c+d);

	// padding zeros
	ull ac_padding_zeros, abcd_padding_zeros;

	ac_padding_zeros = modular_exponentiation(10, half_digits * 2);
	abcd_padding_zeros = modular_exponentiation(10, half_digits);


	return (ac * ac_padding_zeros) + bd + ((abcd - ac - bd) * abcd_padding_zeros);

}

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ull a, b;
	cin >> a >> b;

	cout << "Karatsuba:\t" << karatsuba(a, b) << endl;
	cout << "Default:\t" << a*b << endl;
}