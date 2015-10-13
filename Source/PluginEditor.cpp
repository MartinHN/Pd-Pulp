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
    updatePatch();
    
    
    
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
    AudioProcessorEditor::resized();
    //[/UserPreResize]
    PureDataAudioProcessor * p = (PureDataAudioProcessor*)&processor;
    int idx = 0;
    std::cout << "resizing " << pd_parameters.size()<<std::endl;;
    if(pd_parameters.size()==0){
        return;
    }
    
    Rectangle<int> area = patchRect;
    
    for(auto & param:pulpParameters){
        Rectangle<float> b = param;
        pd_parameters[idx]->setBounds (
                                       area.getX() + area.getWidth() * (b.getX()) ,
                                       area.getY() + area.getHeight() *b.getY(),
                                       area.getWidth() * b.getWidth() ,
                                       area.getHeight() * b.getHeight()
                                       )
        ;
        ((SendSlider*)pd_parameters[idx])->labelRelPos.setXY(area.getX() + area.getWidth() * (param.labelRect.getX()) ,
                                                             area.getY() + area.getHeight() *param.labelRect.getY()
                                                             );

        
        
        
        Component * c = pd_parameters[idx];
        std::cout << " setting : " <<param.getX() << "," << c->getName() << " : " << c->getX() << "," << c->getY() <<"," << c->getWidth() << "," << c->getHeight() << std::endl;
        
        idx++;
    }
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PureDataAudioProcessorEditor::updatePatch (){
    PureDataAudioProcessor* p =  (PureDataAudioProcessor*)&processor;
    
    if(p!=NULL && p->patchfile.exists()){
        updateParametersFromPatch(p->patchfile);
        patchRect.setY(headerRect.getBottom() );
        Rectangle<int> total = patchRect.getUnion(headerRect);
        setSize (total.getWidth(),total.getHeight());
        std::cout << "size : " << total.toString()<<" / " <<headerRect.toString() << std::endl;;
        rebuildParams(p);
        PureDataAudioProcessorEditor::resized();
    }
    
}

void PureDataAudioProcessorEditor::rebuildParams(PureDataAudioProcessor * p){
    for(auto & c:pd_parameters){
        removeChildComponent(c);
    }
    pd_parameters.clear();
    
    int idx = 0;
    Rectangle<int> area = patchRect;
    
    
    
    for(auto & param:pulpParameters){
        switch(param.type){
                
            case PulpParameter::KNOB:{
                p->setParameterName(idx, param.name);
                
                SendSlider * c =new SendSlider(idx+1,*p);
                c->setName(param.name);
                c->setBounds (
                              area.getX() + area.getWidth() * param.getX() ,
                              area.getY() + area.getHeight()* param.getY(),
                              area.getWidth() * param.getWidth() ,
                              area.getHeight()* param.getHeight()
                              );
                c->setRange(param.min, param.max);
                pd_parameters.add(c);
                std::cout << " adding knob: " <<c->getName() << std::endl;
                break;
            }
                
            case PulpParameter::NUMBOX:{
                p->setParameterName(idx, param.name);
                
                SendSlider * c =new SendSlider(idx+1,*p);
                c->setName(param.name);
                c->setBounds (
                              area.getX() + area.getWidth() * param.getX() ,
                              area.getY() + area.getHeight()* param.getY(),
                              area.getWidth() * param.getWidth() ,
                              area.getHeight() * param.getHeight()
                              );
                c->setRange(param.min, param.max);
                pd_parameters.add(c);
                std::cout << " adding numbox: " <<c->getName() << std::endl;
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
