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

int main() {
    std::cout << say_hello() << std::endl;
    return 0;
}
