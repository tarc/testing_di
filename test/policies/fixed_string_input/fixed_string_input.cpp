#include <cstdio>
#include <stdexcept>

#include "fixed_string_input.hpp"


namespace testing_di::input_policies {

  fixed_string::fixed_string( std::string input )
    : m_input( std::move( input ) )
    , m_current_position( 0 )
  {
    if ( m_input.empty( ) )
    {
      throw std::logic_error( "Input must be non empty" );
    }
  }

  char fixed_string::get( )
  {
    char c = m_input[ m_current_position ++ ];
    m_current_position %= m_input.size( );
    return c;
  }

} // namespace testing_di::input_policies
