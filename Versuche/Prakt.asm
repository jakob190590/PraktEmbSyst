;****************************************************************************
; Filename      Prakt.asm
; Project       Prakt.dav
;----------------------------------------------------------------------------
; Description   This file contains the assembler formatted information
;                about the actual project values. It will be used by your
;                programming environment.
;
;                PLEASE DO NOT MODIFY THIS FILE !
;
;----------------------------------------------------------------------------
; Date          21.05.2012 09:36:31
;
;****************************************************************************


; ADC End of Conversion Interrupt Control Register
ADCIC_ADCIE	SET	0
ADCIC_ADCIR	SET	0
ADCIC_GLVL	SET	0
ADCIC_ILVL	SET	0

; A/D Converter Control Register
ADCON_ADBSY	SET	0
ADCON_ADCH	SET	0
ADCON_ADCIN	SET	0
ADCON_ADCRQ	SET	0
ADCON_ADCTC	SET	0
ADCON_ADM	SET	0
ADCON_ADST	SET	1
ADCON_ADSTC	SET	0
ADCON_ADWR	SET	0

; ADC 2 Result Register
ADDAT2_ADRES	SET	0
ADDAT2_CHNR	SET	0

; ADC Result Register
ADDAT_ADRES	SET	0
ADDAT_CHNR	SET	0

; Address Select Register 1
ADDRSEL1_RGSAD	SET	0
ADDRSEL1_RGSZ	SET	0

; Address Select Register 2
ADDRSEL2_RGSAD	SET	0
ADDRSEL2_RGSZ	SET	0

; Address Select Register 3
ADDRSEL3_RGSAD	SET	0
ADDRSEL3_RGSZ	SET	0

; Address Select Register 4
ADDRSEL4_RGSAD	SET	0
ADDRSEL4_RGSZ	SET	0

; ADC Overrun Error Control Register
ADEIC_ADEIE	SET	0
ADEIC_ADEIR	SET	0
ADEIC_GLVL	SET	0
ADEIC_ILVL	SET	0

; Bus Configuration Register 0
BUSCON0_ALECTL0	SET	1
BUSCON0_BTYP	SET	3
BUSCON0_BUSACT0	SET	1
BUSCON0_CSREN0	SET	0
BUSCON0_CSWEN0	SET	0
BUSCON0_MCTC	SET	0
BUSCON0_MTTC0	SET	0
BUSCON0_RWDC0	SET	0

; Bus Configuration Register 1
BUSCON1_ALECTL1	SET	0
BUSCON1_BTYP	SET	3
BUSCON1_BUSACT1	SET	0
BUSCON1_CSREN1	SET	0
BUSCON1_CSWEN1	SET	0
BUSCON1_MCTC	SET	0
BUSCON1_MTTC1	SET	0
BUSCON1_RWDC1	SET	0

; Bus Configuration Register 2
BUSCON2_ALECTL2	SET	0
BUSCON2_BTYP	SET	3
BUSCON2_BUSACT2	SET	0
BUSCON2_CSREN2	SET	0
BUSCON2_CSWEN2	SET	0
BUSCON2_MCTC	SET	0
BUSCON2_MTTC2	SET	0
BUSCON2_RWDC2	SET	0

; Bus Configuration Register 3
BUSCON3_ALECTL3	SET	0
BUSCON3_BTYP	SET	3
BUSCON3_BUSACT3	SET	0
BUSCON3_CSREN3	SET	0
BUSCON3_CSWEN3	SET	0
BUSCON3_MCTC	SET	0
BUSCON3_MTTC3	SET	0
BUSCON3_RWDC3	SET	0

; Bus Configuration Register 4
BUSCON4_ALECTL4	SET	0
BUSCON4_BTYP	SET	3
BUSCON4_BUSACT4	SET	0
BUSCON4_CSREN4	SET	0
BUSCON4_CSWEN4	SET	0
BUSCON4_MCTC	SET	0
BUSCON4_MTTC4	SET	0
BUSCON4_RWDC4	SET	0

; Bit Timing Register
C1BTR_BRP	SET	9
C1BTR_SJW	SET	1
C1BTR_TSEG1	SET	4
C1BTR_TSEG2	SET	3

; Control/Status Register
C1CSR_BOFF	SET	0
C1CSR_CCE	SET	0
C1CSR_EIE	SET	0
C1CSR_EWRN	SET	0
C1CSR_IE	SET	0
C1CSR_INIT	SET	1
C1CSR_LEC	SET	0
C1CSR_RXOK	SET	0
C1CSR_SIE	SET	0
C1CSR_TXOK	SET	0

; Global Mask Short
C1GMS_ID18	SET	1
C1GMS_ID19	SET	1
C1GMS_ID20	SET	1
C1GMS_ID21	SET	1
C1GMS_ID22	SET	1
C1GMS_ID23	SET	1
C1GMS_ID24	SET	1
C1GMS_ID25	SET	1
C1GMS_ID26	SET	1
C1GMS_ID27	SET	1
C1GMS_ID28	SET	1

; Interrupt Register
C1IR_INTID	SET	0

; Lower Global Mask Long
C1LGML_ID0	SET	1
C1LGML_ID1	SET	1
C1LGML_ID10	SET	1
C1LGML_ID11	SET	1
C1LGML_ID12	SET	1
C1LGML_ID2	SET	1
C1LGML_ID3	SET	1
C1LGML_ID4	SET	1
C1LGML_ID5	SET	1
C1LGML_ID6	SET	1
C1LGML_ID7	SET	1
C1LGML_ID8	SET	1
C1LGML_ID9	SET	1

; Lower Mask of Last Message
C1LMLM_ID0	SET	0
C1LMLM_ID1	SET	0
C1LMLM_ID10	SET	0
C1LMLM_ID11	SET	0
C1LMLM_ID12	SET	0
C1LMLM_ID2	SET	0
C1LMLM_ID3	SET	0
C1LMLM_ID4	SET	0
C1LMLM_ID5	SET	0
C1LMLM_ID6	SET	0
C1LMLM_ID7	SET	0
C1LMLM_ID8	SET	0
C1LMLM_ID9	SET	0

; Upper Global Mask Long
C1UGML_ID13	SET	1
C1UGML_ID14	SET	1
C1UGML_ID15	SET	1
C1UGML_ID16	SET	1
C1UGML_ID17	SET	1
C1UGML_ID18	SET	1
C1UGML_ID19	SET	1
C1UGML_ID20	SET	1
C1UGML_ID21	SET	1
C1UGML_ID22	SET	1
C1UGML_ID23	SET	1
C1UGML_ID24	SET	1
C1UGML_ID25	SET	1
C1UGML_ID26	SET	1
C1UGML_ID27	SET	1
C1UGML_ID28	SET	1

; Upper Mask of Last Message
C1UMLM_ID13	SET	0
C1UMLM_ID14	SET	0
C1UMLM_ID15	SET	0
C1UMLM_ID16	SET	0
C1UMLM_ID17	SET	0
C1UMLM_ID18	SET	0
C1UMLM_ID19	SET	0
C1UMLM_ID20	SET	0
C1UMLM_ID21	SET	0
C1UMLM_ID22	SET	0
C1UMLM_ID23	SET	0
C1UMLM_ID24	SET	0
C1UMLM_ID25	SET	0
C1UMLM_ID26	SET	0
C1UMLM_ID27	SET	0
C1UMLM_ID28	SET	0

