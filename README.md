# Karatsuba-Algorithm
The working header file for karatsuba multiplication algorithm is 
```
Karatsuba-Algorithm/saved copies/lib/karatsuba_cpp_int.hpp
```
This header file works with type cpp_int of Boost Multiprecision library.
The function prototype for karatsuba multiplication is
```cpp
cpp_int karatsuba(cpp_int, cpp_int);
```

A sample code for the same is added in the following directory, *Karatsuba-Algorithm/saved copies/lib/*.
Also find the sample code here.
```cpp
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
```
Please feel free to suggest changes.
