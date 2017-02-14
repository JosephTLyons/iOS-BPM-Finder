//
//  MyEditor.cpp
//  BPM Finder
//
//  Created by Joseph Lyons on 2/12/17.
//
//

#include "MyEditor.hpp"

MyEditor::MyEditor()
{
    // Your button
    lockButton->addListener(this);
}

MyEditor::~MyEditor()
{
    // Your button
    
    lockButton->removeListener(this);
}

void MyEditor::buttonStateChanged (Button* b)
{
    if (b == lockButton && lockButton->isDown())
    {
    }
}
