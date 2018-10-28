#include <string>

namespace testing_di::input_policies {

  class keyboard
  {
    public:
      keyboard( std::string );
      char get( );

    private:
      const std::string m_input;
      size_t m_current_position;
  };

} // namespace testing_di::input_policies

