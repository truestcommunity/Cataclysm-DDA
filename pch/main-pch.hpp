// Workaround to a bug in libstdc++ prior to GCC 11 causing
// Error: attempt to self move assign.
// when compiling with _GLIBCXX_DEBUG
// see https://gcc.gnu.org/bugzilla/show_bug.cgi?id=85828
#if defined(_GLIBCXX_DEBUG) && defined(__GNUC__) && (__GNUC__ < 11)
#include <debug/macros.h>
#undef __glibcxx_check_self_move_assign
#define __glibcxx_check_self_move_assign(x)
#ifdef __glibcxx_check_self_move_assign // suppress unused macro warning
#endif
#endif

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <chrono>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwctype>
#include <deque>
#include <exception>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <optional>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <flatbuffers/flexbuffers.h>
