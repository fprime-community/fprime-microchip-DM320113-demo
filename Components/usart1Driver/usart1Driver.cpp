// ======================================================================
// \title  usart1Driver.cpp
// \author dtriska
// \brief  cpp file for usart1Driver component implementation class
// ======================================================================

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
    usart1DriverComponentBase(compName),
    m_quitReadThread(false)
  {

  }

  void usart1Driver::init(const NATIVE_INT_TYPE instance) {
    usart1DriverComponentBase::init(instance);
    // Initialize USART1
    USART1_Initialize();
  }

  usart1Driver::~usart1Driver() {
    if (!m_quitReadThread) {
      quitReadThread();
    }
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

  bool usart1Driver::open(const char* uartDevice, UartBaudRate baudRate, FlowControl flowControl, Parity parity, size_t bufferSize) {
    // Implement functionality to open and configure the USART1 device
    // This may involve setting up the USART1 hardware registers directly
    // according to the parameters provided
    // This is a placeholder for demonstration purposes
    return true;
  }

  void usart1Driver::startReadThread(int priority, size_t stackSize) {
    Os::TaskString task("SerReader");
    // Os::Task::TaskStatus stat = (UPDATED FPP NOT LIKING)
        this->m_readTask.start(task, serialReadTaskEntry, this, priority, stackSize);
    // FW_ASSERT(stat == Os::Task::TASK_OK, stat);
  }

  void usart1Driver::quitReadThread() {
    this->m_quitReadThread = true;
  }

  void usart1Driver::join(void** value_ptr) {
    this->m_readTask.join();
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  Drv::SendStatus usart1Driver::ByteStreamSend_handler(const NATIVE_INT_TYPE portNum, Fw::Buffer& buffer) {
    Drv::SendStatus status = Drv::SendStatus::SEND_OK;
    if (buffer.getData() == nullptr || buffer.getSize() == 0) {
        status = Drv::SendStatus::SEND_ERROR;
    } else {
        this->writeUSART1(buffer.getData(), buffer.getSize());
    }
    if (isConnected_deallocate_OutputPort(0)) {
        deallocate_out(0, buffer);
    }
    return status;
  }

  void usart1Driver::schedIn_handler(const NATIVE_INT_TYPE portNum, const NATIVE_UINT_TYPE context) {
    // Implement scheduling logic if needed
  }

  Drv::SendStatus usart1Driver::writeUSART1_handler(const NATIVE_INT_TYPE portNum, Fw::Buffer& buffer) {
    return this->ByteStreamSend_handler(portNum, buffer);
  }

  void usart1Driver::serialReadTaskEntry(void* ptr) {
    usart1Driver* comp = reinterpret_cast<usart1Driver*>(ptr);
    while (!comp->m_quitReadThread) {
      // Implement reading logic from USART1
      // This is a placeholder for demo
      uint8_t buffer[64];
      size_t size = comp->readUSART1(buffer, sizeof(buffer));
      if (size > 0) {
        Fw::Buffer fwBuffer(buffer, size);
        Drv::RecvStatus status = Drv::RecvStatus::RECV_OK; // Assuming the status is OK
        comp->recv_out(0, fwBuffer, status);
      }
      static NATIVE_UINT_TYPE delay(100); // Delay to prevent busy loop
    }
  }

}