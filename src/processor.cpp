#include <cstdio>

#include "processor.hpp"

namespace testing_di {

  template< class TInput >
  processor< TInput >::processor( TInput & input )
    : m_inputer( input )
  {
  }

  template< class TInput >
  void processor< TInput >::run( )
  {
    while ( m_inputer.get( ) != EOF );
  }

} // namespace testing_di


#include "input_policies/keyboard.hpp"

template class testing_di::processor< testing_di::input_policies::keyboard >;