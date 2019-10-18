#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CCAEXBasicObject
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CCAEXBasicObject



namespace CAEX_ClassModel
{

class CAEXBasicObject : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT CAEXBasicObject(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT CAEXBasicObject(CAEXBasicObject const& init);
	void operator=(CAEXBasicObject const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CAEXBasicObject); }
	MemberAttribute<string_type,_altova_mi_altova_CAEXBasicObject_altova_ChangeMode> ChangeMode;	// ChangeMode CChangeMode
	MemberElement<DescriptionType, _altova_mi_altova_CAEXBasicObject_altova_Description> Description;
	struct Description { typedef Iterator<DescriptionType> iterator; };
	MemberElement<VersionType, _altova_mi_altova_CAEXBasicObject_altova_Version> Version;
	struct Version { typedef Iterator<VersionType> iterator; };
	MemberElement<RevisionType, _altova_mi_altova_CAEXBasicObject_altova_Revision> Revision;
	struct Revision { typedef Iterator<RevisionType> iterator; };
	MemberElement<CopyrightType, _altova_mi_altova_CAEXBasicObject_altova_Copyright> Copyright;
	struct Copyright { typedef Iterator<CopyrightType> iterator; };
	MemberElement<xs::CanyType, _altova_mi_altova_CAEXBasicObject_altova_AdditionalInformation> AdditionalInformation;
	struct AdditionalInformation { typedef Iterator<xs::CanyType> iterator; };


    // added
    static const string_type PATH_SEPARATOR;

    static const string_type NAME_ATTRIBUTE;

    /// Get the description of this object. The returned object is null when no description element is found!
    /// @note The user is responsible to delete the object the returned pointer references!
    DescriptionType *getDescription();

    /// Get the VersionType of this header object.
    /// @note The user is responsible to delete the object the returned pointer references!
    VersionType *getVersion();

    /// Get the CopyrightType of this header object.
    /// @note The user is responsible to delete the object the returned pointer references!
    CopyrightType *getCopyright();

    /// This methods returns the last XmlNode of this CAEX basic object according to the element order given by the CAEX schema. In this
    /// context "last" describes the element that is at the end of this header elements.
    /// @return The last header element node
    CAEX_ClassModel_EXPORT xercesc::DOMNode *getLastHeaderNode();

    /// Creating a new description element. An exception is thrown when a description element is already present.
    /// @return A newly created DescriptionType element. An exception of type SchemaConformanceException is thrown when a description element is already present
    /// @exception SchemaConformanceException element is already existent
    /// @note The user is responsible to delete the object the returned pointer references!
    ///
    CAEX_ClassModel_EXPORT DescriptionType *New_Description();

    /// Creating a new version element.  An exception is thrown when a version element is already present. The sibling order according to the CAEX Schema is preserved in that way, that version nodes are
    /// always inserted after nodes of type DescriptionType
    /// @return A newly created VersionType element. An exception of type SchemaConformanceException is thrown when a version element is already present
    /// @exception SchemaConformanceException element is already existent
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT VersionType *New_Version();

    /// Creating a new revision element. According to CAEX schema each revision element must contain at least the two sub elements "RevisionDate" and "AuthorName". They are created with this revision object. The sibling order according to the CAEX Schema is preserved in that way, that revision nodes are
    /// always inserted after nodes of type VersionType
    /// @return A newly created RevisionType element.
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT RevisionType *New_Revision(altova::DateTime *date, string_type author);

    /// Adding an new Copyright node to this object. If a Copyright node is already existent when calling this method an exception is thrown.
    /// @return A new Copyright node
    /// @exception SchemaConformanceException element is already existent
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT CopyrightType *New_Copyright();

    /// Adding a new AdditionalInformation node to this basic object. It is allowed to insert more than one AdditionalInformation node
    /// @return A new AdditionalInformation node as type anyType
    /// @note The user is responsible to delete the object the returned pointer references!
    CAEX_ClassModel_EXPORT xs::CanyType *New_AdditionalInformation();