; CAPCOM Channel 10 Interrupt Control Register
CC10IC_CC10IE	SET	1
CC10IC_CC10IR	SET	0
CC10IC_GLVL	SET	0
CC10IC_ILVL	SET	0

; CAPCOM Channel 11 Interrupt Control Register
CC11IC_CC11IE	SET	1
CC11IC_CC11IR	SET	0
CC11IC_GLVL	SET	0
CC11IC_ILVL	SET	0

; CAPCOM Channel 16 Interrupt Control Register
CC16IC_CC16IE	SET	0
CC16IC_CC16IR	SET	0
CC16IC_GLVL	SET	0
CC16IC_ILVL	SET	0

; CAPCOM 2 Register 16
CC16_CC16	SET	0

; CAPCOM Channel 17 Interrupt Control Register
CC17IC_CC17IE	SET	0
CC17IC_CC17IR	SET	0
CC17IC_GLVL	SET	0
CC17IC_ILVL	SET	0

; CAPCOM 2 Register 17
CC17_CC17	SET	0

; CAPCOM Channel 18 Interrupt Control Register
CC18IC_CC18IE	SET	0
CC18IC_CC18IR	SET	0
CC18IC_GLVL	SET	0
CC18IC_ILVL	SET	0

; CAPCOM 2 Register 18
CC18_CC18	SET	0

; CAPCOM Channel 19 Interrupt Control Register
CC19IC_CC19IE	SET	1
CC19IC_CC19IR	SET	0
CC19IC_GLVL	SET	1
CC19IC_ILVL	SET	5

; CAPCOM 2 Register 19
CC19_CC19	SET	0

; CAPCOM Channel 24 Interrupt Control Register
CC24IC_CC24IE	SET	0
CC24IC_CC24IR	SET	0
CC24IC_GLVL	SET	0
CC24IC_ILVL	SET	0

; CAPCOM 2 Register 24
CC24_CC24	SET	0

; CAPCOM Channel 25 Interrupt Control Register
CC25IC_CC25IE	SET	0
CC25IC_CC25IR	SET	0
CC25IC_GLVL	SET	0
CC25IC_ILVL	SET	0

; CAPCOM 2 Register 25
CC25_CC25	SET	0

; CAPCOM Channel 26 Interrupt Control Register
CC26IC_CC26IE	SET	0
CC26IC_CC26IR	SET	0
CC26IC_GLVL	SET	0
CC26IC_ILVL	SET	0

; CAPCOM 2 Register 26
CC26_CC26	SET	0

; CAPCOM Channel 27 Interrupt Control Register
CC27IC_CC27IE	SET	0
CC27IC_CC27IR	SET	0
CC27IC_GLVL	SET	0
CC27IC_ILVL	SET	0

; CAPCOM 2 Register 27
CC27_CC27	SET	0

; CAPCOM 6 Register Channel 0
CC60_CC60	SET	5000

; CAPCOM 6 Register Channel 1
CC61_CC61	SET	5000

; CAPCOM 6 Register Channel 2
CC62_CC62	SET	5000

; CAPCOM 6 Emergency Interrupt Control Register
CC6EIC_CC6EIE	SET	0
CC6EIC_CC6EIR	SET	0
CC6EIC_GLVL	SET	0
CC6EIC_ILVL	SET	0

; CAPCOM 6 Interrupt Control Register
CC6IC_CC6IE	SET	0
CC6IC_CC6IR	SET	0
CC6IC_GLVL	SET	0
CC6IC_ILVL	SET	0

; CAPCOM 6 Mode Control Register
CC6MCON_BCEN	SET	0
CC6MCON_BCERR	SET	0
CC6MCON_BCM	SET	0
CC6MCON_BCMP_BCEM	SET	0
CC6MCON_CC0I	SET	1
CC6MCON_CC1I	SET	1
CC6MCON_CC2I	SET	1
CC6MCON_COUT0I	SET	1
CC6MCON_COUT1I	SET	1
CC6MCON_COUT2I	SET	1
CC6MCON_COUT3I	SET	1
CC6MCON_COUTXI	SET	1
CC6MCON_EBCE	SET	0
CC6MCON_MPWM	SET	1

; CAPCOM 6 Mode Interrupt Control Register
CC6MIC_CC0F	SET	0
CC6MIC_CC0FEN	SET	0
CC6MIC_CC0R	SET	0
CC6MIC_CC0REN	SET	0
CC6MIC_CC1F	SET	0
CC6MIC_CC1FEN	SET	0
CC6MIC_CC1R	SET	0
CC6MIC_CC1REN	SET	0
CC6MIC_CC2F	SET	0
CC6MIC_CC2FEN	SET	0
CC6MIC_CC2R	SET	0
CC6MIC_CC2REN	SET	0
CC6MIC_CT12FC	SET	0
CC6MIC_CT12FP	SET	0
CC6MIC_ECTC	SET	0
CC6MIC_ECTP	SET	0

; CAPCOM 6 Mode Select Register
CC6MSEL_CMSEL0	SET	0
CC6MSEL_CMSEL03	SET	0
CC6MSEL_CMSEL1	SET	0
CC6MSEL_CMSEL13	SET	0
CC6MSEL_CMSEL2	SET	0
CC6MSEL_CMSEL23	SET	0
CC6MSEL_ESMC	SET	0
CC6MSEL_NMCS	SET	0

; CC Register 8 Interrupt Control Register
CC8IC_CC8IE	SET	1
CC8IC_CC8IR	SET	0
CC8IC_GLVL	SET	0
CC8IC_ILVL	SET	0

; CC Register 9 Interrupt Control Register
CC9IC_CC9IE	SET	1
CC9IC_CC9IR	SET	0
CC9IC_GLVL	SET	0
CC9IC_ILVL	SET	0

; CC Mode Control Register 4
CCM4_ACC16	SET	0
CCM4_ACC17	SET	0
CCM4_ACC18	SET	1
CCM4_ACC19	SET	1
CCM4_CCMOD16	SET	0
CCM4_CCMOD17	SET	0
CCM4_CCMOD18	SET	1
CCM4_CCMOD19	SET	2

; CC Mode Control Register 6
CCM6_ACC24	SET	0
CCM6_ACC25	SET	0
CCM6_ACC26	SET	0
CCM6_ACC27	SET	0
CCM6_CCMOD24	SET	0
CCM6_CCMOD25	SET	0
CCM6_CCMOD26	SET	0
CCM6_CCMOD27	SET	0

; CAPCOM 6 Timer 13 Compare Register
CMP13_CMP13	SET	500

; CPU Context Pointer Register
CP_CP	SET	1536

; CPU Code Segment Pointer Register (8 bits)
CSP_SEGNR	SET	0

; CAPCOM 6 Compare Timer Control Register
CTCON_CT12CLK	SET	0
CTCON_CT12R	SET	0
CTCON_CT12RES	SET	1
CTCON_CT13CLK	SET	0
CTCON_CT13P	SET	0
CTCON_CT13R	SET	0
CTCON_CT13RES	SET	1
CTCON_CTM	SET	0
CTCON_ECT13O	SET	0
CTCON_ETRP	SET	0
CTCON_STE12	SET	0
CTCON_STE13	SET	0

