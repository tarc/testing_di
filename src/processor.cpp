#include <cstdio>
#include <iostream>

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
    auto c = m_inputer.get( );
    while ( c != EOF )
    {
      std::cout << c;
      c = m_inputer.get( );
    }
  }

} // namespace testing_di


#include "input_policy.hpp"

template class testing_di::processor< testing_di::input_policy >;
