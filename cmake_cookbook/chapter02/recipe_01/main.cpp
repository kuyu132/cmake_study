#include <iostream>
#include <string>
#include <cstdlib>

std::string say_hello() {
#ifdef IS_WINDOWS
    return std::string("Hello from Windows!");
#elif IS_LINUX
    return std::string("Hello from Linux!");
#elif IS_MACOS
    return std::string("Hello from macOS!");
#else
    return std::string("Hello from an unknown system!");
#endif
}

std::string say_hello1() {
#ifdef IS_INTEL_CXX_COMPILER
    return std::string("Hello Intel compiler!");
#elif IS_GNU_CXX_COMPILER
    return std::string("Hello GNU compiler!");
#elif IS_PGI_CXX_COMPILER
    return std::string("Hello PGI compiler!");
#elif IS_APPLECLANG_CXX_COMPILER
    return std::string("Hello AppleClang compiler!");
#endif
}

int main() {
    std::cout << say_hello() << std::endl;
    std::cout << say_hello1() << std::endl;
    return 0;
}