; P0H Direction Control Register
DP0H_DP0H_0	SET	0
DP0H_DP0H_1	SET	0
DP0H_DP0H_2	SET	0
DP0H_DP0H_3	SET	0
DP0H_DP0H_4	SET	0
DP0H_DP0H_5	SET	0
DP0H_DP0H_6	SET	0
DP0H_DP0H_7	SET	0

; P0L Direction Control Register
DP0L_DP0L_0	SET	0
DP0L_DP0L_1	SET	0
DP0L_DP0L_2	SET	0
DP0L_DP0L_3	SET	0
DP0L_DP0L_4	SET	0
DP0L_DP0L_5	SET	0
DP0L_DP0L_6	SET	0
DP0L_DP0L_7	SET	0

; P1H Direction Control Register
DP1H_DP1H_0	SET	0
DP1H_DP1H_1	SET	0
DP1H_DP1H_2	SET	0
DP1H_DP1H_3	SET	0
DP1H_DP1H_4	SET	0
DP1H_DP1H_5	SET	0
DP1H_DP1H_6	SET	0
DP1H_DP1H_7	SET	0

; P1L Direction Control Register
DP1L_DP1L_0	SET	0
DP1L_DP1L_1	SET	0
DP1L_DP1L_2	SET	0
DP1L_DP1L_3	SET	0
DP1L_DP1L_4	SET	1
DP1L_DP1L_5	SET	1
DP1L_DP1L_6	SET	1
DP1L_DP1L_7	SET	1

; Port 3 Direction Control Register
DP3_DP3_10	SET	1
DP3_DP3_11	SET	0
DP3_DP3_12	SET	0
DP3_DP3_13	SET	0
DP3_DP3_15	SET	0
DP3_DP3_4	SET	0
DP3_DP3_6	SET	0
DP3_DP3_8	SET	0
DP3_DP3_9	SET	0

; Port 4 Direction Control Register
DP4_DP4_0	SET	0
DP4_DP4_1	SET	0
DP4_DP4_2	SET	0
DP4_DP4_3	SET	0
DP4_DP4_5	SET	0
DP4_DP4_6	SET	0

; Port 8 Direction Control Register
DP8_DP8_0	SET	0
DP8_DP8_1	SET	0
DP8_DP8_2	SET	0
DP8_DP8_3	SET	0

; CPU Data Page Pointer 0 Register (10 bits)
DPP0_DPP0PN	SET	0

; CPU Data Page Pointer 1 Register (10 bits)
DPP1_DPP1PN	SET	1

; CPU Data Page Pointer 2 Register (10 bits)
DPP2_DPP2PN	SET	2

; CPU Data Page Pointer 3 Register (10 bits)
DPP3_DPP3PN	SET	3

; External Interrupt Control Register
EXICON_EXI0ES	SET	1
EXICON_EXI1ES	SET	1
EXICON_EXI2ES	SET	1
EXICON_EXI3ES	SET	1

; External Interrupt Select Register
EXISEL_EXI0SS	SET	0

; Interrupt Sub Node Control Register
ISNC_PLLIE	SET	0
ISNC_PLLIR	SET	0
ISNC_RTCIE	SET	0
ISNC_RTCIR	SET	0

; Lower Arbitration Register 10
LAR10_ID0	SET	0
LAR10_ID1	SET	0
LAR10_ID10	SET	0
LAR10_ID11	SET	0
LAR10_ID12	SET	0
LAR10_ID2	SET	0
LAR10_ID3	SET	0
LAR10_ID4	SET	0
LAR10_ID5	SET	0
LAR10_ID6	SET	0
LAR10_ID7	SET	0
LAR10_ID8	SET	0
LAR10_ID9	SET	0

; Lower Arbitration Register 11
LAR11_ID0	SET	0
LAR11_ID1	SET	0
LAR11_ID10	SET	0
LAR11_ID11	SET	0
LAR11_ID12	SET	0
LAR11_ID2	SET	0
LAR11_ID3	SET	0
LAR11_ID4	SET	0
LAR11_ID5	SET	0
LAR11_ID6	SET	0
LAR11_ID7	SET	0
LAR11_ID8	SET	0
LAR11_ID9	SET	0

; Lower Arbitration Register 12
LAR12_ID0	SET	0
LAR12_ID1	SET	0
LAR12_ID10	SET	0
LAR12_ID11	SET	0
LAR12_ID12	SET	0
LAR12_ID2	SET	0
LAR12_ID3	SET	0
LAR12_ID4	SET	0
LAR12_ID5	SET	0
LAR12_ID6	SET	0
LAR12_ID7	SET	0
LAR12_ID8	SET	0
LAR12_ID9	SET	0

; Lower Arbitration Register 13
LAR13_ID0	SET	0
LAR13_ID1	SET	0
LAR13_ID10	SET	0
LAR13_ID11	SET	0
LAR13_ID12	SET	0
LAR13_ID2	SET	0
LAR13_ID3	SET	0
LAR13_ID4	SET	0
LAR13_ID5	SET	0
LAR13_ID6	SET	0
LAR13_ID7	SET	0
LAR13_ID8	SET	0
LAR13_ID9	SET	0

; Lower Arbitration Register 14
LAR14_ID0	SET	0
LAR14_ID1	SET	0
LAR14_ID10	SET	0
LAR14_ID11	SET	0
LAR14_ID12	SET	0
LAR14_ID2	SET	0
LAR14_ID3	SET	0
LAR14_ID4	SET	0
LAR14_ID5	SET	0
LAR14_ID6	SET	0
LAR14_ID7	SET	0
LAR14_ID8	SET	0
LAR14_ID9	SET	0

; Lower Arbitration Register 15
LAR15_ID0	SET	0
LAR15_ID1	SET	0
LAR15_ID10	SET	0
LAR15_ID11	SET	0
LAR15_ID12	SET	0
LAR15_ID2	SET	0
LAR15_ID3	SET	0
LAR15_ID4	SET	0
LAR15_ID5	SET	0
LAR15_ID6	SET	0
LAR15_ID7	SET	0
LAR15_ID8	SET	0
LAR15_ID9	SET	0

; Lower Arbitration Register 1
LAR1_ID0	SET	0
LAR1_ID1	SET	0
LAR1_ID10	SET	0
LAR1_ID11	SET	0
LAR1_ID12	SET	0
LAR1_ID2	SET	0
LAR1_ID3	SET	0
LAR1_ID4	SET	0
LAR1_ID5	SET	0
LAR1_ID6	SET	0
LAR1_ID7	SET	0
LAR1_ID8	SET	0
LAR1_ID9	SET	0

; Lower Arbitration Register 2
LAR2_ID0	SET	0
LAR2_ID1	SET	0
LAR2_ID10	SET	0
LAR2_ID11	SET	0
LAR2_ID12	SET	0
LAR2_ID2	SET	0
LAR2_ID3	SET	0
LAR2_ID4	SET	0
LAR2_ID5	SET	0
LAR2_ID6	SET	0
LAR2_ID7	SET	0
LAR2_ID8	SET	0
LAR2_ID9	SET	0

