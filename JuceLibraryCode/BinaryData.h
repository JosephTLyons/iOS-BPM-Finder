/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_67995260_INCLUDED
#define BINARYDATA_H_67995260_INCLUDED

namespace BinaryData
{
    extern const char*   BPM_Finder_Notes_rtf;
    const int            BPM_Finder_Notes_rtfSize = 1147;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 1;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
