#include <cstdlib>
#include <iostream>

#include <boost/di.hpp>

#include "fixed_string_input.hpp"
#include "fill_buffer_output.hpp"
#include "processor.hpp"

int main( )
{
  namespace di = boost::di;
  using namespace testing_di;

  input_policies::fixed_string k( { 'a' , 'b' , 'c' , 'd' , 'e' , EOF } );

  std::string output;
  output_policies::fill_buffer f( output );

  const auto injector = di::make_injector(
      di::bind< class InputPolicy >( ).to< input_policies::fixed_string >( k ) ,
      di::bind< class OutputPolicy >( ).to< output_policies::fill_buffer >( f ) );

  auto processor = injector.create< testing_di::processor >( );

  processor.run( );

  std::cout << output;

  return EXIT_SUCCESS;
}
