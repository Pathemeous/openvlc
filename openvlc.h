/*
 Copyright (c) 2014, IMDEA NETWORKS Institute

 This file is part of the OpenVLC's source codes.

 OpenVLC's source codes are free: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 OpenVLC's source codes are distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with the source codes of OpenVLC.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _LINUX_IF_VLC_H
#define _LINUX_IF_VLC_H

#include <linux/types.h>

/*  PIN  VALUE
 * --------------------------------------------------------------------
 *  P9_11 30 | P9_12 60 | P9_14 50 | P9_16 51 | P9_41A 20 | P9_42A 7
 *  P8_11 45 | P8_13 23 | P8_15 47 | P8_16 46
 * --------------------------------------------------------------------
 */
#define GPIO_LED_ANODE 60
#define GPIO_LED_CATHODE 50
#define GPIO_BUFFER_CONTROL 51

#define GPIO_LED_OR_PD 2 // P9_22  Choose between PD and LED
#define GPIO_H_POWER_LED 49 // P9_23  Output of high power LED

// SPI related GPIO settings
#define SPI_CLC 45 // 32+13 P8_11
#define SPI_MISO 23 // 0+23 P8_13
#define SPI_MOSI 47 // 32+15 P8_15
#define SPI_CS 27 // 0+27 P8_17

#define BIT_CLC (45-32) // 32+13 P8_11
#define BIT_MISO (23) // 0+23 P8_13
#define BIT_MOSI (47-32) // 32+15 P8_15
#define BIT_CS (27) // 0+27 P8_17

#define BIT_LED_ANODE (60-32)
#define BIT_LED_CATHODE (50-32)
#define BIT_BUFFER_CONTROL (51-32)
#define BIT_LED_OR_PD 2 // Choose between PD or LED
#define BIT_H_POWER_LED (49-32) // For high power LED
/* Frame format
 * ----------------------------------------------------------------
 * FIELD | Preamble | SFD | Length | Dst | Src | Protocol | Payload | CRC |
 * BYTE  | 3        | 1   | 2      | 2   | 2   | 2        | 0...255 | 2   |
 * ----------------------------------------------------------------
 */
#define PREAMBLE_LEN 3
#define SFD_LEN 1
#define OCTET_LEN 2
#define MAC_ADDR_LEN 2
#define PROTOCOL_LEN 2
#define MAC_HDR_LEN (OCTET_LEN+2*MAC_ADDR_LEN+PROTOCOL_LEN)
#define VLC_HLEN (2*MAC_ADDR_LEN+PROTOCOL_LEN)
#define ECC_LEN 16  //
#define FRAME_LEN_WO_PAYLOAD \
    (PREAMBLE_LEN+SFD_LEN+MAC_HDR_LEN+ECC_LEN)

#define PREAMBLE_LEN_IN_BITS (8*PREAMBLE_LEN)

#define VLC_P_DEFAULT     0x0001          /* Dummy type for vlc frames  */

// This is an vlc frame header.
struct vlchdr {
	unsigned char	h_dest[MAC_ADDR_LEN];	/* destination eth addr	*/
	unsigned char	h_source[MAC_ADDR_LEN];	/* source ether addr	*/
	__be16		h_proto;		/* packet type ID field	*/
} __attribute__((packed));


#endif /* _LINUX_IF_VLC_H */
