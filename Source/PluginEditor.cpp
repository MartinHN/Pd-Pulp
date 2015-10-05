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
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PureDataAudioProcessorEditor::PureDataAudioProcessorEditor (PureDataAudioProcessor& p)
    : AudioProcessorEditor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 200);

    setVisible(true);
    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PureDataAudioProcessorEditor::~PureDataAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PureDataAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PureDataAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]
    PureDataAudioProcessor * p = (PureDataAudioProcessor*)&processor;
    int idx = 0;
    std::cout << "resizing " << pd_parameters.size()<<std::endl;;
    if(pd_parameters.size()==0){
        return;
    }
    for(auto & param:p->pulpParameters){
        switch(param.type){
                
            case PureDataAudioProcessor::PulpParameter::KNOB:{

                pd_parameters[idx]->setBounds (getWidth() * (1+param.getX()) ,
                              getHeight() *param.getY()+headerSize ,
                              getWidth() * param.getWidth() ,
                              getHeight() * param.getHeight()+headerSize
                              )
                ;
                
                break;
            }
            default:
                std::cout << "no viable parameters for "<<param.name<< std::endl;;
                break;
        }
        

        Component * c = pd_parameters[idx];
         std::cout << " setting : " <<c->getName() << " : " << c->getX() << "," << c->getY() <<"," << c->getWidth() << "," << c->getHeight() << std::endl;
        
        idx++;
    }
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PureDataAudioProcessorEditor::changeListenerCallback (ChangeBroadcaster* source){
    PureDataAudioProcessor* p =  (PureDataAudioProcessor*)source;
    
    if(p!=NULL){
        rebuildParams(p);
        
    }
    
}

void PureDataAudioProcessorEditor::rebuildParams(PureDataAudioProcessor * p){
    for(auto & c:pd_parameters){
        removeChildComponent(c);
    }
    pd_parameters.clear();
    
    int idx = 0;
    for(auto & param:p->pulpParameters){
        switch(param.type){
                
            case PureDataAudioProcessor::PulpParameter::KNOB:{
                p->setParameterName(idx, param.name);

                SendSlider * c =new SendSlider(idx+1,*p);
                c->setName(param.name);
                c->setBounds (                  getWidth() * (1+param.getX()) ,
                                                (getHeight()-headerSize) *param.getY() ,
                                                 getWidth() * param.getWidth() ,
                                                 (getHeight()-headerSize) * param.getHeight()
                                                 );
                c->setRange(param.min, param.max);
                pd_parameters.add(c);
                std::cout << " adding : " <<c->getName() << std::endl;
                break;
            }
            default:
                std::cout << "no viable parameters for "<<param.name<< std::endl;;
            break;
        }
        
        idx++;
    }
    
    for(auto & c:pd_parameters){
       
        addAndMakeVisible(c);
    }
    PureDataAudioProcessorEditor::resized();

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PureDataAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="PureDataAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