; Lower Arbitration Register 3
LAR3_ID0	SET	0
LAR3_ID1	SET	0
LAR3_ID10	SET	0
LAR3_ID11	SET	0
LAR3_ID12	SET	0
LAR3_ID2	SET	0
LAR3_ID3	SET	0
LAR3_ID4	SET	0
LAR3_ID5	SET	0
LAR3_ID6	SET	0
LAR3_ID7	SET	0
LAR3_ID8	SET	0
LAR3_ID9	SET	0

; Lower Arbitration Register 4
LAR4_ID0	SET	0
LAR4_ID1	SET	0
LAR4_ID10	SET	0
LAR4_ID11	SET	0
LAR4_ID12	SET	0
LAR4_ID2	SET	0
LAR4_ID3	SET	0
LAR4_ID4	SET	0
LAR4_ID5	SET	0
LAR4_ID6	SET	0
LAR4_ID7	SET	0
LAR4_ID8	SET	0
LAR4_ID9	SET	0

; Lower Arbitration Register 5
LAR5_ID0	SET	0
LAR5_ID1	SET	0
LAR5_ID10	SET	0
LAR5_ID11	SET	0
LAR5_ID12	SET	0
LAR5_ID2	SET	0
LAR5_ID3	SET	0
LAR5_ID4	SET	0
LAR5_ID5	SET	0
LAR5_ID6	SET	0
LAR5_ID7	SET	0
LAR5_ID8	SET	0
LAR5_ID9	SET	0

; Lower Arbitration Register 6
LAR6_ID0	SET	0
LAR6_ID1	SET	0
LAR6_ID10	SET	0
LAR6_ID11	SET	0
LAR6_ID12	SET	0
LAR6_ID2	SET	0
LAR6_ID3	SET	0
LAR6_ID4	SET	0
LAR6_ID5	SET	0
LAR6_ID6	SET	0
LAR6_ID7	SET	0
LAR6_ID8	SET	0
LAR6_ID9	SET	0

; Lower Arbitration Register 7
LAR7_ID0	SET	0
LAR7_ID1	SET	0
LAR7_ID10	SET	0
LAR7_ID11	SET	0
LAR7_ID12	SET	0
LAR7_ID2	SET	0
LAR7_ID3	SET	0
LAR7_ID4	SET	0
LAR7_ID5	SET	0
LAR7_ID6	SET	0
LAR7_ID7	SET	0
LAR7_ID8	SET	0
LAR7_ID9	SET	0

; Lower Arbitration Register 8
LAR8_ID0	SET	0
LAR8_ID1	SET	0
LAR8_ID10	SET	0
LAR8_ID11	SET	0
LAR8_ID12	SET	0
LAR8_ID2	SET	0
LAR8_ID3	SET	0
LAR8_ID4	SET	0
LAR8_ID5	SET	0
LAR8_ID6	SET	0
LAR8_ID7	SET	0
LAR8_ID8	SET	0
LAR8_ID9	SET	0

; Lower Arbitration Register 9
LAR9_ID0	SET	0
LAR9_ID1	SET	0
LAR9_ID10	SET	0
LAR9_ID11	SET	0
LAR9_ID12	SET	0
LAR9_ID2	SET	0
LAR9_ID3	SET	0
LAR9_ID4	SET	0
LAR9_ID5	SET	0
LAR9_ID6	SET	0
LAR9_ID7	SET	0
LAR9_ID8	SET	0
LAR9_ID9	SET	0

; Message Configuration Register 10
MCFG10_DIR	SET	0
MCFG10_DLC	SET	0
MCFG10_XTD	SET	0

; Message Configuration Register 11
MCFG11_DIR	SET	0
MCFG11_DLC	SET	0
MCFG11_XTD	SET	0

; Message Configuration Register 12
MCFG12_DIR	SET	0
MCFG12_DLC	SET	0
MCFG12_XTD	SET	0

; Message Configuration Register 13
MCFG13_DIR	SET	0
MCFG13_DLC	SET	0
MCFG13_XTD	SET	0

; Message Configuration Register 14
MCFG14_DIR	SET	0
MCFG14_DLC	SET	0
MCFG14_XTD	SET	0

; Message Configuration Register 15
MCFG15_DIR	SET	0
MCFG15_DLC	SET	0
MCFG15_XTD	SET	0

; Message Configuration Register 1
MCFG1_DIR	SET	0
MCFG1_DLC	SET	0
MCFG1_XTD	SET	0

; Message Configuration Register 2
MCFG2_DIR	SET	0
MCFG2_DLC	SET	0
MCFG2_XTD	SET	0

; Message Configuration Register 3
MCFG3_DIR	SET	0
MCFG3_DLC	SET	0
MCFG3_XTD	SET	0

; Message Configuration Register 4
MCFG4_DIR	SET	0
MCFG4_DLC	SET	0
MCFG4_XTD	SET	0

; Message Configuration Register 5
MCFG5_DIR	SET	0
MCFG5_DLC	SET	0
MCFG5_XTD	SET	0

; Message Configuration Register 6
MCFG6_DIR	SET	0
MCFG6_DLC	SET	0
MCFG6_XTD	SET	0

; Message Configuration Register 7
MCFG7_DIR	SET	0
MCFG7_DLC	SET	0
MCFG7_XTD	SET	0

; Message Configuration Register 8
MCFG8_DIR	SET	0
MCFG8_DLC	SET	0
MCFG8_XTD	SET	0

; Message Configuration Register 9
MCFG9_DIR	SET	0
MCFG9_DLC	SET	0
MCFG9_XTD	SET	0

; Message Control Register 10
MCR10_INTPND	SET	1
MCR10_MSGLST	SET	1
MCR10_MSGVAL	SET	1
MCR10_NEWDAT	SET	1
MCR10_RMTPND	SET	1
MCR10_RXIE	SET	1
MCR10_TXIE	SET	1
MCR10_TXRQ	SET	1

; Message Control Register 11
MCR11_INTPND	SET	1
MCR11_MSGLST	SET	1
MCR11_MSGVAL	SET	1
MCR11_NEWDAT	SET	1
MCR11_RMTPND	SET	1
MCR11_RXIE	SET	1
MCR11_TXIE	SET	1
MCR11_TXRQ	SET	1

; Message Control Register 12
MCR12_INTPND	SET	1
MCR12_MSGLST	SET	1
MCR12_MSGVAL	SET	1
MCR12_NEWDAT	SET	1
MCR12_RMTPND	SET	1
MCR12_RXIE	SET	1
MCR12_TXIE	SET	1
MCR12_TXRQ	SET	1

; Message Control Register 13
MCR13_INTPND	SET	1
MCR13_MSGLST	SET	1
MCR13_MSGVAL	SET	1
MCR13_NEWDAT	SET	1
MCR13_RMTPND	SET	1
MCR13_RXIE	SET	1
MCR13_TXIE	SET	1
MCR13_TXRQ	SET	1

; Message Control Register 14
MCR14_INTPND	SET	1
MCR14_MSGLST	SET	1
MCR14_MSGVAL	SET	1
MCR14_NEWDAT	SET	1
MCR14_RMTPND	SET	1
MCR14_RXIE	SET	1
MCR14_TXIE	SET	1
MCR14_TXRQ	SET	1

