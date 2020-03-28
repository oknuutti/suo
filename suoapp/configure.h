#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "libsuo/suo.h"

struct radio_conf {
	float samplerate, rx_centerfreq, tx_centerfreq; /* Hz */
	float rx_gain, tx_gain; /* dB */
	size_t rx_channel, tx_channel;
	bool tx_on;
	long long rx_tx_latency; /* ns */
	const char *rx_antenna, *tx_antenna;
};



int configure(struct suo *, int argc, char *argv[]);
int deinitialize(struct suo *);

#endif
