// ======================================================================
// \title  usart1Driver.hpp
// \author dtriska
// \brief  hpp file for usart1Driver component implementation class
// ======================================================================

#ifndef Components_usart1Driver_HPP
#define Components_usart1Driver_HPP

#include "Components/usart1Driver/usart1DriverComponentAc.hpp"
#include "Os/Task.hpp"

namespace Components {

  class usart1Driver :
    public usart1DriverComponentBase
  {

    public:
      enum UartBaudRate {
        BAUD_9600,
        BAUD_19200,
        BAUD_38400,
        BAUD_57600,
        BAUD_115200
      };

      enum FlowControl {
        NO_FLOW,
        HW_FLOW
      };

      enum Parity {
        PARITY_NONE,
        PARITY_ODD,
        PARITY_EVEN
      };

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct usart1Driver object
      usart1Driver(
          const char* const compName //!< The component name
      );

      //! Destroy usart1Driver object
      ~usart1Driver();

      // ----------------------------------------------------------------------
      // Public member functions
      // ----------------------------------------------------------------------

      //! Initialize the USART1 driver
      void init(const NATIVE_INT_TYPE instance);

      //! Configure the USART1 settings
      void configureUSART1();

      //! Write data to USART1
      void writeUSART1(uint8_t* data, size_t size);

      //! Read data from USART1
      size_t readUSART1(uint8_t* buffer, size_t size);

      //! Open the USART1 device
      bool open(const char* uartDevice, UartBaudRate baudRate, FlowControl flowControl, Parity parity, size_t bufferSize);

      //! Start the read thread
      void startReadThread(int priority, size_t stackSize);

      //! Quit the read thread
      void quitReadThread();

      //! Join the read thread
      void join(void** value_ptr);

    private:
      // Required virtual functions from base class
      virtual Drv::SendStatus ByteStreamSend_handler(NATIVE_INT_TYPE portNum, Fw::Buffer& buffer) override;
      virtual void schedIn_handler(NATIVE_INT_TYPE portNum, NATIVE_UINT_TYPE context) override;
      virtual Drv::SendStatus writeUSART1_handler(NATIVE_INT_TYPE portNum, Fw::Buffer& buffer) override;

      // Private members for thread management
      volatile bool m_quitReadThread;
      Os::Task m_readTask;

      // Private method for read task entry point
      static void serialReadTaskEntry(void* ptr);
  };

}

#endif
