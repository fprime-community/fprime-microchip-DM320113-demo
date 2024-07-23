module Components {
    @ Uart Driver Component to be Used in DM320113 Demo
    passive component SamE70UartDriver {

        # Port for writing data to UART
        sync input port uartWrite: Drv.UartWrite

        # Port for reading data from UART
        sync input port uartRead: Drv.UartRead

    }
}