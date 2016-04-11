/***********************************************************************/
/*                                                                     */
/*  FILE        :intprg.c                                              */
/*  DATE        :Sat, Mar 26, 2016                                     */
/*  DESCRIPTION :Interrupt Program                                     */
/*  CPU TYPE    :RX62N                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.53).    */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
/************************************************************************
*
* Device     : RX/RX600/RX62N
*
* File Name  : intprg.c
*
* Abstract   : Interrupt Program.
*
* History    : 1.00  (2010-03-05)  [Hardware Manual Revision : 0.50]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2009 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
*
*********************************************************************/

#include <machine.h>
#include "vect.h"
#pragma section IntPRG

// Exception(Supervisor Instruction)
void Excep_SuperVisorInst(void){/* brk(); */}

// Exception(Undefined Instruction)
void Excep_UndefinedInst(void){/* brk(); */}

// Exception(Floating Point)
void Excep_FloatingPoint(void){/* brk(); */}

// NMI
void NonMaskableInterrupt(void){/* brk(); */}

// Dummy
void Dummy(void){/* brk(); */}

// BRK
void Excep_BRK(void){ wait(); }

// BUSERR
void Excep_BUSERR(void){ }

// FCU_FCUERR
void Excep_FCU_FCUERR(void){ }

// FCU_FRDYI
void Excep_FCU_FRDYI(void){ }

// ICU_SWINT
void Excep_ICU_SWINT(void){ }

// CMTU0_CMT0
void Excep_CMTU0_CMT0(void){ }

// CMTU0_CMT1
void Excep_CMTU0_CMT1(void){ }

// CMTU1_CMT2
void Excep_CMTU1_CMT2(void){ }

// CMTU1_CMT3
void Excep_CMTU1_CMT3(void){ }

// ETHER EINT
void Excep_ETHER_EINT(void){ }

// USB0 D0FIFO0
void Excep_USB0_D0FIFO0(void){ }

// USB0 D1FIFO0
void Excep_USB0_D1FIFO0(void){ }

// USB0 USBI0
void Excep_USB0_USBI0(void){ }

// USB1 D0FIFO1
void Excep_USB1_D0FIFO1(void){ }

// USB1 D1FIFO1
void Excep_USB1_D1FIFO1(void){ }

// USB1 USBI1
void Excep_USB1_USBI1(void){ }

// RSPI0 SPEI0
void Excep_RSPI0_SPEI0(void){ }

// RSPI0 SPRI0
void Excep_RSPI0_SPRI0(void){ }

// RSPI0 SPTI0
void Excep_RSPI0_SPTI0(void){ }

// RSPI0 SPII0
void Excep_RSPI0_SPII0(void){ }

// RSPI1 SPEI1
void Excep_RSPI1_SPEI1(void){ }

// RSPI1 SPRI1
void Excep_RSPI1_SPRI1(void){ }

// RSPI1 SPTI1
void Excep_RSPI1_SPTI1(void){ }

// RSPI1 SPII1
void Excep_RSPI1_SPII1(void){ }

// CAN0 ERS0
void Excep_CAN0_ERS0(void){ }

// CAN0 RXF0
void Excep_CAN0_RXF0(void){ }

// CAN0 TXF0
void Excep_CAN0_TXF0(void){ }

// CAN0 RXM0
void Excep_CAN0_RXM0(void){ }

// CAN0 TXM0
void Excep_CAN0_TXM0(void){ }

// RTC PRD
void Excep_RTC_PRD(void){ }

// RTC CUP
void Excep_RTC_CUP(void){ }

// IRQ0
void Excep_IRQ0(void){ }

// IRQ1
void Excep_IRQ1(void){ }

// IRQ2
void Excep_IRQ2(void){ }

// IRQ3
void Excep_IRQ3(void){ }

// IRQ4
void Excep_IRQ4(void){ }

// IRQ5
void Excep_IRQ5(void){ }

// IRQ6
void Excep_IRQ6(void){ }

// IRQ7
void Excep_IRQ7(void){ }

// IRQ8
void Excep_IRQ8(void){ }

// IRQ9
void Excep_IRQ9(void){ }

// IRQ10
void Excep_IRQ10(void){ }

// IRQ11
void Excep_IRQ11(void){ }

// IRQ12
void Excep_IRQ12(void){ }

// IRQ13
void Excep_IRQ13(void){ }

// IRQ14
void Excep_IRQ14(void){ }

// IRQ15
void Excep_IRQ15(void){ }

// USB RESUME USBR0
void Excep_USB_USBR0(void){ }

// USB RESUME USBR1
void Excep_USB_USBR1(void){ }

