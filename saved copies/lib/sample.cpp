#include <boost/multiprecision/cpp_int.hpp>
#include "karatsuba_cpp_int.hpp"

using boost::multiprecision::cpp_int;
using namespace std;

int main(){

	cpp_int num1, num2;

	cin >> num1 >> num2;

	cpp_int ks_multi;

	ks_multi = karatsuba(num1, num2);
	
	cout << "Karatsuba multiplication\t= " << ks_multi << endl;
}
