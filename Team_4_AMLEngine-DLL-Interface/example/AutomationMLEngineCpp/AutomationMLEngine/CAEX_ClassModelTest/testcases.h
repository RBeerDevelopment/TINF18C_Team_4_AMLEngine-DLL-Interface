#ifndef _TESTCASES_H_
#define _TESTCASES_H_

#include "StdAfx.h"

#include <CAEX_ClassModel.h>
#include <CAEXDocument.h>

class testcases
{
private:
    // interne pointer
    CAEX_ClassModel::CAEXDocument *doc;
    CAEX_ClassModel::CAEXFileType *file;
    CAEX_ClassModel::InstanceHierarchyType  *firstInstanceHierarchy;
    CAEX_ClassModel::SystemUnitClassLibType *firstSystemUnitClassLib;
    CAEX_ClassModel::RoleClassLibType       *firstRoleClassLib;
    CAEX_ClassModel::ExternalReferenceType  *firstExternalReferenceHierarchy;
    CAEX_ClassModel::InstanceHierarchyType  *secondInstanceHierarchy;
    CAEX_ClassModel::SystemUnitClassLibType *secondSystemUnitClassLib;
    CAEX_ClassModel::RoleClassLibType       *secondRoleClassLib;
    CAEX_ClassModel::ExternalReferenceType  *secondExternalReferenceHierarchy;

public:
    // alle testcases geben true zurueck, wenn sie erfolgreich waren. Ansonsten false.
    bool newDocument();
    bool writeDocument();
    bool createCAEXStructure();
    bool instanceHierarchyTests();
    bool caexBasicObjectsTests();

    bool openDocument();
};

#endif // _TESTCASES_H_