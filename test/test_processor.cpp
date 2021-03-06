#include <cstdlib>

#include <boost/di.hpp>

#include "fixed_string.hpp"
#include "processor.hpp"

int main( )
{
  namespace di = boost::di;
  using namespace testing_di;

  input_policies::fixed_string k( { 'a' , 'b' , 'c' , 'd' , 'e' , EOF } );

  const auto injector = di::make_injector(
      di::bind< class InputPolicy >( ).to< input_policies::fixed_string >( k ) );

  auto processor = injector.create< testing_di::processor >( );

  processor.run( );

  return EXIT_SUCCESS;
}
