module Components {
    @ Usart Driver component for DM320113 Demo
    passive component usart1Driver {
        
        @ Polling for receiving data
        sync input port schedIn: Svc.Sched

        @ Indicates the driver has connected to the UART device
        output port ready: Drv.ByteStreamReady

        @Allocate new buffer
        output port allocate: Fw.BufferGet

        @return the allocated buffer
        output port deallocate: Fw.BufferSend

        @ Takes data to transmit out the UART device
        guarded input port ByteStreamSend: Drv.ByteStreamSend

        @ Takes data to transmit out the UART device
        output port $recv: Drv.ByteStreamRecv

    }
}