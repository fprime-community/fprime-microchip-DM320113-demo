module Components {

  passive component FreeRTOSUartDriver {

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------

    @ Write data to UART
    sync input port write: Fw.BufferSend

    @ Read data from UART using polling
    sync input port readPoll: Fw.BufferSend

    @ Read data from UART using callback
    output port readCallback: Fw.BufferSend

    @ Scheduler input
    sync input port schedIn: Svc.Sched

    # ----------------------------------------------------------------------
    # Special ports
    # ----------------------------------------------------------------------

    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------

    # ----------------------------------------------------------------------
    # Telemetry
    # ----------------------------------------------------------------------

  }

}
