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
        concatL+=" ";
        if(l.endsWith(";")){
            
            juce::StringArray curS ;
            curS.addTokens (concatL," ;","");
            
            if(concatL.startsWith("#N canvas")){
                patchRect.setSize(curS[4].getIntValue(),curS[5].getIntValue());
                
            }
            else if(concatL.startsWith("#X obj")){
                
                if(curS.size()>4){
                    String pdType = curS[4];
                    
                    if((pdType == "nbx" || pdType== "knob" || pdType == "tgl") && curS.size()>15){
                        PulpParameter p;
                        p.hasLabel = curS[13]!="empty";
                        p.labelName = curS[13];
                        p.min = curS[7].getFloatValue();
                        p.max = curS[8].getFloatValue();
                        
                        p.labelRect.setBounds((p.getX() - curS[14].getFloatValue())/patchRect.getWidth(),
                                              (p.getY() - curS[15].getFloatValue())/patchRect.getHeight(),
                                              (p.name.length()*curS[17].getFloatValue())/patchRect.getWidth(),
                                              (curS[17].getFloatValue()/patchRect.getHeight()));
                        p.labelSize = curS[17].getFloatValue();
                        p.name=curS[11];
                        
                        // numBox
                        if(pdType == "nbx" ){
                            p.type = PulpParameter::NUMBOX;
                            p.setBounds(curS[2].getFloatValue()/patchRect.getWidth(),
                                        curS[3].getFloatValue()/patchRect.getHeight(),
                                        (20+curS[5].getFloatValue()*10.0)/patchRect.getWidth(),
                                        (1+curS[6].getFloatValue())/patchRect.getHeight());
                            
                        }
                        else if(pdType == "knob" ){
                            p.type = PulpParameter::KNOB;
                            
                            p.setBounds(curS[2].getFloatValue()/patchRect.getWidth(),
                                        curS[3].getFloatValue()/patchRect.getHeight(),
                                        (curS[5].getFloatValue())/patchRect.getWidth(),
                                        (curS[6].getFloatValue())/patchRect.getHeight());
                            
                            
                        }
                        
                        else if(pdType == "tgl"){
                            p.type = PulpParameter::TOGGLE;
                            p.hasLabel = curS[9]!="empty";
                            p.labelName =  curS[9];
                            p.name = curS[7];
                            p.labelSize = curS[13].getFloatValue();
                            p.setBounds(curS[2].getFloatValue()/patchRect.getWidth(),
                                        curS[3].getFloatValue()/patchRect.getHeight(),
                                        curS[5].getFloatValue()/patchRect.getWidth(),
                                        curS[5].getFloatValue()/patchRect.getHeight());
                            p.labelRect.setBounds((p.getX() - curS[10].getFloatValue())/patchRect.getWidth(),
                                                  (p.getY() - curS[11].getFloatValue())/patchRect.getHeight(),
                                                  (p.name.length()*p.labelSize)/patchRect.getWidth(),
                                                  (p.labelSize/patchRect.getHeight()));
                            
                            
                            
                            
                        }
                        pulpParameters.add(p);
                    }
                    
                    
                }
                
            }
            concatL.clear();
        }
        
        
    }
    
    // find top left most coordinate from pd
    if(pulpParameters.size()>0){
        float minX = std::min(std::min(minX, pulpParameters[0].getX()),pulpParameters[0].labelRect.getX()) ;
        float minY = std::min(std::min(minY, pulpParameters[0].getY()),pulpParameters[0].labelRect.getY()) ;
        
        for(auto & p:pulpParameters){
            minX = std::min(std::min(minX, p.getX()),p.labelRect.getX()) ;
            minY = std::min(std::min(minY, p.getY()),p.labelRect.getY()) ;
        }
        for(auto & p:pulpParameters){
            p.setPosition( p.getX()-minX,p.getY()-minY);
        }
    }
    
}