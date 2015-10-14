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


#include "PluginEditor.h"


PureDataAudioProcessorEditor::PureDataAudioProcessorEditor (PureDataAudioProcessor& p)
: AudioProcessorEditor (p)

{

    
    
    
    setVisible(true);

}

PureDataAudioProcessorEditor::~PureDataAudioProcessorEditor()
{

}

void PureDataAudioProcessorEditor::paint (Graphics& g)
{

    
    g.fillAll (Colours::white);

}

void PureDataAudioProcessorEditor::resized()
{

    AudioProcessorEditor::resized();

    PureDataAudioProcessor * p = (PureDataAudioProcessor*)&processor;
    int idx = 0;
    std::cout << "resizing " << pd_parameters.size()<<std::endl;;
    if(pd_parameters.size()==0){
        return;
    }
    
    Rectangle<int> area = patchRect;
    
    for(auto & param:pulpParameters){
        Rectangle<float> b = param;
        LabelComponent * c = ((LabelComponent*)pd_parameters[idx]);
        c->labelRelPos.setXY(area.getX() + area.getWidth() * param.labelRect.getX() ,
                             area.getY() + area.getHeight() *param.labelRect.getY()
                             );
        pd_parameters[idx]->setBounds (
                                       area.getX() + area.getWidth() * b.getX() ,
                                       area.getY() + area.getHeight()* b.getY(),
                                       area.getWidth() * b.getWidth() ,
                                       area.getHeight()* b.getHeight()
                                       )
        ;
        
        
        
        std::cout << " resizing : " << ((SendSlider*)c)->labelRelPos.toString() << "," << c->getName() << " : " << c->getX() << "," << c->getY() <<"," << c->getWidth() << "," << c->getHeight() << std::endl;
        
        idx++;
    }
 
}


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
        LabelComponent *c;
        
        
        if(param.type == PulpParameter::KNOB || param.type == PulpParameter::NUMBOX){
            c =new SendSlider(idx,*p);
            ((SendSlider*)c)->setRange(param.min, param.max);
            
        }
        else if(param.type == PulpParameter::TOGGLE){
            c =new SendToggle(idx,*p);
            
        }
        if(c!=nullptr){
        
        c->labelSize = param.labelSize;
        c->setName(param.labelName);
        p->setParameterName(idx, param.name);
        pd_parameters.add(c);
        c->setBounds (
                      area.getX() + area.getWidth() * param.getX(),
                      area.getY() + area.getHeight()* param.getY(),
                      area.getWidth() * param.getWidth() ,
                      area.getHeight()* param.getHeight()
                      );
        
        idx++;
        }
        else{
            std::cout << "no viable parameters for "<<param.name<< std::endl;;

        }
    }
    
    for(auto & c:pd_parameters){
        
        addAndMakeVisible(c);
    }
    
    
}