// RTC ALM
void Excep_RTC_ALM(void){ }

// WDT_WOVI
void Excep_WDT_WOVI(void){ }

// AD0_ADI0
void Excep_AD0_ADI0(void){ }

// AD1_ADI1
void Excep_AD1_ADI1(void){ }

// S12AD ADI12
void Excep_S12AD_ADI12(void){ }

// MTU0 TGIA0
void Excep_MTU0_TGIA0(void){ }

// MTU0 TGIB0
void Excep_MTU0_TGIB0(void){ }

// MTU0 TGIC0
void Excep_MTU0_TGIC0(void){ }

// MTU0 TGID0
void Excep_MTU0_TGID0(void){ }

// MTU0 TCIV0
void Excep_MTU0_TCIV0(void){ }

// MTU0 TGIE0
void Excep_MTU0_TGIE0(void){ }

// MTU0 TGIF0
void Excep_MTU0_TGIF0(void){ }

// MTU1 TGIA1
void Excep_MTU1_TGIA1(void){ }

// MTU1 TGIB1
void Excep_MTU1_TGIB1(void){ }

// MTU1 TCIV1
void Excep_MTU1_TCIV1(void){ }

// MTU1 TCIU1
void Excep_MTU1_TCIU1(void){ }

// MTU2 TGIA2
void Excep_MTU2_TGIA2(void){ }

// MTU2 TGIB2
void Excep_MTU2_TGIB2(void){ }

// MTU2 TCIV2
void Excep_MTU2_TCIV2(void){ }

// MTU2 TCIU2
void Excep_MTU2_TCIU2(void){ }

// MTU3 TGIA3
void Excep_MTU3_TGIA3(void){ }

// MTU3 TGIB3
void Excep_MTU3_TGIB3(void){ }

// MTU3 TGIC3
void Excep_MTU3_TGIC3(void){ }

// MTU3 TGID3
void Excep_MTU3_TGID3(void){ }

// MTU3 TCIV3
void Excep_MTU3_TCIV3(void){ }

// MTU4 TGIA4
void Excep_MTU4_TGIA4(void){ }

// MTU4 TGIB4
void Excep_MTU4_TGIB4(void){ }

// MTU4 TGIC4
void Excep_MTU4_TGIC4(void){ }

// MTU4 TGID4
void Excep_MTU4_TGID4(void){ }

// MTU4 TCIV4
void Excep_MTU4_TCIV4(void){ }

// MTU5 TCIU5
void Excep_MTU5_TCIU5(void){ }

// MTU5 TCIV5
void Excep_MTU5_TCIV5(void){ }

// MTU5 TCIW5
void Excep_MTU5_TCIW5(void){ }

// MTU6 TGIA6
void Excep_MTU6_TGIA6(void){ }

// MTU6 TGIB6
void Excep_MTU6_TGIB6(void){ }

// MTU6 TGIC6
void Excep_MTU6_TGIC6(void){ }

// MTU6 TGID6
void Excep_MTU6_TGID6(void){ }

// MTU6 TCIV6
void Excep_MTU6_TCIV6(void){ }

// MTU6 TGIE6
void Excep_MTU6_TGIE6(void){ }

// MTU6 TGIF6
void Excep_MTU6_TGIF6(void){ }

// MTU7 TGIA7
void Excep_MTU7_TGIA7(void){ }

// MTU7 TGIB7
void Excep_MTU7_TGIB7(void){ }

// MTU7 TCIV7
void Excep_MTU7_TCIV7(void){ }

// MTU7 TCIU7
void Excep_MTU7_TCIU7(void){ }

// MTU8 TGIA8
void Excep_MTU8_TGIA8(void){ }

// MTU8 TGIB8
void Excep_MTU8_TGIB8(void){ }

// MTU8 TCIV8
void Excep_MTU8_TCIV8(void){ }

// MTU8 TCIU8
void Excep_MTU8_TCIU8(void){ }

// MTU9 TGIA9
void Excep_MTU9_TGIA9(void){ }

// MTU9 TGIB9
void Excep_MTU9_TGIB9(void){ }

// MTU9 TGIC9
void Excep_MTU9_TGIC9(void){ }

// MTU9 TGID9
void Excep_MTU9_TGID9(void){ }

// MTU9 TCIV9
void Excep_MTU9_TCIV9(void){ }

// MTU10 TGIA10
void Excep_MTU10_TGIA10(void){ }

// MTU10 TGIB10
void Excep_MTU10_TGIB10(void){ }

// MTU10 TGIC10
void Excep_MTU10_TGIC10(void){ }

// MTU10 TGID10
void Excep_MTU10_TGID10(void){ }

