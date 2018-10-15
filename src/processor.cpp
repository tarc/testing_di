#include "processor.hpp"

namespace testing_di {

  template< class TInput >
  processor< TInput >::processor( TInput & input )
    : m_inputer( input )
  {
    input.get( );
  }

  template< class TInput >
  void processor< TInput >::run( )
  {
    m_inputer.get( );
  }

} // namespace testing_di


#include "input_policies/keyboard.hpp"

template class testing_di::processor< testing_di::input_policies::keyboard >;
