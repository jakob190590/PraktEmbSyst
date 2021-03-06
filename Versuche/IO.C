//****************************************************************************
// @Module        Ports
// @Filename      IO.C
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all functions that use the general IO ports.
//                
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************







//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (IO_General,1)

// USER CODE END


//***************************************************************************
// @Global Variables
//***************************************************************************

// USER CODE BEGIN (IO_General,2)

// USER CODE END


//****************************************************************************
// @Function      void IO_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This function initializes the IO component. It effects all
//                necessary configurations of the SFR, depending on the selected
//                operating mode.
//                Note:
//                Only those pins that are initialized are used as general IO.
//                If the alternate function of a pin is used, this pin is
//                initialized in the initialization function of the peripheral.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

void IO_vInit(void)
{
  /// P8.0 .. P8.7  switch on special threshold input levels
  /// P3.8 .. P3.15 switch on standard TTL input levels
  /// P3.0 .. P3.7  switch on standard TTL input levels
  PICON = 0x0080;

  /// no pin of port 0 low is used as general IO

  /// no pin of port 0 high is used as general IO

  //  initializes port 1 low
  /// P1L.4 is used as general IO
  /// -  the pin is configured as output
  /// -  the pin status is low level
  /// P1L.5 is used as general IO
  /// -  the pin is configured as output
  /// -  the pin status is low level
  /// P1L.6 is used as general IO
  /// -  the pin is configured as output
  /// -  the pin status is low level
  /// P1L.7 is used as general IO
  /// -  the pin is configured as output
  /// -  the pin status is low level
  P1L   = 0x00;          // set port data register
  DP1L  = 0xF0;          // set port direction register

  //  initializes port 1 high
  /// P1H.4 is used as general IO
  /// -  the pin is configured as input
  /// P1H.5 is used as general IO
  /// -  the pin is configured as input
  /// P1H.6 is used as general IO
  /// -  the pin is configured as input
  /// P1H.7 is used as general IO
  /// -  the pin is configured as input
  P1H   = 0x00;          // set port data register
  DP1H  = 0x00;          // set port direction register

  /// no pin of port 3 is used as general IO

  /// no pin of port 4 is used as general IO

  /// no pin of port 5 is used as general input

  /// no pin of port 8 is used as general IO


  // USER CODE BEGIN (IO_Init,1)

  // USER CODE END

}


// USER CODE BEGIN (IO_General,3)

// USER CODE END

