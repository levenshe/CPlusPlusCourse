// MP1.cpp : Defines the entry point for the console application.
//
#include <iostream> 
#include <tuple>
#include <string>

struct F
{
	template <typename T>
	void operator()(T&& t) { std::cout << "unexpected type: " << typeid(std::forward<T&&>(t)).name() << std::endl; }
	void operator()(int i) { std::cout << "void F::operator()(int): " << i << std::endl; }
	void operator()(double d) { std::cout << "void F::operator()(double): " << d << std::endl; }
	void operator()(char const* s) { std::cout << "void F::operator()(char const*): " << s << std::endl; }
	void operator()(const std::string& s) { std::cout << "void F::operator()(const std::string&): " << s << std::endl; }
	void operator()( std::string& s) { std::cout << "void F::operator()( std::string&): " << s << std::endl; }
};


template <typename... T>
void tuple_visitor(F f, std::tuple<T...> SampleTuple)
{
	f(std::get<0>(SampleTuple));
	f(std::get<1>(SampleTuple));
	f(std::get<2>(SampleTuple));
	f(std::get<3>(SampleTuple));
}

int main()
{
	auto t = std::make_tuple(10, std::string("Test"), 3.14, "Test");
	F f;
	tuple_visitor(f, t); //please implement this tuple_visitor 
	return 0;
}