; Message Control Register 15
MCR15_INTPND	SET	1
MCR15_MSGLST	SET	1
MCR15_MSGVAL	SET	1
MCR15_NEWDAT	SET	1
MCR15_RMTPND	SET	1
MCR15_RXIE	SET	1
MCR15_TXIE	SET	1
MCR15_TXRQ	SET	1

; Message Control Register 1
MCR1_INTPND	SET	1
MCR1_MSGLST	SET	1
MCR1_MSGVAL	SET	1
MCR1_NEWDAT	SET	1
MCR1_RMTPND	SET	1
MCR1_RXIE	SET	1
MCR1_TXIE	SET	1
MCR1_TXRQ	SET	1

; Message Control Register 2
MCR2_INTPND	SET	1
MCR2_MSGLST	SET	1
MCR2_MSGVAL	SET	1
MCR2_NEWDAT	SET	1
MCR2_RMTPND	SET	1
MCR2_RXIE	SET	1
MCR2_TXIE	SET	1
MCR2_TXRQ	SET	1

; Message Control Register 3
MCR3_INTPND	SET	1
MCR3_MSGLST	SET	1
MCR3_MSGVAL	SET	1
MCR3_NEWDAT	SET	1
MCR3_RMTPND	SET	1
MCR3_RXIE	SET	1
MCR3_TXIE	SET	1
MCR3_TXRQ	SET	1

; Message Control Register 4
MCR4_INTPND	SET	1
MCR4_MSGLST	SET	1
MCR4_MSGVAL	SET	1
MCR4_NEWDAT	SET	1
MCR4_RMTPND	SET	1
MCR4_RXIE	SET	1
MCR4_TXIE	SET	1
MCR4_TXRQ	SET	1

; Message Control Register 5
MCR5_INTPND	SET	1
MCR5_MSGLST	SET	1
MCR5_MSGVAL	SET	1
MCR5_NEWDAT	SET	1
MCR5_RMTPND	SET	1
MCR5_RXIE	SET	1
MCR5_TXIE	SET	1
MCR5_TXRQ	SET	1

; Message Control Register 6
MCR6_INTPND	SET	1
MCR6_MSGLST	SET	1
MCR6_MSGVAL	SET	1
MCR6_NEWDAT	SET	1
MCR6_RMTPND	SET	1
MCR6_RXIE	SET	1
MCR6_TXIE	SET	1
MCR6_TXRQ	SET	1

; Message Control Register 7
MCR7_INTPND	SET	1
MCR7_MSGLST	SET	1
MCR7_MSGVAL	SET	1
MCR7_NEWDAT	SET	1
MCR7_RMTPND	SET	1
MCR7_RXIE	SET	1
MCR7_TXIE	SET	1
MCR7_TXRQ	SET	1

; Message Control Register 8
MCR8_INTPND	SET	1
MCR8_MSGLST	SET	1
MCR8_MSGVAL	SET	1
MCR8_NEWDAT	SET	1
MCR8_RMTPND	SET	1
MCR8_RXIE	SET	1
MCR8_TXIE	SET	1
MCR8_TXRQ	SET	1

; Message Control Register 9
MCR9_INTPND	SET	1
MCR9_MSGLST	SET	1
MCR9_MSGVAL	SET	1
MCR9_NEWDAT	SET	1
MCR9_RMTPND	SET	1
MCR9_RXIE	SET	1
MCR9_TXIE	SET	1
MCR9_TXRQ	SET	1

; CPU Multiply Divide Control Register
MDC_MDRIU	SET	0

; CPU Multiply Divide Register - High Word
MDH_MDH	SET	0

; CPU Multiply Divide Register - Low Word
MDL_MDL	SET	0

; Port 3 Open Drain Control Register
ODP3_ODP3_10	SET	0
ODP3_ODP3_11	SET	0
ODP3_ODP3_13	SET	0
ODP3_ODP3_4	SET	0
ODP3_ODP3_6	SET	0
ODP3_ODP3_8	SET	0
ODP3_ODP3_9	SET	0

; Port 8 Open Drain Control Register
ODP8_ODP8_0	SET	0
ODP8_ODP8_1	SET	0
ODP8_ODP8_2	SET	0
ODP8_ODP8_3	SET	0

; Constant Value 1's Register
ONES_0	SET	1
ONES_1	SET	1
ONES_10	SET	1
ONES_11	SET	1
ONES_12	SET	1
ONES_13	SET	1
ONES_14	SET	1
ONES_15	SET	1
ONES_2	SET	1
ONES_3	SET	1
ONES_4	SET	1
ONES_5	SET	1
ONES_6	SET	1
ONES_7	SET	1
ONES_8	SET	1
ONES_9	SET	1

; Port 0 High Register (Upper half)
P0H_P0H_0	SET	0
P0H_P0H_1	SET	0
P0H_P0H_2	SET	0
P0H_P0H_3	SET	0
P0H_P0H_4	SET	0
P0H_P0H_5	SET	0
P0H_P0H_6	SET	0
P0H_P0H_7	SET	0

; Port 0 Low Register (Lower half)
P0L_P0L_0	SET	0
P0L_P0L_1	SET	0
P0L_P0L_2	SET	0
P0L_P0L_3	SET	0
P0L_P0L_4	SET	0
P0L_P0L_5	SET	0
P0L_P0L_6	SET	0
P0L_P0L_7	SET	0

; Port 1 High Register (Upper half)
P1H_P1H_0	SET	0
P1H_P1H_1	SET	0
P1H_P1H_2	SET	0
P1H_P1H_3	SET	0
P1H_P1H_4	SET	0
P1H_P1H_5	SET	0
P1H_P1H_6	SET	0
P1H_P1H_7	SET	0

; Port 1 Low Register (Lower half)
P1L_P1L_0	SET	0
P1L_P1L_1	SET	0
P1L_P1L_2	SET	0
P1L_P1L_3	SET	0
P1L_P1L_4	SET	0
P1L_P1L_5	SET	0
P1L_P1L_6	SET	0
P1L_P1L_7	SET	0

; Port 3 Register
P3_P3_10	SET	1
P3_P3_11	SET	0
P3_P3_12	SET	0
P3_P3_13	SET	0
P3_P3_15	SET	0
P3_P3_4	SET	0
P3_P3_6	SET	0
P3_P3_8	SET	0
P3_P3_9	SET	0

; Port 4 Register (8 bits)
P4_P4_0	SET	0
P4_P4_1	SET	0
P4_P4_2	SET	0
P4_P4_3	SET	0
P4_P4_5	SET	0
P4_P4_6	SET	0

; Port 5 Digital Input Disable
P5DIDIS_P5D_0	SET	1
P5DIDIS_P5D_1	SET	1
P5DIDIS_P5D_2	SET	1
P5DIDIS_P5D_3	SET	0
P5DIDIS_P5D_4	SET	0
P5DIDIS_P5D_5	SET	0
P5DIDIS_P5D_6	SET	0
P5DIDIS_P5D_7	SET	0

; Port 5 Register (read only)
P5_P5_0	SET	0
P5_P5_1	SET	0
P5_P5_2	SET	0
P5_P5_3	SET	0
P5_P5_4	SET	0
P5_P5_5	SET	0
P5_P5_6	SET	0
P5_P5_7	SET	0

