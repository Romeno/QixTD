#pragma once


template <class A>
class Singleton
{
public:
	friend A;

	static A* Inst() {
		if ( !p_instance )
			InitInstance();
		return p_instance;
	}

	static void InitInstance() { new A(); }

protected:
	static A* p_instance;

	Singleton() { p_instance = (A*)this; };
	Singleton(const Singleton&);
	Singleton& operator=(Singleton&);
};

template <class A>
A* Singleton<A>::p_instance = 0;