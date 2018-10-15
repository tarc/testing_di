namespace testing_di
{
  class InputPolicy;

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