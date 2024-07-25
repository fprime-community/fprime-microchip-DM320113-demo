// ======================================================================
// \title  FreeRTOSUartDriver.cpp
// \author dtriska
// \brief  cpp file for FreeRTOSUartDriver component implementation class
// ======================================================================

#include "Components/FreeRTOSUartDriver/FreeRTOSUartDriver.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  FreeRTOSUartDriver ::
    FreeRTOSUartDriver(const char* const compName) :
      FreeRTOSUartDriverComponentBase(compName)
  {

  }

  FreeRTOSUartDriver ::
    ~FreeRTOSUartDriver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void FreeRTOSUartDriver ::
    readPoll_handler(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer& fwBuffer
    )
  {
    // TODO
  }

  void FreeRTOSUartDriver ::
    schedIn_handler(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
  }

  void FreeRTOSUartDriver ::
    write_handler(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer& fwBuffer
    )
  {
    // TODO
  }

}
