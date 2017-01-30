#include "Wine.h"

Wine::Wine()
{
}


Wine::~Wine()
{
}

template<class T1, class T2>
T1 & Pair<T1, T2>::first()
{
	return a;
}
template<class T1, class T2>
T2 & Pair<T1, T2>::second()
{
	return b;
}

std::string & Wine::Label() {
	std::cout << "Sarap markasini giriniz: " << std::endl;

}