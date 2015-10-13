//
//  GUIMaker.cpp
//  Pd Pulp
//
//  Created by martin hermant on 13/10/15.
//
//

#include "GUIMaker.h"


void GUIMaker::updateParametersFromPatch(File & patchfile){
    juce::StringArray destLines;
    File guipatch = File(patchfile.getParentDirectory().getChildFile("gui.pd"));
    if(!guipatch.exists()){
        return;
    }
    std::cout << "loading gui" << std::endl;
    guipatch.readLines(destLines);
    pulpParameters.clear();
    patchRect.setBounds(0, 0, 0, 0);
    String concatL = "";
    for(auto & l : destLines){
        concatL +=l;
        if(l.endsWith(";")){
            
            juce::StringArray curS ;
            curS.addTokens (concatL," ;","");
            
            if(concatL.startsWith("#N canvas")){
                patchRect.setSize(curS[4].getIntValue(),curS[5].getIntValue());
                
            }
            else if(concatL.startsWith("#X obj")){
                
                if(curS.size()>4){
                    // numBox
                    if(curS[4] == "nbx" && curS.size()>15){
                        PulpParameter p;
                        p.type = PulpParameter::NUMBOX;
                        p.name = curS[11];
                        p.min = curS[7].getFloatValue();
                        p.max = curS[8].getFloatValue();
                        p.setBounds(curS[2].getFloatValue()/patchRect.getWidth(),
                                    curS[3].getFloatValue()/patchRect.getHeight(),
                                    (20+curS[5].getFloatValue()*10.0)/patchRect.getWidth(),
                                    (1+curS[6].getFloatValue())/patchRect.getHeight());
                        p.labelRect.setBounds((p.getX() - curS[14].getFloatValue())/patchRect.getWidth(),
                                                 (p.getY() - curS[15].getFloatValue())/patchRect.getHeight(),
                                                 (p.name.length()*curS[17].getFloatValue())/patchRect.getWidth(),
                                                 (curS[17].getFloatValue()/patchRect.getHeight()));
                        pulpParameters.add(p);
                        
                    }
                    else if(curS[4] == "knob" && curS.size()>15){
                        PulpParameter p;
                        p.type = PulpParameter::KNOB;
                        p.name = curS[11];
                        p.min = curS[7].getFloatValue();
                        p.max = curS[8].getFloatValue();
                        p.setBounds(curS[2].getFloatValue()/patchRect.getWidth(),
                                    curS[3].getFloatValue()/patchRect.getHeight(),
                                    (curS[5].getFloatValue())/patchRect.getWidth(),
                                    (curS[6].getFloatValue())/patchRect.getHeight());
                        p.labelRect.setBounds((p.getX() - curS[14].getFloatValue())/patchRect.getWidth(),
                                              (p.getY() - curS[15].getFloatValue())/patchRect.getHeight(),
                                              (p.name.length()*curS[17].getFloatValue())/patchRect.getWidth(),
                                              (curS[17].getFloatValue()/patchRect.getHeight()));
                        pulpParameters.add(p);
                        
                    }
                    
                    
                }
                
            }
            concatL.clear();
        }
        
        
    }
    if(pulpParameters.size()>0){
        float minX = pulpParameters[0].getX();
        float minY = pulpParameters[0].getY();
        
        for(auto & p:pulpParameters){
            minX = std::min(minX, p.getX()) ;
            minY = std::min(minY, p.getY()) ;
        }
        for(auto & p:pulpParameters){
            p.setPosition( p.getX()-minX,p.getY()-minY);
        }
    }
    
}