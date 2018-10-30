#include <cstdio>

#include "keyboard_input.hpp"


namespace testing_di::input_policies {

  char keyboard::get( ) const
  {
    return std::getchar( );
  }

} // namespace testing_di::input_policies