; Port 8 Register (8 bits)
P8_P8_0	SET	0
P8_P8_1	SET	0
P8_P8_2	SET	0
P8_P8_3	SET	0

; Port Driver Control Register
PDCR_BIPEC	SET	0
PDCR_NBPEC	SET	0

; PEC Channel 0 Control Register
PECC0_BWT	SET	0
PECC0_COUNT	SET	0
PECC0_INC	SET	0

; PEC Channel 1 Control Register
PECC1_BWT	SET	0
PECC1_COUNT	SET	0
PECC1_INC	SET	0

; PEC Channel 2 Control Register
PECC2_BWT	SET	0
PECC2_COUNT	SET	0
PECC2_INC	SET	0

; PEC Channel 3 Control Register
PECC3_BWT	SET	0
PECC3_COUNT	SET	0
PECC3_INC	SET	0

; PEC Channel 4 Control Register
PECC4_BWT	SET	0
PECC4_COUNT	SET	0
PECC4_INC	SET	0

; PEC Channel 5 Control Register
PECC5_BWT	SET	0
PECC5_COUNT	SET	0
PECC5_INC	SET	0

; PEC Channel 6 Control Register
PECC6_BWT	SET	0
PECC6_COUNT	SET	0
PECC6_INC	SET	0

; PEC Channel 7 Control Register
PECC7_BWT	SET	0
PECC7_COUNT	SET	0
PECC7_INC	SET	0

; Port Input Threshold Control Register
PICON_P3HIN	SET	0
PICON_P3LIN	SET	0
PICON_P8LIN	SET	0

; CPU Program Status Word
PSW_C	SET	0
PSW_E	SET	0
PSW_HLDEN	SET	0
PSW_IEN	SET	1
PSW_ILVL	SET	0
PSW_MULIP	SET	0
PSW_N	SET	0
PSW_USR0	SET	0
PSW_V	SET	0
PSW_Z	SET	0

; System Startup Configuration Register (RO)
RP0H_CLKCFG	SET	7
RP0H_CSSEL	SET	2
RP0H_SALSEL	SET	0
RP0H_WRC	SET	0

; RTC Timer High Register
RTCH_RTCH	SET	0

; RTC Timer Low Register
RTCL_RTCL	SET	0

; Serial Channel 0 Baud Rate Generator Reload Register
S0BG_S0BG	SET	64

; Serial Channel 0 Control Register
S0CON_S0BRS	SET	0
S0CON_S0FE	SET	0
S0CON_S0FEN	SET	0
S0CON_S0LB	SET	0
S0CON_S0M	SET	1
S0CON_S0ODD	SET	0
S0CON_S0OE	SET	0
S0CON_S0OEN	SET	0
S0CON_S0PE	SET	0
S0CON_S0PEN	SET	0
S0CON_S0R	SET	1
S0CON_S0REN	SET	0
S0CON_S0STP	SET	1

; Serial Channel 0 Error Interrupt Control Register
S0EIC_GLVL	SET	0
S0EIC_ILVL	SET	0
S0EIC_S0EIE	SET	0
S0EIC_S0EIR	SET	0

; Serial Channel 0 Receive Buffer Register (RO)
S0RBUF_S0RBUF	SET	0

; Serial Channel 0 Receive Interrupt Control Register
S0RIC_GLVL	SET	0
S0RIC_ILVL	SET	0
S0RIC_S0RIE	SET	0
S0RIC_S0RIR	SET	0

; Serial Channel 0 Transmit Buffer IC Register
S0TBIC_GLVL	SET	1
S0TBIC_ILVL	SET	4
S0TBIC_S0TBIE	SET	1
S0TBIC_S0TBIR	SET	0

; Serial Channel 0 Transmit Buffer Register (WO)
S0TBUF_S0TBUF	SET	0

; Serial Channel 0 Transmit Interrupt Control Register
S0TIC_GLVL	SET	0
S0TIC_ILVL	SET	0
S0TIC_S0TIE	SET	0
S0TIC_S0TIR	SET	0

; CPU System Stack Pointer Register
SP_SP	SET	1536

; SSC Baudrate Register
SSCBR_SSCBR	SET	99

; SSC Control Register
SSCCON_SSCAREN_BSY	SET	0
SSCCON_SSCBEN_BE	SET	0
SSCCON_SSCBM	SET	0
SSCCON_SSCEN	SET	0
SSCCON_SSCHB	SET	0
SSCCON_SSCMS	SET	0
SSCCON_SSCPEN_PE	SET	0
SSCCON_SSCPH	SET	0
SSCCON_SSCPO	SET	0
SSCCON_SSCREN_RE	SET	0
SSCCON_SSCTEN_TE	SET	0

; SSC Error Interrupt Control Register
SSCEIC_GLVL	SET	0
SSCEIC_ILVL	SET	0
SSCEIC_SSCEIE	SET	0
SSCEIC_SSCEIR	SET	0

; SSC Receive Buffer (RO)
SSCRB_SSCRB	SET	0

; SSC Receive Interrupt Control Register
SSCRIC_GLVL	SET	0
SSCRIC_ILVL	SET	0
SSCRIC_SSCRIE	SET	0
SSCRIC_SSCRIR	SET	0

; SSC Transmit Buffer (WO)
SSCTB_SSCTB	SET	0

; SSC Transmit Interrupt Control Register
SSCTIC_GLVL	SET	0
SSCTIC_ILVL	SET	0
SSCTIC_SSCTIE	SET	0
SSCTIC_SSCTIR	SET	0

; CPU Stack Overflow Pointer Register
STKOV_STKOV	SET	1280

; CPU Stack Underflow Pointer Register
STKUN_STKUN	SET	1536

; System Configuration Register 2/Clock Control
SYSCON2_CLKCON	SET	0
SYSCON2_CLKLOCK	SET	0
SYSCON2_CLKREL	SET	0
SYSCON2_PDCON	SET	0
SYSCON2_RCS	SET	0
SYSCON2_SCS	SET	0
SYSCON2_SYSRLS	SET	0

; System Configuration Register 3/Periph. Managem.
SYSCON3_ADCDIS	SET	0
SYSCON3_ASC0DIS	SET	0
SYSCON3_CAN1DIS	SET	0
SYSCON3_CC2DIS	SET	0
SYSCON3_CC6DIS	SET	0
SYSCON3_GPTDIS	SET	0
SYSCON3_PCDDIS	SET	0
SYSCON3_SSCDIS	SET	0

; CPU System Configuration Register
SYSCON_BDRSTEN	SET	0
SYSCON_BYTDIS	SET	0
SYSCON_CLKEN	SET	0
SYSCON_CSCFG	SET	0
SYSCON_OWDDIS	SET	1
SYSCON_ROMEN	SET	0
SYSCON_ROMS1	SET	1
SYSCON_SGTDIS	SET	0
SYSCON_STKSZ	SET	0
SYSCON_VISIBLE	SET	0
SYSCON_WRCFG	SET	1
SYSCON_XPEN	SET	1
SYSCON_XPER_SHARE	SET	0

; CAPCOM 6 Timer 12 Interrupt Control Register
T12IC_GLVL	SET	0
T12IC_ILVL	SET	0
T12IC_T12IE	SET	0
T12IC_T12IR	SET	0

