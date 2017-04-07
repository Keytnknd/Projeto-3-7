/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_device_registers.h"
#include "es670_peripheral_board.h"
#include "buzzer_hal.h"
#include "ledswi_hal.h"
#include "mcg_hal.h"
#include "util.h"
#include "7seg.h"

static int i = 0;

int main(void) {

	/* Write your code here */
	switch_status_type_e sts;

	/* This for loop should be replaced. By default this loop allows a single stepping. */
	for (;;) {
		ledswi_initLedSwitch(1,3);
		sts = ledswi_getSwitchStatus(3);
		if (sts == SWITCH_ON) {
		    ledswi_setLed(4);
		}
		else {
			ledswi_clearLed(4);
		}


		mcg_clockInit();
		init_7seg_dev();

		set_7seg_dev(0);
		which_7seg_dev(0);
		util_genDelay1ms();
		clear_7seg_dev();


		set_7seg_dev(2);
		which_7seg_dev(1);
		util_genDelay1ms();
		clear_7seg_dev();

		set_7seg_dev(4);
		which_7seg_dev(2);
		util_genDelay1ms();
		clear_7seg_dev();

		set_7seg_dev(3);
		which_7seg_dev(3);
		util_genDelay1ms();
		clear_7seg_dev();

		i++;
	}
	/* Never leave main */
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
