/***********************************************************************************************************************
 * Copyright [2015-2021] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 * 
 * This file is part of Renesas SynergyTM Software Package (SSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas SSP license agreement. Unless otherwise agreed in an SSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hal_entry.c
* Description  : This is a very simple example application that blinks all LEDs on a board.
***********************************************************************************************************************/
#include "stdio.h"
#include "hal_data.h"
extern void initialise_monitor_handles(void);



/*******************************************************************************************************************//**
 * @brief  Blinky example application
 *
 * Blinks all leds at a rate of 1 second using the software delay function provided by the BSP.
 * Only references two other modules including the BSP, IOPORT.
 *
 **********************************************************************************************************************/
void hal_entry(void) {

	/* Define the units to be used with the software delay function */
	const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;
	/* Set the blink frequency (must be <= bsp_delay_units */
    const uint32_t freq_in_hz = 2;
	/* Calculate the delay in terms of bsp_delay_units */
    const uint32_t delay = bsp_delay_units/freq_in_hz;

    /* definindo em qual variavel ta a porta, onde vale-se lembrar
     * (endereo na placa_PIN_ porta) */

#define ledverde IOPORT_PORT_02_PIN_02
#define ledamarelo  IOPORT_PORT_03_PIN_03
#define ledvermelho IOPORT_PORT_01_PIN_12

    initialise_monitor_handles();

    while (1)
               {

        /*Defenindo se a porta é entrada e saida, onde  */
    g_ioport.p_api->pinCfg(ledverde, IOPORT_CFG_IRQ_ENABLE | IOPORT_CFG_PORT_DIRECTION_OUTPUT);
    g_ioport.p_api->pinCfg(ledamarelo, IOPORT_CFG_IRQ_ENABLE | IOPORT_CFG_PORT_DIRECTION_OUTPUT);
    g_ioport.p_api->pinCfg(ledvermelho, IOPORT_CFG_IRQ_ENABLE | IOPORT_CFG_PORT_DIRECTION_OUTPUT);


    printf("TO AQUI.",0x0a);

            g_ioport.p_api->pinWrite(ledverde, IOPORT_LEVEL_HIGH);
            g_ioport.p_api->pinWrite(ledamarelo, IOPORT_LEVEL_LOW);
            g_ioport.p_api->pinWrite(ledvermelho, IOPORT_LEVEL_LOW);

            /* Delay */
            R_BSP_SoftwareDelay(delay, bsp_delay_units);

            g_ioport.p_api->pinWrite(ledverde, IOPORT_LEVEL_LOW);
            g_ioport.p_api->pinWrite(ledamarelo, IOPORT_LEVEL_HIGH);
            g_ioport.p_api->pinWrite(ledvermelho, IOPORT_LEVEL_LOW);
            /* Delay */
            R_BSP_SoftwareDelay(delay, bsp_delay_units);

            g_ioport.p_api->pinWrite(ledverde, IOPORT_LEVEL_LOW);
            g_ioport.p_api->pinWrite(ledamarelo, IOPORT_LEVEL_LOW);
            g_ioport.p_api->pinWrite(ledvermelho, IOPORT_LEVEL_HIGH);
        /* Delay */
        R_BSP_SoftwareDelay(delay, bsp_delay_units);
               }
}
