#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRevisionType
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRevisionType

#include "CAEXBasicObject.h"


namespace CAEX_ClassModel
{

class RevisionType : public CAEXBasicObject
{
public:
	CAEX_ClassModel_EXPORT RevisionType(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT RevisionType(RevisionType const& init);
	void operator=(RevisionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_RevisionType); }
	MemberElement<CopyrightType, _altova_mi_altova_RevisionType_altova_Copyright> Copyright;
	struct Copyright { typedef Iterator<CopyrightType> iterator; };
	MemberElement<xs::CanyType, _altova_mi_altova_RevisionType_altova_AdditionalInformation> AdditionalInformation;
	struct AdditionalInformation { typedef Iterator<xs::CanyType> iterator; };
	MemberElement<xs::CdateTimeType, _altova_mi_altova_RevisionType_altova_RevisionDate> RevisionDate;
	struct RevisionDate { typedef Iterator<xs::CdateTimeType> iterator; };
	MemberElement<xs::CstringType, _altova_mi_altova_RevisionType_altova_OldVersion> OldVersion;
	struct OldVersion { typedef Iterator<xs::CstringType> iterator; };
	MemberElement<xs::CstringType, _altova_mi_altova_RevisionType_altova_NewVersion> NewVersion;
	struct NewVersion { typedef Iterator<xs::CstringType> iterator; };
	MemberElement<xs::CstringType, _altova_mi_altova_RevisionType_altova_AuthorName> AuthorName;
	struct AuthorName { typedef Iterator<xs::CstringType> iterator; };
	MemberElement<xs::CstringType, _altova_mi_altova_RevisionType_altova_Comment> Comment;
	struct Comment { typedef Iterator<xs::CstringType> iterator; };

    // added

    /// Adds a new OldVersion node to this revision. A SchemaConformanceException is thrown when an OldVersion node is already existent.
    /// @note The user is responsible to delete the object the returned pointer references!
    /// @exception SchemaConformanceException element is already existent
    /// @return A new OldVersion node
    CAEX_ClassModel_EXPORT xs::CstringType *New_OldVersion();

    /// Adds a new NewVersion node to this revision. A SchemaConformanceException is thrown when an OldVersion node is already existent.
    /// @note The user is responsible to delete the object the returned pointer references!
    /// @exception SchemaConformanceException element is already existent
    /// @return A new NewVersion node
    CAEX_ClassModel_EXPORT xs::CstringType *New_NewVersion();

    /// Adds a Comment to this Revision node.
    /// @note The user is responsible to delete the object the returned pointer references!
    /// @return A new Comment node as stringType
    CAEX_ClassModel_EXPORT xs::CstringType *New_Comment();

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CRevisionType
