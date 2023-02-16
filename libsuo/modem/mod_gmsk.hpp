#pragma once

#include <memory>
#include "suo.hpp"
#include <liquid/liquid.h>


namespace suo {

/*
 * GMSK modulator
 */
class GMSKModulator : public Block
{	
public:

	struct Config
	{
		Config();

		/*
		 * Output sample rate as samples per second
		 */
		float sample_rate;

		/* 
		 * Symbol rate as symbols per second
		 */
		float symbol_rate;

		/*
		 * Center frequency (Hz)
		 */
		float center_frequency;

		/* 
		 * Frequency offset from the center frequency (Hz)
		 */
		float frequency_offset;

		/*
	 	 * Gaussian filter bandwidth-time product / excess bandwidth factor.
		 * Usually 0.3 or 0.5.
		 */
		float bt;

		/*
		 * Length of the start/stop ramp in symbols
		 */
		unsigned int ramp_up_duration;
		unsigned int ramp_down_duration;
	};

	explicit GMSKModulator(const Config& conf = Config());

	~GMSKModulator();
	
	void reset();

	void sourceSamples(SampleVector& samples, Timestamp now);

	void setFrequency(float frequency);
	void setFrequencyOffset(float frequency_offset);

	Port<SymbolVector&, Timestamp> sourceSymbols;

private:
	SampleGenerator sampleGenerator();

	/* Configuration */
	Config conf;
	uint32_t symrate;           // integer symbol rate
	
	Timestamp sample_ns;        // Sample duration in ns
	unsigned int mod_rate;      // GMSK modulator samples per symbols rate
	unsigned int mod_max_samples;// Maximum number of samples generated from single symbol
	float nco_1Hz;
	unsigned int trailer_length; // Number of symbols in trailer [symbols]
	Timestamp filter_delay;      // Total timedelay in the FIR filtering [ns]

	/* State */
	SymbolVector symbols;     // Symbol buffer
	SampleGenerator sample_gen;
	SymbolGenerator symbol_gen;

	/* Liquid-DSP objects */
	gmskmod l_mod;            // GMSK modulator
	resamp_crcf l_resamp;     // Rational resampler
	nco_crcf l_nco;	          // NCO for mixing up the signal

};

}; // namespace suo
