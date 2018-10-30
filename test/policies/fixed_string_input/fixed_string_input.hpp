#include <string>

namespace testing_di::input_policies {

  class fixed_string
  {
    public:
      fixed_string( std::string );
      char get( );

    private:
      const std::string m_input;
      size_t m_current_position;
  };

} // namespace testing_di::input_policies

