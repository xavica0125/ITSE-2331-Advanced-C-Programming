#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <new>

using std::cout; using std::cerr; using std::cin; using std::string;

using std::invalid_argument; using std::bad_alloc; using std::set_new_handler;

void divByZero(int x, int y);

void rethrowException();

int rethrowExceptionHelper(int x, int y);

void stackUnwind(int x);

void stackHelper1(int x);

void stackHelper2(int x);

void badAllocException();

void setNewHandler();

void customNewHandler();

