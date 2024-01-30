/**
 * In C++ we can use cxxabi.h with a major of one exposed function through abi namespace which is
 * __cxa_demangle() to demangle the mangled name e.g. m -> unsigned long for std::thread::id
 * in this testcase.
 *
 * Compile:
 * g++ -std=c++17 <source-file> Demangle.cpp
 *
 * (notice doesn't need to link with -lpthread as we didn't spawn a new thread at all)
 */
#include <iostream>
#include <thread>
#include <cxxabi.h>
#include <typeinfo>
#include <memory>
#include <cstdlib>

int main()
{
	auto nameDeleter = [](char* namePtr) {
		// pointer can be null in which free() won't perform anything
		std::free(namePtr);
		std::cout << "deleter of name called" << std::endl;
	};

	using DemangledNameType = std::unique_ptr<char, decltype(nameDeleter)>;

	int status;
	const char* mangledName = typeid(std::thread::native_handle_type).name();
	std::cout << "mangled name: " << mangledName << std::endl;
	DemangledNameType dnamePtr(abi::__cxa_demangle(mangledName, nullptr, nullptr, &status), std::move(nameDeleter));
	if (status != 0)
		std::cerr << "[Error] operation failed with status: " << status << std::endl;
	else
		std::cout << "Demangled name is '" << dnamePtr.get() << "'" << std::endl;
	// automatically cleanup the allocated memory
	return 0;
}
