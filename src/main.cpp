#include <cstdlib>

#include <boost/di.hpp>

#include "processor.hpp"
#include "input_policies/keyboard.hpp"

int main( )
{
  namespace di = boost::di;
  namespace tdi = testing_di;

  const auto injector = di::make_injector(
      di::bind< tdi::InputPolicy >( ).to< tdi::input_policies::keyboard >( ) );

  auto processor = injector.create< tdi::processor >( );

  processor.run( );

  return EXIT_SUCCESS;
}
