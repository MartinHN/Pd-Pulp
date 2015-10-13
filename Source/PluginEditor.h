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

#ifndef __JUCE_HEADER_DFA254F056F7859__
#define __JUCE_HEADER_DFA254F056F7859__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]

#include "SendSlider.h"
#include "GUIMaker.h"
//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PureDataAudioProcessorEditor  : public AudioProcessorEditor ,public GUIMaker
{
public:
    //==============================================================================
    PureDataAudioProcessorEditor (PureDataAudioProcessor& p);
    ~PureDataAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void updatePatch ();
    void rebuildParams(PureDataAudioProcessor * p);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    Rectangle<int> headerRect;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    OwnedArray<Component>pd_parameters;
    
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PureDataAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_DFA254F056F7859__
