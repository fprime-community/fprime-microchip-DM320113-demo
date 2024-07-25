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

      // Unsure if needed
      //! Configure UART parameters
      enum UartBaudRate {
        BAUD_115K=115200
      };

      // Unsure if needed
      enum UartFlowControl { NO_FLOW, HW_FLOW };
      
      // Unsure if needed
      enum UartParity { PARITY_NONE, PARITY_ODD, PARITY_EVEN };

      // Unsure if needed
      // Open device with specified baud and flow control.
      bool open(const char* const device, UartBaudRate baud, UartFlowControl fc, UartParity parity, NATIVE_INT_TYPE allocationSize);

      //! Destroy FreeRTOSUartDriver object
      ~FreeRTOSUartDriver();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for readPoll
      //!
      //! Read data from UART using polling
      void readPoll_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::Buffer& fwBuffer //!< The buffer
      ) override;

      //! Handler implementation for schedIn
      //!
      //! Scheduler input
      void schedIn_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      ) override;

      //! Handler implementation for write
      //!
      //! Write data to UART
      void write_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::Buffer& fwBuffer //!< The buffer
      ) override;

  };

}

#endif
