/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Gain_slider_brianMoonAudioProcessorEditor::Gain_slider_brianMoonAudioProcessorEditor (Gain_slider_brianMoonAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gain_slider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    gain_slider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 60, 20);
    gain_slider.setTextBoxIsEditable(true);
    gain_slider.setTextValueSuffix(" dB");
    gain_slider.setRange (-75.0f, 12.0f, 0.01f);
    gain_slider.setValue (0.0f);
    gain_slider.addListener(this); // this refers to this class
    addAndMakeVisible (gain_slider);
    
    
    setSize (200, 300);
}

Gain_slider_brianMoonAudioProcessorEditor::~Gain_slider_brianMoonAudioProcessorEditor()
{
}

//==============================================================================
void Gain_slider_brianMoonAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::rebeccapurple);
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

//    g.setColour (juce::Colours::black);
    g.setFont (18.0f);
//    g.drawFittedText ("Gain", getLocalBounds(), juce::Justification::centredTop, 1);
//    g.drawText("Gain", getLocalBounds(), juce::Justification::centredTop);
    g.drawFittedText("Gain Slider", getWidth() / 2 - 50, 20, 100, 100, juce::Justification::centredTop, 1);
}

void Gain_slider_brianMoonAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gain_slider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 100, 100, 200);
}

// gain is modified the position of our slider
void Gain_slider_brianMoonAudioProcessorEditor::sliderValueChanged (juce::Slider *slider)
{
    if (slider == &gain_slider) {
        audioProcessor.gain_amount = gain_slider.getValue();
    }
}
