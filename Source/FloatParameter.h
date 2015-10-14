/*
  ==============================================================================

    FloatParameter.h
    Created: 3 Jul 2015 3:53:57pm
    Author:  Karl

  ==============================================================================
*/

#ifndef FLOATPARAMETER_H_INCLUDED
#define FLOATPARAMETER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class FloatParameter : public AudioProcessorParameter
{
public:
    
    FloatParameter (float defaultParameterValue, const String& paramName)
    : defaultValue (defaultParameterValue),
    value (defaultParameterValue),
    name (paramName)
    {
    }
    
    float getValue() const override
    {
        return value;
    }
    
    bool hasToObserve(){
        bool _c = changed;
        changed = false;
        return _c;
    }
    void setValue (float newValue) override
    {   changed = true;
        std::cout << name << std::endl;
        value = newValue;
    }
    
    float getDefaultValue() const override
    {
        return defaultValue;
    }
    
    String getName (int maximumStringLength) const override
    {
        return name;
    }
    
    void setName (String n)
    {
        name = n;
    }
    
    String getLabel() const override
    {
        return String();
    }
    
    float getValueForText (const String& text) const override
    {
        return text.getFloatValue();
    }
    
private:
    float defaultValue, value;
    bool changed ;
    String name;
};


#endif  // FLOATPARAMETER_H_INCLUDED
