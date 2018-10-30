#include <cstdio>

#include "fill_buffer_output.hpp"


namespace testing_di::output_policies {

  fill_buffer::fill_buffer( std::string & buffer )
    : m_buffer( buffer )
  { }

  void fill_buffer::put( char c ) const
  {
    m_buffer += c;
  }

  const std::string & fill_buffer::get_buffer( ) const
  {
    return m_buffer;
  }

} // namespace testing_di::input_policies
