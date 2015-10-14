//
//  GUIMaker.h
//  Pd Pulp
//
//  Created by martin hermant on 13/10/15.
//
//

#ifndef __Pd_Pulp__GUIMaker__
#define __Pd_Pulp__GUIMaker__

#include "../JuceLibraryCode/JuceHeader.h"


class GUIMaker {
    public :

    void updateParametersFromPatch(File & patchfile);
    
    
    
    
    class PulpParameter: public juce::Rectangle<float>{
    public:
        String name;
        float min;
        float max;
        enum Type{
            KNOB= 0,
            NUMBOX,
            TOGGLE,
            POPUP
        };
        Type type;
        Rectangle<float> labelRect;
        Rectangle<float> getEnclosing(){return getUnion(labelRect);}
        bool hasLabel;
        int labelSize;
        String labelName;
    };
    
    Array<PulpParameter> pulpParameters;
    Rectangle<int> patchRect;
    
};
#endif /* defined(__Pd_Pulp__GUIMaker__) */
