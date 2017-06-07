#pragma once


template <class A>
class Singleton
{
public:
	friend A;

	static A* Inst() {
		if (!p_instance)
			p_instance = new A();
		return p_instance;
	}

protected:
	static A* p_instance;

	Singleton() {};
	Singleton(const Singleton&);
	Singleton& operator=(Singleton&);
};

template <class A>
A* Singleton<A>::p_instance = 0;