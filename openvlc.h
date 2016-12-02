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

// See: http://beagleboard.org/static/images/cape-headers.png for pin layout
// GPIO related settings
// LED related GPIOs
#define GPIO_LED_ANODE 60
#define GPIO_LED_CATHODE 50
#define GPIO_BUFFER_CONTROL 51
#define GPIO_LED_OR_PD 2 // P9_22
#define GPIO_LED_HPL 49 // P9_23

#define GPIO_LED_ANODE_BIT (GPIO_LED_ANODE % 32)
#define GPIO_LED_CATHODE_BIT (GPIO_LED_CATHODE % 32)
#define GPIO_BUFFER_CONTROL_BIT (GPIO_BUFFER_CONTROL % 32)
#define GPIO_LED_OR_PD_BIT (GPIO_LED_OR_PD % 32)
#define GPIO_LED_HPL_BIT (GPIO_LED_HPL % 32)


// SPI related GPIOs
#define GPIO_SPI_CLC 45 // P8_11
#define GPIO_SPI_MISO 23 // P8_13
#define GPIO_SPI_MOSI 47 // P8_15
#define GPIO_SPI_CS 27 // P8_17

#define GPIO_SPI_CLC_BIT (GPIO_SPI_CLC % 32)
#define GPIO_SPI_MISO_BIT (GPIO_SPI_MISO % 32)
#define GPIO_SPI_MOSI_BIT (GPIO_SPI_MOSI % 32)
#define GPIO_SPI_CS_BIT (GPIO_SPI_CS % 32)


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