// MTU10 TCIV10
void Excep_MTU10_TCIV10(void){ }

// MTU11 TCIU11
void Excep_MTU11_TCIU11(void){ }

// MTU11 TCIV11
void Excep_MTU11_TCIV11(void){ }

// MTU11 TCIW11
void Excep_MTU11_TCIW11(void){ }

// POE OEI1
void Excep_POE_OEI1(void){ }

// POE OEI1
void Excep_POE_OEI2(void){ }

// POE OEI1
void Excep_POE_OEI3(void){ }

// POE OEI1
void Excep_POE_OEI4(void){ }

// TMR0_CMI0A
void Excep_TMR0_CMI0A(void){ }

// TMR0_CMI0B
void Excep_TMR0_CMI0B(void){ }

// TMR0_OV0I
void Excep_TMR0_OV0I(void){ }

// TMR1_CMI1A
void Excep_TMR1_CMI1A(void){ }

// TMR1_CMI1B
void Excep_TMR1_CMI1B(void){ }

// TMR1_OV1I
void Excep_TMR1_OV1I(void){ }

// TMR2_CMI2A
void Excep_TMR2_CMI2A(void){ }

// TMR2_CMI2B
void Excep_TMR2_CMI2B(void){ }

// TMR2_OV2I
void Excep_TMR2_OV2I(void){ }

// TMR3_CMI3A
void Excep_TMR3_CMI3A(void){ }

// TMR3_CMI3B
void Excep_TMR3_CMI3B(void){ }

// TMR3_OV3I
void Excep_TMR3_OV3I(void){ }

// DMACA DMAC0
void Excep_DMACA_DMAC0(void){ }

// DMAC DMAC1
void Excep_DMACA_DMAC1(void){ }

// DMAC DMAC2
void Excep_DMACA_DMAC2(void){ }

// DMAC DMAC3
void Excep_DMACA_DMAC3(void){ }

// EXDMAC DMAC0
void Excep_EXDMAC_DMAC0(void){ }

// EXDMAC DMAC1
void Excep_EXDMAC_DMAC1(void){ }

// SCI0_ERI0
void Excep_SCI0_ERI0(void){ }

// SCI0_RXI0
void Excep_SCI0_RXI0(void){ }

// SCI0_TXI0
void Excep_SCI0_TXI0(void){ }

// SCI0_TEI0
void Excep_SCI0_TEI0(void){ }

// SCI1_ERI1
void Excep_SCI1_ERI1(void){ }

// SCI1_RXI1
void Excep_SCI1_RXI1(void){ }

// SCI1_TXI1
void Excep_SCI1_TXI1(void){ }

// SCI1_TEI1
void Excep_SCI1_TEI1(void){ }

// SCI2_ERI2
void Excep_SCI2_ERI2(void){ }

// SCI2_RXI2
void Excep_SCI2_RXI2(void){ }

// SCI2_TXI2
void Excep_SCI2_TXI2(void){ }

// SCI2_TEI2
void Excep_SCI2_TEI2(void){ }

// SCI3_ERI3
void Excep_SCI3_ERI3(void){ }

// SCI3_RXI3
void Excep_SCI3_RXI3(void){ }

// SCI3_TXI3
void Excep_SCI3_TXI3(void){ }

// SCI3_TEI3
void Excep_SCI3_TEI3(void){ }

// SCI5_ERI5
void Excep_SCI5_ERI5(void){ }

// SCI5_RXI5
void Excep_SCI5_RXI5(void){ }

// SCI5_TXI5
void Excep_SCI5_TXI5(void){ }

// SCI5_TEI5
void Excep_SCI5_TEI5(void){ }

// SCI6_ERI6
void Excep_SCI6_ERI6(void){ }

// SCI6_RXI6
void Excep_SCI6_RXI6(void){ }

// SCI6_TXI6
void Excep_SCI6_TXI6(void){ }

// SCI6_TEI6
void Excep_SCI6_TEI6(void){ }

// RIIC0_EEI0
void Excep_RIIC0_EEI0(void){ }

// RIIC0_RXI0
void Excep_RIIC0_RXI0(void){ }

// RIIC0_TXI0
void Excep_RIIC0_TXI0(void){ }

// RIIC0_TEI0
void Excep_RIIC0_TEI0(void){ }

// RIIC1_EEI1
void Excep_RIIC1_EEI1(void){ }

// RIIC1_RXI1
void Excep_RIIC1_RXI1(void){ }

// RIIC1_TXI1
void Excep_RIIC1_TXI1(void){ }

// RIIC1_TEI1
void Excep_RIIC1_TEI1(void){ }


