namespace testing_di
{

  template< class TInput = class InputPolicy , class TOutput = class OutputPolicy>
  class processor
  {
    public:
      processor( TInput & , TOutput & );

      void run( );

    private:
      TInput & m_inputer;
      TOutput & m_outputer;
  };

} // namespace testing_di
