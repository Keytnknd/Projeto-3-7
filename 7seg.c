/* ***************************************************************** */
/* File name:        7seg.c                                          */
/* File description: file dedicated to implement the functioning of  */
/*                   the 7 segments device                           */
/* Author name:      Daniel Kaneda                                   */
/* Creation date:    30março2017                                     */
/* Revision date:                                                    */
/* ***************************************************************** */

#include "es670_peripheral_board.h"
#include "util.h"


/* ****************************************************/
/* Method name:        init_7seg_dev                  */
/* Method description: function to initiate the       */
/*                     clock of the 7 segments device */
/*                     and to configure the mux field */
/*                     of the PCR register for the    */
/*                     correct alternative, gerenec   */
/*                     pin input output               */
/*                                                    */          
/* Input params:      n/a                             */
/*                                                    */
/*                                                    */
/*                                                    */
/* Outpu params:      n/a                            */
/* ****************************************************/
void init_7seg_dev( void ) {

    SIM_SCGC5 |= SIM_SCGC5_PORTC( CGC_CLOCK_ENABLED ); //RELEASE PORT C CLOCK

    PORTC_PCR0 |= PORT_PCR_MUX( 0x01U );            //SET ALL PINS FOR 7 SEG AS GPIO'S
    PORTC_PCR1 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR2 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR3 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR4 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR5 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR6 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR7 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR10 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR11 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR12 |= PORT_PCR_MUX( 0x01U );
    PORTC_PCR13 |= PORT_PCR_MUX( 0x01U );

    GPIOC_PDDR |= GPIO_PDDR_PDD( 0x3CFFu );

}

/* ************************************************ */
/* Method name:        set_7seg_dev                 */
/* Method description: function to configure the    */
/*                     segments and show the        */
/*                     respective character on the  */
/*                     7 segments device            */
/*                                                  */
/*                                                  */
/* Input params:      char_to_show = char to show   */
/*                    on display                    */
/*                                                  */
/*                                                  */
/* Outpu params:       n/a                          */
/* ************************************************ */
void set_7seg_dev( int char_to_show) {

    switch( char_to_show ) {
        case 0:                                     //SHOW CHARACTER 'E'
            GPIOC_PSOR = GPIO_PSOR_PTSO( 0x79u );
            break;
        case 1:                                     //SHOW CHARACTER '6'
            GPIOC_PSOR = GPIO_PSOR_PTSO( 0x7Du );
            break;
        case 2:                                     //SHOW CHARACTER 'S'
            GPIOC_PSOR = GPIO_PSOR_PTSO( 0x6Du );
            break;
        case 3:                                     //SHOW CHARACTER '7'
            GPIOC_PSOR = GPIO_PSOR_PTSO( 0x07u );
            break;
        case 4:
        	GPIOC_PSOR = GPIO_PSOR_PTSO( 0x77u );
        	break;// A
    }
}

/* ************************************************ */
/* Method name:        which_7seg_dev               */
/* Method description: choose the 7 seg display     */
/* Input params:       position = which display     */
/* Outpu params:       n/a                          */
/* ************************************************ */
void which_7seg_dev( int position ) {
    switch( position ) {
        case 0:
            GPIOC_PSOR |= GPIO_PSOR_PTSO( 0x2000u );
            break;
        case 1:
            GPIOC_PSOR |= GPIO_PSOR_PTSO( 0x1000u );
            break;
        case 2:
            GPIOC_PSOR |= GPIO_PSOR_PTSO( 0x800u );
            break;
        case 3:
            GPIOC_PSOR |= GPIO_PSOR_PTSO( 0x400u );
            break;

    }
}

/* ************************************************ */
/* Method name:        clear_7seg_dev               */
/* Method description: set the 7 segment device off */
/* Input params:       n/a                          */
/* Outpu params:       n/a                          */
/* ************************************************ */
void clear_7seg_dev(  ) {

	GPIOC_PCOR |= GPIO_PCOR_PTCO( 0xFFFFu );
}
