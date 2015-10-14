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

#ifndef __JUCE_HEADER_E639DC74856C943A__
#define __JUCE_HEADER_E639DC74856C943A__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "LabelComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SendSlider  : public LabelComponent,public SliderListener
{
public:
    //==============================================================================
    SendSlider (int index, AudioProcessor& processor)
    : LabelComponent(index,processor)
    
    {
        //[Constructor_pre] You can add your own custom stuff here..
        //[/Constructor_pre]
        
        addAndMakeVisible (component = new Slider ("slider"));
        
        getSlider()->setSliderStyle (Slider::RotaryVerticalDrag);
        getSlider()->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 12);
        getSlider()->setColour (Slider::thumbColourId, Colour (0xff5c5c5c));
        getSlider()->setColour (Slider::rotarySliderFillColourId, Colour (0x7fdddddd));
        getSlider()->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66e6e6e6));
        getSlider()->setColour (Slider::textBoxHighlightColourId, Colour (0x40a6a6a6));
        getSlider()->setColour(juce::Slider::textBoxBackgroundColourId, juce::Colours::transparentWhite);
        getSlider()->setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentWhite);
        getSlider()->addListener (this);
  
        
        //[UserPreSize]
        //[/UserPreSize]
        
        setSize (100, 130);
        
        
        
        
        //[/Constructor]
    }
    ~SendSlider(){};

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback(){getSlider()->setValue(processor.getParameter(index), NotificationType::dontSendNotification);};
    //[/UserMethods]
    void resizeComponent(){};
    void sliderValueChanged (Slider* sliderThatWasMoved){
        if (sliderThatWasMoved == getSlider()){
         processor.setParameterNotifyingHost(index, sliderThatWasMoved->getValue());
//            sliderThatWasMoved->setValue(processor.getParameter(index), NotificationType::dontSendNotification);
            
        }
    }

    void setRange(float min,float max){getSlider()->setRange(min,max);}

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Slider* getSlider(){return (Slider*) component.get();}
    


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SendSlider)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_E639DC74856C943A__
