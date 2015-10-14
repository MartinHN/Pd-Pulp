

#include "PdAudioProcessorEditor.h"


PdAudioProcessorEditor::PdAudioProcessorEditor (PureDataAudioProcessor& p)
: AudioProcessorEditor (p)

{

    setVisible(true);
    
}

PdAudioProcessorEditor::~PdAudioProcessorEditor()
{
    
}

void PdAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
}

void PdAudioProcessorEditor::resized()
{
    
    AudioProcessorEditor::resized();
    
    PureDataAudioProcessor * p = (PureDataAudioProcessor*)&processor;
    int idx = 0;
    DBG( "resizing GUI " << juce_Components.size());
    if(juce_Components.size()==0){
        return;
    }
    
    Rectangle<int> area = p->patchRect;
    
    for(auto & param:p->pulpParameterDescs){
        Rectangle<float> b = param;
        LabelComponent * c = ((LabelComponent*)juce_Components[idx]);
        if(c!=nullptr){
        c->labelRelPos.setXY(area.getX() + area.getWidth() * param.labelRect.getX() ,
                             area.getY() + area.getHeight() *param.labelRect.getY()
                             );
        juce_Components[idx]->setBounds (
                                         area.getX() + area.getWidth() * b.getX() ,
                                         area.getY() + area.getHeight()* b.getY(),
                                         area.getWidth() * b.getWidth() ,
                                         area.getHeight()* b.getHeight()
                                         )
        ;
        
        
        
        DBG( " resizing UI : " << c->getName() <<  " : " <<
            ((SendSlider*)c)->labelRelPos.toString() << " / "
            << c->getBounds().toString() );;
        }
        idx++;
    }
    
}


void PdAudioProcessorEditor::updatePatch (){
    PureDataAudioProcessor* p =  (PureDataAudioProcessor*)&processor;
    
    if(p!=NULL && p->patchfile.exists()){
        p->patchRect.setY(headerRect.getBottom() );
        Rectangle<int> total = p->patchRect.getUnion(headerRect);
        setSize (total.getWidth(),total.getHeight());
        DBG( "size : " << total.toString()<<" / " <<headerRect.toString() );;;
        rebuildParams(p);
        PdAudioProcessorEditor::resized();
    }
    
}

void PdAudioProcessorEditor::rebuildParams(PureDataAudioProcessor * p){
    for(auto & c:juce_Components){
        removeChildComponent(c);
    }
    juce_Components.clear();
    
    int idx = 0;
    Rectangle<int> area = p->patchRect;
    
    
    
    for(auto & param:p->pulpParameterDescs){
        LabelComponent *c=nullptr;
        
        
        if(param.type == PdParamGetter::PulpParameterDesc::KNOB || param.type == PdParamGetter::PulpParameterDesc::NUMBOX){
            c =new SendSlider(idx,*p);
            ((SendSlider*)c)->setRange(param.min, param.max);
            
        }
        else if(param.type == PdParamGetter::PulpParameterDesc::TOGGLE){
            c =new SendToggle(idx,*p);
            
        }
        if(c!=nullptr){
            
            c->labelSize = param.labelSize;
            c->setName(param.labelName);
            p->setParameterName(idx, param.name);
            juce_Components.add(c);
            c->setBounds (
                          area.getX() + area.getWidth() * param.getX(),
                          area.getY() + area.getHeight()* param.getY(),
                          area.getWidth() * param.getWidth() ,
                          area.getHeight()* param.getHeight()
                          );
            
            idx++;
        }
        else{
            DBG( "no viable parameters for "<<param.name);;;
            
        }
    }
    
    for(auto & c:juce_Components){
        
        addAndMakeVisible(c);
    }
    
    
}


