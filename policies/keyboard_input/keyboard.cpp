#include <cstdio>

#include "input_policies/keyboard.hpp"


namespace testing_di::input_policies {

  char keyboard::get( ) const
  {
    return std::getchar( );
  }

} // namespace testing_di::input_policies
