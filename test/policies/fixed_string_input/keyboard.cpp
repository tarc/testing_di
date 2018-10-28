#include <cstdio>
#include <stdexcept>

#include "input_policies/keyboard.hpp"


namespace testing_di::input_policies {

  keyboard::keyboard( std::string input )
    : m_input( std::move( input ) )
    , m_current_position( 0 )
  {
    if ( m_input.empty( ) )
    {
      throw std::logic_error( "Input must be non empty" );
    }
  }

  char keyboard::get( )
  {
    char c = m_input[ m_current_position ++ ];
    m_current_position %= m_input.size( );
    return c;
  }

} // namespace testing_di::input_policies

