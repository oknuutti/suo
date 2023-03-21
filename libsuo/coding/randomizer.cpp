
#include "coding/randomizer.hpp"

/*
 * Pseudo random sequence generated using the polynomial h(x) = x^8 + x^7 + x^5 + x^3 + 1.
 * Ref: CCSDS 131.0-B-4, 10.4.1
 */
const uint8_t suo::ccsds_tm_randomizer[suo::ccsds_randomizer_len] = {
	0xff, 0x48, 0x0e, 0xc0, 0x9a, 0x0d, 0x70, 0xbc,
	0x8e, 0x2c, 0x93, 0xad, 0xa7, 0xb7, 0x46, 0xce,
	0x5a, 0x97, 0x7d, 0xcc, 0x32, 0xa2, 0xbf, 0x3e,
	0x0a, 0x10, 0xf1, 0x88, 0x94, 0xcd, 0xea, 0xb1,
	0xfe, 0x90, 0x1d, 0x81, 0x34, 0x1a, 0xe1, 0x79,
	0x1c, 0x59, 0x27, 0x5b, 0x4f, 0x6e, 0x8d, 0x9c,
	0xb5, 0x2e, 0xfb, 0x98, 0x65, 0x45, 0x7e, 0x7c,
	0x14, 0x21, 0xe3, 0x11, 0x29, 0x9b, 0xd5, 0x63,
	0xfd, 0x20, 0x3b, 0x02, 0x68, 0x35, 0xc2, 0xf2,
	0x38, 0xb2, 0x4e, 0xb6, 0x9e, 0xdd, 0x1b, 0x39,
	0x6a, 0x5d, 0xf7, 0x30, 0xca, 0x8a, 0xfc, 0xf8,
	0x28, 0x43, 0xc6, 0x22, 0x53, 0x37, 0xaa, 0xc7,
	0xfa, 0x40, 0x76, 0x04, 0xd0, 0x6b, 0x85, 0xe4,
	0x71, 0x64, 0x9d, 0x6d, 0x3d, 0xba, 0x36, 0x72,
	0xd4, 0xbb, 0xee, 0x61, 0x95, 0x15, 0xf9, 0xf0,
	0x50, 0x87, 0x8c, 0x44, 0xa6, 0x6f, 0x55, 0x8f,
	0xf4, 0x80, 0xec, 0x09, 0xa0, 0xd7, 0x0b, 0xc8,
	0xe2, 0xc9, 0x3a, 0xda, 0x7b, 0x74, 0x6c, 0xe5,
	0xa9, 0x77, 0xdc, 0xc3, 0x2a, 0x2b, 0xf3, 0xe0,
	0xa1, 0x0f, 0x18, 0x89, 0x4c, 0xde, 0xab, 0x1f,
	0xe9, 0x01, 0xd8, 0x13, 0x41, 0xae, 0x17, 0x91,
	0xc5, 0x92, 0x75, 0xb4, 0xf6, 0xe8, 0xd9, 0xcb,
	0x52, 0xef, 0xb9, 0x86, 0x54, 0x57, 0xe7, 0xc1,
	0x42, 0x1e, 0x31, 0x12, 0x99, 0xbd, 0x56, 0x3f,
	0xd2, 0x03, 0xb0, 0x26, 0x83, 0x5c, 0x2f, 0x23,
	0x8b, 0x24, 0xeb, 0x69, 0xed, 0xd1, 0xb3, 0x96,
	0xa5, 0xdf, 0x73, 0x0c, 0xa8, 0xaf, 0xcf, 0x82,
	0x84, 0x3c, 0x62, 0x25, 0x33, 0x7a, 0xac, 0x7f,
	0xa4, 0x07, 0x60, 0x4d, 0x06, 0xb8, 0x5e, 0x47,
	0x16, 0x49, 0xd6, 0xd3, 0xdb, 0xa3, 0x67, 0x2d,
	0x4b, 0xbe, 0xe6, 0x19, 0x51, 0x5f, 0x9f, 0x05,
	0x08, 0x78, 0xc4, 0x4a, 0x66, 0xf5, 0x58, 0xff
};

