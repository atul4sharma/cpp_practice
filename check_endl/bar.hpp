
#pragma once

#include <iostream>

typedef std::ostream& (*ManipFunc)(std::ostream&);

int check_address(ManipFunc func);

