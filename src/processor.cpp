#include <cstdio>
#include <iostream>

#include "processor.hpp"

namespace testing_di {

  template< class TInput , class TOutput >
  processor< TInput , TOutput >::processor( TInput & input , TOutput & output )
    : m_inputer( input )
    , m_outputer( output )
  { }

  template< class TInput , class TOutput >
  void processor< TInput , TOutput >::run( )
  {
    auto c = m_inputer.get( );
    while ( c != EOF )
    {
      m_outputer.put( c );
      c = m_inputer.get( );
    }
  }

} // namespace testing_di


#include "input_policy.hpp"
#include "output_policy.hpp"

template class testing_di::processor
<
  testing_di::input_policy , testing_di::output_policy
>;
