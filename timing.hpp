#pragma once
#include "template.hpp"

clock_t _cur_time;
void beginTiming() { _cur_time = clock(); }
void endTiming() { cout << fixed << setprecision(5) << "-- Operation took " << (clock()-_cur_time)/(long double)(CLOCKS_PER_SEC) << " seconds." << endl; }
