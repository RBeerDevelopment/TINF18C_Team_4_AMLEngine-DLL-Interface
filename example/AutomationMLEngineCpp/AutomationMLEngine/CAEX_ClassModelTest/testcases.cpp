#include "StdAfx.h"

#include <string>

#include <CAEX_ClassModel.h>
#include <CAEXDocument.h>
#include <SchemaConformanceException.h>
//#include <xs-types.h>

#include "testcases.h"

#define TESTCASE_ASSERT_TEXT(text) { std::cout << "Failure: " << text << std::endl; return false; }
#define TESTCASE_ASSERT_TEXT_THROW(text) { std::cout << "Failure: " << text << std::endl; throw; }

bool testcases::newDocument()
{
    doc=CAEX_ClassModel::CAEXDocument::New_CAEXDocument();
    if (doc!=0) return true;
    return false;
}

bool testcases::createCAEXStructure()
{
    file = doc->getCAEXFile();
    file->FileName=std::string("testcase.aml");

    firstInstanceHierarchy=file->New_InstanceHierarchy("first instance name");
    if (firstInstanceHierarchy==0) TESTCASE_ASSERT_TEXT("firstInstanceHierarchy could not be instantiated");

    firstSystemUnitClassLib=file->New_SystemUnitClassLibHierarchy("first system unit class library");
    if (firstSystemUnitClassLib==0) TESTCASE_ASSERT_TEXT("firstSystemUnitClassLib could not be instantiated");

    firstRoleClassLib=file->New_RoleClassLibHierarchy("first role class library");
    if (firstRoleClassLib==0) TESTCASE_ASSERT_TEXT("firstRoleClassLib could not be instantiated");

    firstExternalReferenceHierarchy=file->New_ExternalReferenceHierarchy("first/external/reference/path","first role class lib alias");
    if (firstExternalReferenceHierarchy==0) TESTCASE_ASSERT_TEXT("firstExternalReferenceHierarchy could not be instantiated");

    secondInstanceHierarchy=file->New_InstanceHierarchy("second instance name");
    if (secondInstanceHierarchy==0) TESTCASE_ASSERT_TEXT("secondInstanceHierarchy could not be instantiated");

    secondSystemUnitClassLib=file->New_SystemUnitClassLibHierarchy("second system unit class library");
    if (secondSystemUnitClassLib==0) TESTCASE_ASSERT_TEXT("secondSystemUnitClassLib could not be instantiated");

    secondRoleClassLib=file->New_RoleClassLibHierarchy("second role class library");
    if (secondRoleClassLib==0) TESTCASE_ASSERT_TEXT("secondRoleClassLib could not be instantiated");

    secondExternalReferenceHierarchy=file->New_ExternalReferenceHierarchy("second/external/reference/path","second role class lib alias");
    if (secondExternalReferenceHierarchy==0) TESTCASE_ASSERT_TEXT("secondExternalReferenceHierarchy could not be instantiated");

    return true;
}

bool testcases::instanceHierarchyTests()
{
    CAEX_ClassModel::InternalElementType *internal=firstInstanceHierarchy->New_InternalElement("an internal Element");
    if (internal==0) TESTCASE_ASSERT_TEXT("an internal element could not be created");

    // entferne internal aus firstInstanceHierarchy und fuege es in firstInstanceHierarchy ein
    firstInstanceHierarchy->Insert_InternalElement(internal);

    // entferne internal aus firstInstancefirstInstanceHierarchy und fuege es in secondInstanceHierarchy ein
    secondInstanceHierarchy->Insert_InternalElement(internal);

    // einfuegen eines nicht passenden typs
    CAEX_ClassModel::RoleFamilyType *test=secondRoleClassLib->New_RoleClass("test role class");
    if (test==0) TESTCASE_ASSERT_TEXT("a RoleFamilyType for test could not be created");

    bool success=firstInstanceHierarchy->Insert_Element(test);
    if (success==true) TESTCASE_ASSERT_TEXT("test element of type RoleFamilyType has been faultily inserted as InternalElementType");

    // einfuegen einer neuen Instanz naemlich dem nicht passenden test vom Type RoleFamilyType
    // Dies ist moeglich, verstoest aber gegen das Schema
    firstInstanceHierarchy->Insert_NewInstance(test);

    // aufraeumen
    secondRoleClassLib->RoleClass.remove();
    delete test;
    delete internal;

    return true;
}

bool testcases::caexBasicObjectsTests()
{
    // revision einfuegen
    altova::DateTime date(2009,10,1,12,0,30);
    CAEX_ClassModel::RevisionType *revision=secondRoleClassLib->New_Revision(&date,string_type("Zuehlke Engineering GmbH"));
    if (revision==0) TESTCASE_ASSERT_TEXT("a new revision could not be created");

    // description einfugen
    CAEX_ClassModel::DescriptionType *description=secondRoleClassLib->New_Description();
    if (description==0) TESTCASE_ASSERT_TEXT("a new description could not be created");
    *description=string_type("This is the second Role Class Library instatiated for 'testcase'");

    // zweite description einfuegen -> sollte SchemaConformanceException werfen
    try
    {
        CAEX_ClassModel::DescriptionType *description2=secondRoleClassLib->New_Description();
        TESTCASE_ASSERT_TEXT("expected a SchemaConformanceException while inserting a second description, but exception hasn't been thrown");
    }
    catch (CAEX_ClassModel::SchemaConformanceException ex)
    {
        std::cout << "Caught expected SchemaConformanceException: " << ex.what() << std::endl;
    }

    // version einfuegen -> sollte zwischen description und revision landen
    CAEX_ClassModel::VersionType *version=secondRoleClassLib->New_Version();
    if (version==0) TESTCASE_ASSERT_TEXT("a new version could not be created");
    *version=string_type("Version 1.0");

    delete revision;
    delete description;
    delete version;

    return true;
}

bool testcases::writeDocument()
{
    try
    {
        doc->SaveToFile("testcase.aml", true);
        return true;
    }
    catch (...)
    {
        TESTCASE_ASSERT_TEXT_THROW("An exception occured during writing document to file");
    }
}


bool testcases::openDocument()
{
    return true;
}
