#include <string>

namespace testing_di::output_policies {

  class fill_buffer
  {
    public:
      fill_buffer( std::string & buffer );
      void put( char ) const;

      const std::string & get_buffer( ) const;

    private:
      std::string & m_buffer;
  };

} // namespace testing_di::input_policies
