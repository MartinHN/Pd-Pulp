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

#ifndef __JUCE_HEADER_E639DC74856C933A__
#define __JUCE_HEADER_E639DC74856C933A__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
 //[Comments]
 An auto-generated component, created by the Introjucer.
 
 Describe your class and how it works here!
 //[/Comments]
 */
class LabelComponent  : public Component,
public LabelListener
{
public:
    //==============================================================================
    LabelComponent (int index, AudioProcessor& processor);
    ~LabelComponent();
    
    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    //[/UserMethods]
    
    void paint (Graphics& g);
    void resized();
    virtual void resizeComponent() {};
    void setName(const String&  s) override{
    Component::setName(s);
    label->setText(s, dontSendNotification);
    };
    

    void labelTextChanged (Label* labelThatHasChanged);
    
    
    
    Point<float> labelRelPos;
    float labelSize = 15;
protected:
    //[UserVariables]   -- You can add your own custom variables in this section.
    int index;
    AudioProcessor& processor;
    //[/UserVariables]
    
    //==============================================================================
    ScopedPointer<Component> component;
    ScopedPointer<Label> label;
    
    
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LabelComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_E639DC74856C943A__
