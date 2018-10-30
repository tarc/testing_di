#include <cstdio>

#include "fill_buffer_output.hpp"


namespace testing_di::output_policies {

  void fill_buffer::put( char c ) const
  {
    std::putchar( c );
  }

} // namespace testing_di::input_policies
