/*
 * 7seg.h
 *
 *  Created on: 31/03/2017
 *      Author: Daniel Kaneda
 */

#ifndef SOURCES_7SEG_H_
#define SOURCES_7SEG_H_


void init_7seg_dev( void );

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
void set_7seg_dev( int char_to_show);

/* ************************************************ */
/* Method name:        which_7seg_dev               */
/* Method description: choose a display             */
/* Input params:       position = which 7seg display*/
/*                     to show                      */
/* Outpu params:       n/a                          */
/* ************************************************ */
void which_7seg_dev( int position );

/* ************************************************ */
/* Method name:        clear_7seg_dev               */
/* Method description: set the 7 segment device off */
/* Input params:       n/a                          */
/* Outpu params:       n/a                          */
/* ************************************************ */
void clear_7seg_dev( );


#endif /* SOURCES_7SEG_H_ */
