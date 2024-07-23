// ======================================================================
// \title  SamE70UartDriver.cpp
// \author dtriska
// \brief  cpp file for SamE70UartDriver component implementation class
// ======================================================================

#include "Components/SamE70UartDriver/SamE70UartDriver.hpp"
#include "FpConfig.hpp"
#include "Fw/Types/Assert.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  SamE70UartDriver ::
    SamE70UartDriver(const char* const compName) :
      SamE70UartDriverComponentBase(compName)
  {

  }

  void SamE70UartDriver ::
    init(const NATIVE_INT_TYPE instance)
  {
    SamE70UartDriverComponentBase::init(instance);
    // Additional initialization if needed
  }

  SamE70UartDriver ::
    ~SamE70UartDriver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void SamE70UartDriver ::
    uartWrite_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &dataBuffer
    )
  {
    FW_ASSERT(dataBuffer.getData());

    // Add code to handle UART write

  }

  void SamE70UartDriver ::
    uartRead_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &buffer
    )
  {
    FW_ASSERT(buffer.getData());

    // Add code to handle UART read

  }

} // end namespace Components
