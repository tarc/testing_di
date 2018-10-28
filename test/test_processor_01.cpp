#include <cstdlib>

#include <boost/di.hpp>

#include "processor.hpp"
#include "input_policies/keyboard.hpp"

int main( )
{
  namespace di = boost::di;
  using namespace testing_di;

  std::string input = "abcdef";
  input += EOF;

  const auto injector = di::make_injector(
      di::bind< class InputPolicy >( ).to< input_policies::keyboard >( ) ,
      di::bind< std::string >( ).to( input ) );

  auto processor = injector.create< testing_di::processor >( );

  processor.run( );

  return EXIT_SUCCESS;
}

