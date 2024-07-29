// ======================================================================
// \title  usart1Driver.hpp
// \author dtriska
// \brief  hpp file for usart1Driver component implementation class
// ======================================================================

#ifndef Components_usart1Driver_HPP
#define Components_usart1Driver_HPP

#include "Components/usart1Driver/usart1DriverComponentAc.hpp"

namespace Components {

  class usart1Driver :
    public usart1DriverComponentBase
  {

    public:

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
      void init();

      //! Configure the USART1 settings
      void configureUSART1();

      //! Write data to USART1
      void writeUSART1(uint8_t* data, size_t size);

      //! Read data from USART1
      size_t readUSART1(uint8_t* buffer, size_t size);

  };

}

#endif
