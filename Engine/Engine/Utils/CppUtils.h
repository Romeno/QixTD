#pragma once


#define del(pObj) SafeDelete(pObj); pObj = nullptr;



template <class T>
void SafeDelete(T* pObj)
{
	if (pObj)
		delete pObj;
}

//#define DECLARE_SINGLETON(Class) \
//static Class* Inst() { if (!s_instance) initInstance(); return s_instance; }\
//static void initInstance() { s_instance = new Class(); }\
//static Class* s_instance;
//
//#define DEFINE_SINGLETON(Class) Class* Class::s_instance = nullptr;

#define MADD(e) map[e] = #e;


