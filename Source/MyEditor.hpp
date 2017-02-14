//
//  MyEditor.hpp
//  BPM Finder
//
//  Created by Joseph Lyons on 2/12/17.
//
//

#ifndef MyEditor_hpp
#define MyEditor_hpp

#include <stdio.h>
#include "../JuceLibraryCode/JuceHeader.h"

class MyEditor : public Button::Listener
{
private:
    ScopedPointer<TextButton> lockButton;
    
public:
    MyEditor();
    ~MyEditor();
    void buttonStateChanged (Button* b) override;
};

#endif /* MyEditor_hpp */
