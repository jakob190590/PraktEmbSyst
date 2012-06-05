//****************************************************************************
// @Module        ADC
// @Filename      ADC.C
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all functions that use the ADC peripheral
//                
//
//----------------------------------------------------------------------------
// @Date          05.06.2012 15:19:14
//
//****************************************************************************


//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (ADC_General,1)

// USER CODE END


//***************************************************************************
// @Global Variables
//***************************************************************************

// USER CODE BEGIN (ADC_General,2)

// USER CODE END


//****************************************************************************
// @Function      void ADC_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This function initializes the ADC component. It effects all
//                necessary configurations of the SFR, depending on the selected
//                operating mode. The configuration determines whether the ADC
//                interrupts are to be released, and the priority of the 
//                released interrupt.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          05.06.2012 15:19:14
//
//****************************************************************************

void ADC_vInit(void)
{
  /// digital input stage is disconnected from port line P5.0
  /// digital input stage is disconnected from port line P5.1
  /// digital input stage is disconnected from port line P5.2
  /// digital input stage is connected to port line P5.3
  /// digital input stage is connected to port line P5.4
  /// digital input stage is connected to port line P5.5
  /// digital input stage is connected to port line P5.6
  /// digital input stage is connected to port line P5.7

  P5DIDIS = 0x0007;

  /// fixed channel single conversion
  /// converts channel 0
  /// ADC start bit is set
  /// converter clock = fcpu / 24 (1,200 µs)
  /// sample time = 9,600 µs 
  ADCON   = 0x0080;

  //  USER CODE BEGIN (ADC_Init,1)

  //  USER CODE END

}


//****************************************************************************
// @Function      uword ADC_uwReadConv(void)
//
//----------------------------------------------------------------------------
// @Description   This function returns the result of a conversion.
//                This function must be called after each conversion.
//                The lower 10 bits contain the conversion result
//                while the upper 4 bits identify the converted
//                analog channel.
//
//----------------------------------------------------------------------------
// @Returnvalue   conversion result
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          05.06.2012 15:19:14
//
//****************************************************************************

uword ADC_uwReadConv(void)
{
  ADCIR = 0;
  return(ADDAT);
}




// USER CODE BEGIN (ADC_General,3)

// USER CODE END

