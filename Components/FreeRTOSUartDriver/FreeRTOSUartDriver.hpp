// ======================================================================
// \title  FreeRTOSUartDriver.hpp
// \author dtriska
// \brief  hpp file for FreeRTOSUartDriver component implementation class
// ======================================================================

#ifndef Components_FreeRTOSUartDriver_HPP
#define Components_FreeRTOSUartDriver_HPP

#include "Components/FreeRTOSUartDriver/FreeRTOSUartDriverComponentAc.hpp"

namespace Components {

  class FreeRTOSUartDriver :
    public FreeRTOSUartDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct FreeRTOSUartDriver object
      FreeRTOSUartDriver(
          const char* const compName //!< The component name
      );

      //! Destroy FreeRTOSUartDriver object
      ~FreeRTOSUartDriver();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for send
      //!
      //! Port invoked to send data out the driver
      Drv::SendStatus send_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::Buffer& sendBuffer //!< Data to send
      ) override;

  };

}

#endif
