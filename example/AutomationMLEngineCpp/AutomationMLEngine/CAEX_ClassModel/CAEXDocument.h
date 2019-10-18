#ifndef _CAEXDOCUMENT_H_
#define _CAEXDOCUMENT_H_

//#include <StdAfx.h>

#include "CAEX_ClassModel.h"
//#include "CAEXFileType.h"
#include <string>

namespace CAEX_ClassModel
{
    class CAEXDocument
    {

    public:
        CAEX_ClassModel_EXPORT CAEXDocument(CAEX_ClassModel *caexModel);

    private:
        CAEX_ClassModel *caexModel;


        CAEXFileType *caexFile; // TODO *caexfile and its setter/getter (setCAEXFile and getCAEXFile) could be replaces by a Property class instance
    public:
        /// The root element of a CAEX file.
        CAEX_ClassModel_EXPORT CAEXFileType *getCAEXFile();
        CAEX_ClassModel_EXPORT void setCAEXFile(CAEXFileType *value);


        /// Creation of a new CAEX file (CAEXDocument). The CAEX root element CAEXFile is automatically added to the document.
        /// @note The user is responsible to delete the object the returned pointer is pointing to!
        /// @return An empty CAEX file with only the root element CAEXFile
        CAEX_ClassModel_EXPORT static CAEXDocument *New_CAEXDocument();

        /// Loading a CAEX file from the specified location.
        /// @param filename The CAEX file to load
        /// @note The user is responsible to delete the object the returned pointer is pointing to!
        /// @exception SchemaConformanceException mandatory element CAEXFile not found
        /// @return A CAEXDocument containing the file information
        CAEX_ClassModel_EXPORT static CAEXDocument *LoadFromFile(string_type filename);

        /// Saves the current document to the specified filepath.
        /// @param filename The filepath to save the document to.
        /// @param prettyPrint Set to true, if pretty printing is desired.
        CAEX_ClassModel_EXPORT void SaveToFile(string_type filename, bool prettyPrint);
    };
}

#endif // _CAEXDOCUMENT_H_
