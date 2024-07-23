// ======================================================================
// \title  SamE70UartDriver.hpp
// \author dtriska
// \brief  hpp file for SamE70UartDriver component implementation class
// ======================================================================

#ifndef COMPONENTS_SAME70UARTDRIVER_HPP
#define COMPONENTS_SAME70UARTDRIVER_HPP

#include "Components/SamE70UartDriver/SamE70UartDriverComponentAc.hpp"

namespace Components {

  class SamE70UartDriver :
    public SamE70UartDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object SamE70UartDriver
      //!
      SamE70UartDriver(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object SamE70UartDriver
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object SamE70UartDriver
      //!
      ~SamE70UartDriver();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for uartWrite
      //!
      void uartWrite_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &dataBuffer /*!< The buffer containing data to be written*/
      );

      //! Handler implementation for uartRead
      //!
      void uartRead_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &buffer /*!< The buffer to store read data*/
      );

    PRIVATE:

      // Add any necessary private data members here

  };

} // end namespace Components

#endif // COMPONENTS_SAME70UARTDRIVER_HPP
