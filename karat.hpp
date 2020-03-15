#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

int log10(cpp_int num){

	int counter = 0;
    
    while(num /= 10){
        counter++;
    }

    return counter;
}

cpp_int modular_exponentiation(cpp_int base, cpp_int power){
	
	// base case
	if(power == 0)
		return 1;

	// recursive case
	cpp_int half_power = modular_exponentiation(base, power/2);
	cpp_int half_ans;

	if(power % 2 == 0)
		half_ans = half_power * half_power;
	else
		half_ans = half_power * half_power * base;

	return half_ans;
}

cpp_int karatsuba(cpp_int num1, cpp_int num2){

	int max_num_digits, min_num_digits, half_digits;

	max_num_digits = std::max(log10(num1), log10(num2)) + 1;
	half_digits = max_num_digits / 2;
	
	// base case

	if(num1 == 0 || num2 == 0)
		return 0;

	min_num_digits = std::min(log10(num1), log10(num2)) + 1;

	if(min_num_digits == 1)
		return num1 * num2;

	// recursive case

	cpp_int a, b, c, d;
	cpp_int half_divisor = modular_exponentiation(10, half_digits);

	a = num1 / half_divisor;
	b = num1 % half_divisor;
	c = num2 / half_divisor;
	d = num2 % half_divisor;

	cpp_int ac, bd, abcd;

	ac = karatsuba(a, c);
	bd = karatsuba(b, d);
	abcd = karatsuba(a+b, c+d);

	// padding zeros
	cpp_int ac_padding_zeros, abcd_padding_zeros;

	ac_padding_zeros = modular_exponentiation(10, half_digits * 2);
	abcd_padding_zeros = modular_exponentiation(10, half_digits);


	return (ac * ac_padding_zeros) + bd + ((abcd - ac - bd) * abcd_padding_zeros);

}