; CAPCOM 6 Timer 12 Offset Register
T12OF_T12OF	SET	0

; CAPCOM 6 Timer 12 Period Register
T12P_T12P	SET	9999

; CAPCOM 6 Timer 13 Interrupt Control Register
T13IC_GLVL	SET	0
T13IC_ILVL	SET	0
T13IC_T13IE	SET	0
T13IC_T13IR	SET	0

; CAPCOM 6 Timer 13 Period Register
T13P_T13P	SET	999

; Timer 14 Reload Register
T14REL_T14REL	SET	46005

; Timer 14 Register
T14_T14	SET	0

; GPT1 Timer 2 Control Register
T2CON_T2I	SET	0
T2CON_T2M	SET	0
T2CON_T2R	SET	1
T2CON_T2UD	SET	0
T2CON_T2UDE	SET	0

; GPT1 Timer 2 Interrupt Control Register
T2IC_GLVL	SET	0
T2IC_ILVL	SET	4
T2IC_T2IE	SET	1
T2IC_T2IR	SET	0

; GPT1 Timer 2 Register
T2_T2	SET	0

; GPT1 Timer 3 Control Register
T3CON_T3I	SET	0
T3CON_T3M	SET	0
T3CON_T3OTL	SET	0
T3CON_T3R	SET	1
T3CON_T3UD	SET	1
T3CON_T3UDE	SET	0

; GPT1 Timer 3 Interrupt Control Register
T3IC_GLVL	SET	0
T3IC_ILVL	SET	5
T3IC_T3IE	SET	1
T3IC_T3IR	SET	0

; GPT1 Timer 3 Register
T3_T3	SET	2499

; GPT1 Timer 4 Control Register
T4CON_T4I	SET	7
T4CON_T4M	SET	4
T4CON_T4R	SET	0
T4CON_T4UD	SET	0
T4CON_T4UDE	SET	0

; GPT1 Timer 4 Interrupt Control Register
T4IC_GLVL	SET	0
T4IC_ILVL	SET	0
T4IC_T4IE	SET	0
T4IC_T4IR	SET	0

; GPT1 Timer 4 Register
T4_T4	SET	2499

; CAPCOM 2 Timer 7 and Timer 8 Control Register
T78CON_T7I	SET	0
T78CON_T7M	SET	0
T78CON_T7R	SET	0
T78CON_T8I	SET	0
T78CON_T8M	SET	0
T78CON_T8R	SET	1

; CAPCOM 2 Timer 7 Interrupt Control Register
T7IC_GLVL	SET	0
T7IC_ILVL	SET	0
T7IC_T7IE	SET	0
T7IC_T7IR	SET	0

; CAPCOM 2 Timer 7 Reload Register
T7REL_T7REL	SET	0

; CAPCOM 2 Timer 7 Register
T7_T7	SET	0

; CAPCOM 2 Timer 8 Interrupt Control Register
T8IC_GLVL	SET	0
T8IC_ILVL	SET	0
T8IC_T8IE	SET	0
T8IC_T8IR	SET	0

; CAPCOM 2 Timer 8 Reload Register
T8REL_T8REL	SET	0

; CAPCOM 2 Timer 8 Register
T8_T8	SET	0

; Trap Flag Register
TFR_ILLBUS	SET	0
TFR_ILLINA	SET	0
TFR_ILLOPA	SET	0
TFR_NMI	SET	0
TFR_PRTFLT	SET	0
TFR_STKOF	SET	0
TFR_STKUF	SET	0
TFR_UNDOPC	SET	0

; CAPCOM 6 Trap Enable Control Register
TRCON_TREN0	SET	0
TRCON_TREN1	SET	0
TRCON_TREN2	SET	0
TRCON_TREN3	SET	0
TRCON_TREN4	SET	0
TRCON_TREN5	SET	0
TRCON_TRF	SET	0
TRCON_TRPEN	SET	0

; Upper Arbitration Register 10
UAR10_ID13	SET	0
UAR10_ID14	SET	0
UAR10_ID15	SET	0
UAR10_ID16	SET	0
UAR10_ID17	SET	0
UAR10_ID18	SET	0
UAR10_ID19	SET	0
UAR10_ID20	SET	0
UAR10_ID21	SET	0
UAR10_ID22	SET	0
UAR10_ID23	SET	0
UAR10_ID24	SET	0
UAR10_ID25	SET	0
UAR10_ID26	SET	0
UAR10_ID27	SET	0
UAR10_ID28	SET	0

; Upper Arbitration Register 11
UAR11_ID13	SET	0
UAR11_ID14	SET	0
UAR11_ID15	SET	0
UAR11_ID16	SET	0
UAR11_ID17	SET	0
UAR11_ID18	SET	0
UAR11_ID19	SET	0
UAR11_ID20	SET	0
UAR11_ID21	SET	0
UAR11_ID22	SET	0
UAR11_ID23	SET	0
UAR11_ID24	SET	0
UAR11_ID25	SET	0
UAR11_ID26	SET	0
UAR11_ID27	SET	0
UAR11_ID28	SET	0

; Upper Arbitration Register 12
UAR12_ID13	SET	0
UAR12_ID14	SET	0
UAR12_ID15	SET	0
UAR12_ID16	SET	0
UAR12_ID17	SET	0
UAR12_ID18	SET	0
UAR12_ID19	SET	0
UAR12_ID20	SET	0
UAR12_ID21	SET	0
UAR12_ID22	SET	0
UAR12_ID23	SET	0
UAR12_ID24	SET	0
UAR12_ID25	SET	0
UAR12_ID26	SET	0
UAR12_ID27	SET	0
UAR12_ID28	SET	0

; Upper Arbitration Register 13
UAR13_ID13	SET	0
UAR13_ID14	SET	0
UAR13_ID15	SET	0
UAR13_ID16	SET	0
UAR13_ID17	SET	0
UAR13_ID18	SET	0
UAR13_ID19	SET	0
UAR13_ID20	SET	0
UAR13_ID21	SET	0
UAR13_ID22	SET	0
UAR13_ID23	SET	0
UAR13_ID24	SET	0
UAR13_ID25	SET	0
UAR13_ID26	SET	0
UAR13_ID27	SET	0
UAR13_ID28	SET	0

; Upper Arbitration Register 14
UAR14_ID13	SET	0
UAR14_ID14	SET	0
UAR14_ID15	SET	0
UAR14_ID16	SET	0
UAR14_ID17	SET	0
UAR14_ID18	SET	0
UAR14_ID19	SET	0
UAR14_ID20	SET	0
UAR14_ID21	SET	0
UAR14_ID22	SET	0
UAR14_ID23	SET	0
UAR14_ID24	SET	0
UAR14_ID25	SET	0
UAR14_ID26	SET	0
UAR14_ID27	SET	0
UAR14_ID28	SET	0

; Upper Arbitration Register 15
UAR15_ID13	SET	0
UAR15_ID14	SET	0
UAR15_ID15	SET	0
UAR15_ID16	SET	0
UAR15_ID17	SET	0
UAR15_ID18	SET	0
UAR15_ID19	SET	0
UAR15_ID20	SET	0
UAR15_ID21	SET	0
UAR15_ID22	SET	0
UAR15_ID23	SET	0
UAR15_ID24	SET	0
UAR15_ID25	SET	0
UAR15_ID26	SET	0
UAR15_ID27	SET	0
UAR15_ID28	SET	0