/*
 * Pseudo random sequence generated using the polynom PN9  h(x) = x^9 + x^5 + x^0
 * Ref: Data Whitening and Random TX Mode https://www.ti.com/lit/an/swra322/swra322.pdf
 */
const uint8_t suo::pn9_randomizer[pn9_randomizer_len] = {
	0xff, 0xe1, 0x1d, 0x9a, 0xed, 0x85, 0x33, 0x24,
	0xea, 0x7a, 0xd2, 0x39, 0x70, 0x97, 0x57, 0x0a,
	0x54, 0x7d, 0x2d, 0xd8, 0x6d, 0x0d, 0xba, 0x8f,
	0x67, 0x59, 0xc7, 0xa2, 0xbf, 0x34, 0xca, 0x18,
	0x30, 0x53, 0x93, 0xdf, 0x92, 0xec, 0xa7, 0x15,
	0x8a, 0xdc, 0xf4, 0x86, 0x55, 0x4e, 0x18, 0x21,
	0x40, 0xc4, 0xc4, 0xd5, 0xc6, 0x91, 0x8a, 0xcd,
	0xe7, 0xd1, 0x4e, 0x09, 0x32, 0x17, 0xdf, 0x83,
	0xff, 0xf0, 0x0e, 0xcd, 0xf6, 0xc2, 0x19, 0x12,
	0x75, 0x3d, 0xe9, 0x1c, 0xb8, 0xcb, 0x2b, 0x05,
	0xaa, 0xbe, 0x16, 0xec, 0xb6, 0x06, 0xdd, 0xc7,
	0xb3, 0xac, 0x63, 0xd1, 0x5f, 0x1a, 0x65, 0x0c,
	0x98, 0xa9, 0xc9, 0x6f, 0x49, 0xf6, 0xd3, 0x0a,
	0x45, 0x6e, 0x7a, 0xc3, 0x2a, 0x27, 0x8c, 0x10,
	0x20, 0x62, 0xe2, 0x6a, 0xe3, 0x48, 0xc5, 0xe6,
	0xf3, 0x68, 0xa7, 0x04, 0x99, 0x8b, 0xef, 0xc1,
	0x7f, 0x78, 0x87, 0x66, 0x7b, 0xe1, 0x0c, 0x89,
	0xba, 0x9e, 0x74, 0x0e, 0xdc, 0xe5, 0x95, 0x02,
	0x55, 0x5f, 0x0b, 0x76, 0x5b, 0x83, 0xee, 0xe3,
	0x59, 0xd6, 0xb1, 0xe8, 0x2f, 0x8d, 0x32, 0x06,
	0xcc, 0xd4, 0xe4, 0xb7, 0x24, 0xfb, 0x69, 0x85,
	0x22, 0x37, 0xbd, 0x61, 0x95, 0x13, 0x46, 0x08,
	0x10, 0x31, 0x71, 0xb5, 0x71, 0xa4, 0x62, 0xf3,
	0x79, 0xb4, 0x53, 0x82, 0xcc, 0xc5, 0xf7, 0xe0,
	0x3f, 0xbc, 0x43, 0xb3, 0xbd, 0x70, 0x86, 0x44,
	0x5d, 0x4f, 0x3a, 0x07, 0xee, 0xf2, 0x4a, 0x81,
	0xaa, 0xaf, 0x05, 0xbb, 0xad, 0x41, 0xf7, 0xf1,
	0x2c, 0xeb, 0x58, 0xf4, 0x97, 0x46, 0x19, 0x03,
	0x66, 0x6a, 0xf2, 0x5b, 0x92, 0xfd, 0xb4, 0x42,
	0x91, 0x9b, 0xde, 0xb0, 0xca, 0x09, 0x23, 0x04,
	0x88, 0x98, 0xb8, 0xda, 0x38, 0x52, 0xb1, 0xf9,
	0x3c, 0xda, 0x29, 0x41, 0xe6, 0xe2, 0x7b, 0xf0,
	0x1f, 0xde, 0xa1, 0xd9, 0x5e, 0x38, 0x43, 0xa2,
	0xae, 0x27, 0x9d, 0x03, 0x77, 0x79, 0xa5, 0x40,
	0xd5, 0xd7, 0x82, 0xdd, 0xd6, 0xa0, 0xfb, 0x78,
	0x96, 0x75, 0x2c, 0xfa, 0x4b, 0xa3, 0x8c, 0x01,
	0x33, 0x35, 0xf9, 0x2d, 0xc9, 0x7e, 0x5a, 0xa1,
	0xc8, 0x4d, 0x6f, 0x58, 0xe5, 0x84, 0x11, 0x02,
	0x44, 0x4c, 0x5c, 0x6d, 0x1c, 0xa9, 0xd8, 0x7c,
	0x1e, 0xed, 0x94, 0x20, 0x73, 0xf1, 0x3d, 0xf8,
	0x0f, 0xef, 0xd0, 0x6c, 0x2f, 0x9c, 0x21, 0x51,
	0xd7, 0x93, 0xce, 0x81, 0xbb, 0xbc, 0x52, 0xa0,
	0xea, 0x6b, 0xc1, 0x6e, 0x6b, 0xd0, 0x7d, 0x3c,
	0xcb, 0x3a, 0x16, 0xfd, 0xa5, 0x51, 0xc6, 0x80,
	0x99, 0x9a, 0xfc, 0x96, 0x64, 0x3f, 0xad, 0x50,
	0xe4, 0xa6, 0x37, 0xac, 0x72, 0xc2, 0x08, 0x01,
	0x22, 0x26, 0xae, 0x36, 0x8e, 0x54, 0x6c, 0x3e,
	0x8f, 0x76, 0x4a, 0x90, 0xb9, 0xf8, 0x1e, 0xfc,
	0x87, 0x77, 0x68, 0xb6, 0x17, 0xce, 0x90, 0xa8,
	0xeb, 0x49, 0xe7, 0xc0, 0x5d, 0x5e, 0x29, 0x50,
	0xf5, 0xb5, 0x60, 0xb7, 0x35, 0xe8, 0x3e, 0x9e,
	0x65, 0x1d, 0x8b, 0xfe, 0xd2, 0x28, 0x63, 0xc0,
	0x4c, 0x4d, 0x7e, 0x4b, 0xb2, 0x9f, 0x56, 0x28,
	0x72, 0xd3, 0x1b, 0x56, 0x39, 0x61, 0x84, 0x00,
	0x11, 0x13, 0x57, 0x1b, 0x47, 0x2a, 0x36, 0x9f,
	0x47, 0x3b, 0x25, 0xc8, 0x5c, 0x7c, 0x0f, 0xfe,
	0xc3, 0x3b, 0x34, 0xdb, 0x0b, 0x67, 0x48, 0xd4,
	0xf5, 0xa4, 0x73, 0xe0, 0x2e, 0xaf, 0x14, 0xa8,
	0xfa, 0x5a, 0xb0, 0xdb, 0x1a, 0x74, 0x1f, 0xcf,
	0xb2, 0x8e, 0x45, 0x7f, 0x69, 0x94, 0x31, 0x60,
	0xa6, 0x26, 0xbf, 0x25, 0xd9, 0x4f, 0x2b, 0x14,
	0xb9, 0xe9, 0x0d, 0xab, 0x9c, 0x30, 0x42, 0x80,
	0x88, 0x89, 0xab, 0x8d, 0x23, 0x15, 0x9b, 0xcf,
	0xa3, 0x9d, 0x12, 0x64, 0x2e, 0xbe, 0x07,
};

