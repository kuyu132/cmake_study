#include <iostream>
#include <string>
#include <cstdlib>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

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

std::string say_hello2() {
    std::string arch_info(TOSTRING(ARCHITECTURE));
    arch_info += std::string(" architecture. ");
#ifdef IS_32_BIT_ARCH
    return arch_info + std::string("Compiled on a 32 bit host processor.");
#elif IS_64_BIT_ARCH
    return arch_info + std::string("Compiled on a 64 bit host processor.");
#else
    return arch_info + std::string("Neither 32 nor 64 bit, puzzling ...");
#endif
}

int main() {
    std::cout << say_hello() << std::endl;
    std::cout << say_hello1() << std::endl;
    std::cout << say_hello2() << std::endl;
    return 0;
}
