
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "foo.hpp"
#include "bar.hpp"

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

int main()
{
    auto const pid = std::string{"pid[" + std::to_string(getpid()) + "]"};
    std::cout << pid << " Sleeping before loading the so\n";
    std::this_thread::sleep_for(std::chrono::seconds{15});
    std::cout << pid << " Loading the so\n";
    auto handle = dlopen("libfoo_bar.so", RTLD_LAZY);
    if(! handle)
    {
        std::cout << dlerror() << '\n';
        return 1;
    }
    auto const foo   = reinterpret_cast<int(*)(void)>(dlsym(handle, "foo"));
    auto const bar   = reinterpret_cast<int(*)(void)>(dlsym(handle, "bar"));
    auto const error = dlerror();
    if( error != NULL )
    {
        std::cout << "Error -> " << error << "\n";
        return 2;
    }

    std::cout << "foo -> " << foo() << '\n';
    std::cout << "bar -> " << bar() << '\n';
    std::cout << pid << ": Sleeping just before unloading so\n";
    std::this_thread::sleep_for(std::chrono::seconds{30});
    std::cout << pid << ": Unloading the so\n";
    dlclose(handle);
    std::cout << pid << ": Sleeping after unloading so\n";
    std::this_thread::sleep_for(std::chrono::seconds{15});
    return 0;
}

