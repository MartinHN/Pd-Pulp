/*
 ==============================================================================
 
 This is an automatically generated GUI class created by the Introjucer!
 
 Be careful when adding custom code to these files, as only the code within
 the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
 and re-saved.
 
 Created with Introjucer version: 3.1.1
 
 ------------------------------------------------------------------------------
 
 The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
 Copyright 2004-13 by Raw Material Software Ltd.
 
 ==============================================================================
 */

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "LabelComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
LabelComponent::LabelComponent (int index, AudioProcessor& processor)
: index(index),
processor(processor)
{
    
    
    addAndMakeVisible (label = new Label ("label",
                                          TRANS("Label")));
    label->setTooltip (TRANS("Click to set the name of the corresponding Pure Data receive port."));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, true, false);
    label->setColour (Label::backgroundColourId, Colour (0x00404040));
    label->setColour (Label::textColourId, Colour (0xffc4c4c4));
    label->setColour (TextEditor::textColourId, Colour (0xffe9e9e9));
    label->setColour (TextEditor::backgroundColourId, Colour (0x00343434));
    label->addListener (this);
    
    
    setSize (100, 130);
    
    PureDataAudioProcessor& p = (PureDataAudioProcessor&) processor;
    String labelText(p.getParameterName(index));
    setName(labelText);
    label->setJustificationType(juce::Justification::left);
    
    
    setPaintingIsUnclipped(true);
    
    label->setSize(200, 20);
    //    startTimer(25);
    
}

LabelComponent::~LabelComponent()
{
    
    
    component = nullptr;
    label = nullptr;
    
}

//==============================================================================
void LabelComponent::paint (Graphics& g)
{
    
    //    g.fillAll(juce::Colours::red);
    
}

void LabelComponent::resized()
{
    
    Rectangle<int> area = getLocalBounds();
    
    label->setTopLeftPosition(//area.getX() +
                              labelRelPos.getX(),
                              // area.getY() +
                              labelRelPos.getY() -labelSize);
    Font nF = label->getFont();
    nF.setHeight(labelSize);
    label->setFont(nF);
    label->setBounds(label->getBounds().withHeight(labelSize));
    if(component){
        component->setBounds(area);
        resizeComponent();
    }
    
}



void LabelComponent::labelTextChanged (Label* labelThatHasChanged)
{
    
    if (labelThatHasChanged == label)
    {
        
        PureDataAudioProcessor& p = (PureDataAudioProcessor&) processor;
        p.setParameterName(index, labelThatHasChanged->getTextValue().toString());
        
    }
    
}





