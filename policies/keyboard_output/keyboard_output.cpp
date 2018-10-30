#include <cstdio>

#include "keyboard_output.hpp"


namespace testing_di::output_policies {

  void keyboard::put( char c ) const
  {
    std::putchar( c );
  }

} // namespace testing_di::input_policies
