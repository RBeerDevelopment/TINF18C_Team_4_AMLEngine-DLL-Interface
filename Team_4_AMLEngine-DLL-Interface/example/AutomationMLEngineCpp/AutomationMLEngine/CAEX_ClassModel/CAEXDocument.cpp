#include "StdAfx.h"
#include "CAEXDocument.h"
#include "SchemaConformanceException.h"


namespace CAEX_ClassModel
{

    CAEXDocument::CAEXDocument(CAEX_ClassModel *caexModel)
    {
        this->caexModel = caexModel;
    }

    CAEXFileType *CAEXDocument::getCAEXFile()
    {
        return caexFile;
    }

    void CAEXDocument::setCAEXFile(CAEXFileType *value)
    {
        caexFile = value;
    }

    CAEXDocument *CAEXDocument::New_CAEXDocument()
    {
        CAEX_ClassModel *caexModel = new CAEX_ClassModel(CAEX_ClassModel::CreateDocument());
        CAEXDocument *doc = new CAEXDocument(caexModel);

        doc->setCAEXFile( new CAEXFileType(caexModel->CAEXFile.append()) );
        doc->getCAEXFile()->FileName = "";
        doc->getCAEXFile()->SchemaVersion = "2.15";
        doc->getCAEXFile()->CaexSchemaLocation = "CAEX_ClassModel.xsd";

        // FIXME: the following must be done some way inside Property CaexSchemaLocation's callback WriteAccess in CAEXFileType
        string_type sl = doc->getCAEXFile()->CaexSchemaLocation;
        caexModel->SetSchemaLocation(sl);

        return doc;
    }

    CAEXDocument *CAEXDocument::LoadFromFile(string_type filename)
    {
        CAEX_ClassModel *caexModel = new CAEX_ClassModel(CAEX_ClassModel::LoadFromFile(filename));
        if (caexModel==0) return 0;

        if (! caexModel->CAEXFile.exists())
        {
            throw SchemaConformanceException("No root element <CAEXFile> found! File not valid");
        }
        CAEXDocument *doc = new CAEXDocument(caexModel);
        doc->setCAEXFile( new CAEXFileType(caexModel->CAEXFile.first()) );
        return doc;
    }

    void CAEXDocument::SaveToFile(string_type filename, bool prettyPrint)
    {
        caexModel->SaveToFile(filename, prettyPrint);
    }
}