; Upper Arbitration Register 1
UAR1_ID13	SET	0
UAR1_ID14	SET	0
UAR1_ID15	SET	0
UAR1_ID16	SET	0
UAR1_ID17	SET	0
UAR1_ID18	SET	0
UAR1_ID19	SET	0
UAR1_ID20	SET	0
UAR1_ID21	SET	0
UAR1_ID22	SET	0
UAR1_ID23	SET	0
UAR1_ID24	SET	0
UAR1_ID25	SET	0
UAR1_ID26	SET	0
UAR1_ID27	SET	0
UAR1_ID28	SET	0

; Upper Arbitration Register 2
UAR2_ID13	SET	0
UAR2_ID14	SET	0
UAR2_ID15	SET	0
UAR2_ID16	SET	0
UAR2_ID17	SET	0
UAR2_ID18	SET	0
UAR2_ID19	SET	0
UAR2_ID20	SET	0
UAR2_ID21	SET	0
UAR2_ID22	SET	0
UAR2_ID23	SET	0
UAR2_ID24	SET	0
UAR2_ID25	SET	0
UAR2_ID26	SET	0
UAR2_ID27	SET	0
UAR2_ID28	SET	0

; Upper Arbitration Register 3
UAR3_ID13	SET	0
UAR3_ID14	SET	0
UAR3_ID15	SET	0
UAR3_ID16	SET	0
UAR3_ID17	SET	0
UAR3_ID18	SET	0
UAR3_ID19	SET	0
UAR3_ID20	SET	0
UAR3_ID21	SET	0
UAR3_ID22	SET	0
UAR3_ID23	SET	0
UAR3_ID24	SET	0
UAR3_ID25	SET	0
UAR3_ID26	SET	0
UAR3_ID27	SET	0
UAR3_ID28	SET	0

; Upper Arbitration Register 4
UAR4_ID13	SET	0
UAR4_ID14	SET	0
UAR4_ID15	SET	0
UAR4_ID16	SET	0
UAR4_ID17	SET	0
UAR4_ID18	SET	0
UAR4_ID19	SET	0
UAR4_ID20	SET	0
UAR4_ID21	SET	0
UAR4_ID22	SET	0
UAR4_ID23	SET	0
UAR4_ID24	SET	0
UAR4_ID25	SET	0
UAR4_ID26	SET	0
UAR4_ID27	SET	0
UAR4_ID28	SET	0

; Upper Arbitration Register 5
UAR5_ID13	SET	0
UAR5_ID14	SET	0
UAR5_ID15	SET	0
UAR5_ID16	SET	0
UAR5_ID17	SET	0
UAR5_ID18	SET	0
UAR5_ID19	SET	0
UAR5_ID20	SET	0
UAR5_ID21	SET	0
UAR5_ID22	SET	0
UAR5_ID23	SET	0
UAR5_ID24	SET	0
UAR5_ID25	SET	0
UAR5_ID26	SET	0
UAR5_ID27	SET	0
UAR5_ID28	SET	0

; Upper Arbitration Register 6
UAR6_ID13	SET	0
UAR6_ID14	SET	0
UAR6_ID15	SET	0
UAR6_ID16	SET	0
UAR6_ID17	SET	0
UAR6_ID18	SET	0
UAR6_ID19	SET	0
UAR6_ID20	SET	0
UAR6_ID21	SET	0
UAR6_ID22	SET	0
UAR6_ID23	SET	0
UAR6_ID24	SET	0
UAR6_ID25	SET	0
UAR6_ID26	SET	0
UAR6_ID27	SET	0
UAR6_ID28	SET	0

; Upper Arbitration Register 7
UAR7_ID13	SET	0
UAR7_ID14	SET	0
UAR7_ID15	SET	0
UAR7_ID16	SET	0
UAR7_ID17	SET	0
UAR7_ID18	SET	0
UAR7_ID19	SET	0
UAR7_ID20	SET	0
UAR7_ID21	SET	0
UAR7_ID22	SET	0
UAR7_ID23	SET	0
UAR7_ID24	SET	0
UAR7_ID25	SET	0
UAR7_ID26	SET	0
UAR7_ID27	SET	0
UAR7_ID28	SET	0

; Upper Arbitration Register 8
UAR8_ID13	SET	0
UAR8_ID14	SET	0
UAR8_ID15	SET	0
UAR8_ID16	SET	0
UAR8_ID17	SET	0
UAR8_ID18	SET	0
UAR8_ID19	SET	0
UAR8_ID20	SET	0
UAR8_ID21	SET	0
UAR8_ID22	SET	0
UAR8_ID23	SET	0
UAR8_ID24	SET	0
UAR8_ID25	SET	0
UAR8_ID26	SET	0
UAR8_ID27	SET	0
UAR8_ID28	SET	0

; Upper Arbitration Register 9
UAR9_ID13	SET	0
UAR9_ID14	SET	0
UAR9_ID15	SET	0
UAR9_ID16	SET	0
UAR9_ID17	SET	0
UAR9_ID18	SET	0
UAR9_ID19	SET	0
UAR9_ID20	SET	0
UAR9_ID21	SET	0
UAR9_ID22	SET	0
UAR9_ID23	SET	0
UAR9_ID24	SET	0
UAR9_ID25	SET	0
UAR9_ID26	SET	0
UAR9_ID27	SET	0
UAR9_ID28	SET	0

; Watchdog Timer Control Register
WDTCON_LHWR	SET	0
WDTCON_SHWR	SET	0
WDTCON_SWR	SET	0
WDTCON_WDTIN	SET	0
WDTCON_WDTR	SET	0
WDTCON_WDTREL	SET	0

; Watchdog Timer Register (RO)
WDT_WDT	SET	0

; X-Peripheral 0 Interrupt Control Register
XP0IC_GLVL	SET	0
XP0IC_ILVL	SET	0
XP0IC_XP0IE	SET	0
XP0IC_XP0IR	SET	0

; X-Peripheral 1 Interrupt Control Register
XP1IC_GLVL	SET	0
XP1IC_ILVL	SET	0
XP1IC_XP1IE	SET	0
XP1IC_XP1IR	SET	0

; X-Peripheral 2 Interrupt Control Register
XP2IC_GLVL	SET	0
XP2IC_ILVL	SET	0
XP2IC_XP2IE	SET	0
XP2IC_XP2IR	SET	0

; X-Peripheral 3 Interrupt Control Register
XP3IC_GLVL	SET	0
XP3IC_ILVL	SET	0
XP3IC_XP3IE	SET	0
XP3IC_XP3IR	SET	0

; Constant Value 0's Register
ZEROS_0	SET	0
ZEROS_1	SET	0
ZEROS_10	SET	0
ZEROS_11	SET	0
ZEROS_12	SET	0
ZEROS_13	SET	0
ZEROS_14	SET	0
ZEROS_15	SET	0
ZEROS_2	SET	0
ZEROS_3	SET	0
ZEROS_4	SET	0
ZEROS_5	SET	0
ZEROS_6	SET	0
ZEROS_7	SET	0
ZEROS_8	SET	0
ZEROS_9	SET	0