    /// Removing all header elements from this basicobject
    CAEX_ClassModel_EXPORT void RemoveHeader();

    /// Getting the full path from document root to the specified XmlNode. As name of an XmlNode is the value of the contained attribute "name" taken. Hierarchies are sparated via the path separator (slash '/').
    /// The name of the document root element CAEXFile is not contained in the path.
    /// @param xmlNode The XmlNode to get the full path for
    /// @return The full path from the document root element to the given XmlNode. The path contains of values of the "name" attribute of the XmlNodes. If no
    /// such attribute existst in the current node, the xml tag name is used instead.
    CAEX_ClassModel_EXPORT string_type getFullNodePath(xercesc::DOMNode *xmlNode);

    /// Getting a referenced RoleClass.
    /// @param roleClassReference Full path to a RoleClass
    /// @return The referenced RoleClass
    CAEX_ClassModel_EXPORT RoleFamilyType *getReferencedRoleClass(string_type roleClassReference);

    /// Getting a referenced SystemUnitClass.
    /// @param systemUnitClassReference Full path to a SystemUnitClass
    /// @return The referenced SystemUnitClass
    CAEX_ClassModel_EXPORT SystemUnitFamilyType *getReferencedSystemUnitClass(string_type systemUnitClassReference);

    /// Getting a referenced InterfaceClass.
    /// @param interfaceClassReference Full path to an InterfaceClass
    /// @return The referenced InterfaceClass
    CAEX_ClassModel_EXPORT InterfaceFamilyType *getReferencedInterfaceClass(string_type interfaceClassReference);

    /// Getting the XmlNode for a classpath.
    /// @param referencedClassPath The full path to the referenced class. Hierarchies are sparated via slash "/"
    /// @return The XmlnNode of the desired class, or null if none found
    /// @exception altova::Exception* forwards this exception
    CAEX_ClassModel_EXPORT xercesc::DOMNode *getReferencedClass(string_type referencedClassPath);

    /// Getting the name of the referenced Interface.
    /// @param reference A reference to a interface class in form GUID:InterfaceClass
    /// @return The name of the referenced interface class
    CAEX_ClassModel_EXPORT string_type getReferencedInterfaceName(string_type reference);

    /// Parsing a string of form GUID:Interface and returning the GUID
    /// @param reference A reference in form GUID:InterfaceClass
    /// @return The GUID
    CAEX_ClassModel_EXPORT string_type getReferencedGUID(string_type reference);

    /// Resolve a reference to an InternalElement and return the refernced element if found.
    /// @param referenceGUID The GUID of the InternalElement
    /// @return The InternalElement with the specified GUID
    CAEX_ClassModel_EXPORT InternalElementType *findInternalElement(string_type referenceGUID);

    /// Check if the given classPath is a valid path to an existent class in the AML file.
    /// @param classPath The class path to check for validity.
    /// @return True if a class at the given path exists, else false.
    CAEX_ClassModel_EXPORT bool ConsistencyCheck_ClassReference(string_type classPath);


    /// Generic method to insert an element of type TypeBase in this object.
    /// This method could be declared as abstract, but then all inherited classes have to implement this method but not
    /// all inhertied classes use this method.
    /// @param elementToInsert the element to insert
    /// @return true on succes and false on failure
    CAEX_ClassModel_EXPORT bool Insert_TypeBaseElement(TypeBase *elementToInsert);



    /// Create a clone of this object via reflection. The underlying XMLNode is normally cloned and a new instance of this class is created
    /// via Activator.CreateInstance with the cloned xml node.
    /// If an object of type InternalElement should be cloned, the method create_uniquecopy is called instead of using reflection to automatically get new
    /// GUIDs assigned.
    /// @returns A clone copy of this object
    CAEX_ClassModel_EXPORT TypeBase *clone();

};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CCAEXBasicObject
