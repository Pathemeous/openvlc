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

#ifndef BBB_GPIO_H
#define BBB_GPIO_H

// from: https://groups.google.com/d/msg/beagleboard/_d4giJ0GO3E/GFb5bwuulmEJ
#define GPIO0_ADDR 0x44e07000
#define GPIO1_ADDR 0x4804c000
#define GPIO2_ADDR 0x481ac000
#define GPIO3_ADDR 0x481ae000
#define READ_OFFSET 0x138
#define SET_OFFSET 0x194
#define CLEAR_OFFSET 0x190

#endif	/* BBB_GPIO_H */
