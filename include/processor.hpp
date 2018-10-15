namespace testing_di
{

  template< class TInput = class InputPolicy >
  class processor
  {
    public:
      processor( TInput & );

      void run( );

    private:
      TInput & m_inputer;
  };

} // namespace testing_di
