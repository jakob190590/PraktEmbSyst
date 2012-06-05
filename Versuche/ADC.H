//****************************************************************************
// @Module        ADC
// @Filename      ADC.H
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all function prototypes and macros for
//                the Analog / Digital Converter 
//
//----------------------------------------------------------------------------
// @Date          21.05.2012 21:30:11
//
//****************************************************************************

//****************************************************************************
// @Prototypes of global functions
//****************************************************************************

void ADC_vInit(void);
uword ADC_uwReadConv(void);


// USER CODE BEGIN (ADCHeader,1)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

//****************************************************************************
// @Macro         ADC_vStartConv()
//
//----------------------------------------------------------------------------
// @Description   This macro starts the A/D conversion.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          21.05.2012 21:30:11
//
//****************************************************************************

#define ADC_vStartConv() ADST = 1


//****************************************************************************
// @Macro         ADC_vConfConv(Mode, Channel)
//
//----------------------------------------------------------------------------
// @Description   This macro configures a new A/D conversion. In fixed channel
//                single conversion mode (FIXED) the forwarded channel is 
//                converted once. In fixed channel continuous conversion mode
//                (FIXED_CONTI) the forwarded channel is converted
//                continuously. In auto scan single conversion mode (SCAN) a 
//                sequence beginning with the forwarded channel and ending 
//                with channel 0 is converted. In auto scan continuous 
//                conversion mode (SCAN_CONTI) the sequence is converted
//                continuously. To start the conversion it is necessary to 
//                call ADC_vStartConv.
//                Note:
//                While a conversion is in progress, the mode and the channel
//                may be changed. The new mode will be evaluated after the 
//                current conversion.The new channel will be evaluated after 
//                the current conversion (fixed channel modes) or after the 
//                current conversion sequence (auto scan modes).
//                
//                The following constants are available for Mode:
//                FIXED
//                FIXED_CONTI
//                SCAN
//                SCAN_CONTI
//                
//                The following constants are available for Channel:
//                AN0 - AN7 (see @Defines in header file)
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    conversion mode
// @Parameters    channel number
//
//----------------------------------------------------------------------------
// @Date          21.05.2012 21:30:11
//
//****************************************************************************

#define ADC_vConfConv(Mode,Channel) ADCON = (ADCON & 0xFF00)| Mode << 4 | Channel


//****************************************************************************
// @Macro         ADC_bConvReady()
//
//----------------------------------------------------------------------------
// @Description   This macro detects the end of a conversion (ADCIR). 
//                If the conversion is completed, the ADDAT register
//                can be read with the function ADC_uwReadConv.
//
//----------------------------------------------------------------------------
// @Returnvalue   returns a 1 if conversion is completed, else 0
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          21.05.2012 21:30:11
//
//****************************************************************************

#define ADC_bConvReady() ADCIR



// USER CODE BEGIN (ADCHeader,2)

// USER CODE END


/****************************************************************************
* @Defines                                                                   
****************************************************************************/

#define FIXED 0
#define FIXED_CONTI 1
#define SCAN 2
#define SCAN_CONTI 3

// defines for the parameter Channel
#define AN0 0
#define AN1 1
#define AN2 2
#define AN3 3
#define AN4 4
#define AN5 5
#define AN6 6
#define AN7 7



// USER CODE BEGIN (ADCHeader,3)

#define ADNUM 3 // Anzahl der Kanaele

// USER CODE END

//****************************************************************************
// @Interrupt Vectors
//****************************************************************************



// USER CODE BEGIN (ADCHeader,4)

// USER CODE END

