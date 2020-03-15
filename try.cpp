#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>
#include "karat.hpp"

using namespace std::chrono;
using boost::multiprecision::cpp_int;
using namespace std;

// int main(){
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);

// 	cpp_int a, b;
// 	cin >> a >> b;
	
// 	cpp_int ans_karat = karatsuba(a, b);
// 	cpp_int ans_default = a * b;

// 	cout << "Karatsuba:\t" << ans_karat << endl;
// 	cout << "Default:\t" << ans_default << endl;

// 	if(ans_default ^ ans_karat == 0)
// 		cout << "Same" << endl;
// 	else 
// 		cout << "Different" << endl;
// }

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cpp_int num1, num2;
	cin >> num1 >> num2;

	cpp_int simple_multi, ks_multi;

	auto start = high_resolution_clock::now();
	simple_multi = num1 * num2;
	auto stop = high_resolution_clock::now();
	
	auto duration = duration_cast <nanoseconds> (stop - start);
	
	cout << "Simple multiplication \t\t= " << simple_multi << endl;
	cout << "Time: " << duration.count() << " nanoseconds\n\n";
	
	start = high_resolution_clock::now();
	ks_multi = karatsuba(num1, num2);
	stop = high_resolution_clock::now();

	duration = duration_cast <nanoseconds> (stop - start);

	cout << "Karatsuba multiplication\t= " << ks_multi << endl;
	cout << "Time: " << duration.count() << " nanoseconds\n\n";
}