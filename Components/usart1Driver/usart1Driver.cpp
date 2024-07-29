#include "Components/usart1Driver/usart1Driver.hpp"
#include "FpConfig.hpp"
#include "device.h"
#include "plib_usart1.h"
#include "interrupts.h"

namespace Components {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  usart1Driver::usart1Driver(const char* const compName) :
    usart1DriverComponentBase(compName)
  {

  }

  void usart1Driver::init() {
    // Initialize USART1
    USART1_Initialize();
  }

  usart1Driver::~usart1Driver()
  {

  }

  // ----------------------------------------------------------------------
  // Public member functions
  // ----------------------------------------------------------------------

  void usart1Driver::configureUSART1() {
    USART_SERIAL_SETUP setup;
    setup.baudRate = 115200;
    setup.dataWidth = USART_DATA_8_BIT; 
    setup.parity = USART_PARITY_NONE; 
    setup.stopBits = USART_STOP_1_BIT; 

    USART1_SerialSetup(&setup, 0);
  }

  void usart1Driver::writeUSART1(uint8_t* data, size_t size) {
    USART1_Write(data, size);
  }

  size_t usart1Driver::readUSART1(uint8_t* buffer, size_t size) {
    return USART1_Read(buffer, size);
  }

}
