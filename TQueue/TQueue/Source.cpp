#include "TStatus.h"

int main()
{
	setlocale(0, "");
	int a, b, c, d;
	while (true) {
		std::cout << "¬ведите количество такстов, интенсивность потока задач, размер очереди, можность процессора: \n";
		std::cin >> a >> b >> c >> d;
		TStatus Obj(a, b, c, d);
	}
	//( _tact,  _intensity,  _counter,  _power)
	return 0;	
}