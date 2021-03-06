#include <JuceHeader.h>
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SoftVstAudioProcessor& p) : processor(p)
{
	setSize(400, 400);

	// Configure combobox settings 
	oscMenu.addItem("Sine", 1);
	oscMenu.addItem("Saw", 2);
	oscMenu.addItem("Square", 3);
	oscMenu.addItem("Phasor", 4);
	oscMenu.addItem("Triangle", 5);
	oscMenu.addItem("Noise", 6);
	oscMenu.setJustificationType(Justification::centred); 
	addAndMakeVisible(oscMenu);

	// Menu title settings
	oscLabel.setFont(Font(24.0f, Font::bold));
	oscLabel.setText("Oscillator", dontSendNotification);
	oscLabel.attachToComponent(&oscMenu, false);
	oscLabel.setJustificationType(Justification::centred);
	addAndMakeVisible(oscLabel);

	oscMenuAttachment = 
		std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.apvts, 
		OSC_ID, oscMenu);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
	g.fillAll(Colours::lightseagreen);
}

void Oscillator::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(100);

	oscMenu.setBounds(area);
}
