#ifndef _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAEX_ClassModel
#define _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAEX_ClassModel



namespace CAEX_ClassModel
{

class CAEX_ClassModel : public TypeBase
{
public:
	CAEX_ClassModel_EXPORT CAEX_ClassModel(xercesc::DOMNode* const& init);
	CAEX_ClassModel_EXPORT CAEX_ClassModel(CAEX_ClassModel const& init);
	void operator=(CAEX_ClassModel const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CAEX_ClassModel); }
	MemberElement<CAEXFileType, _altova_mi_altova_CAEX_ClassModel_altova_CAEXFile> CAEXFile;
	struct CAEXFile { typedef Iterator<CAEXFileType> iterator; };

	// document functions
	CAEX_ClassModel_EXPORT static CAEX_ClassModel LoadFromFile(const string_type& fileName);
	CAEX_ClassModel_EXPORT static CAEX_ClassModel LoadFromString(const string_type& xml);
	CAEX_ClassModel_EXPORT static CAEX_ClassModel LoadFromBinary(const std::vector<unsigned char>& data);
	CAEX_ClassModel_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint );
	CAEX_ClassModel_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, const string_type& encoding );
	CAEX_ClassModel_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM );
	CAEX_ClassModel_EXPORT string_type SaveToString(bool prettyPrint);
	CAEX_ClassModel_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint);
	CAEX_ClassModel_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint, const string_type& encoding);
	CAEX_ClassModel_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM);
 	CAEX_ClassModel_EXPORT static CAEX_ClassModel CreateDocument();
	CAEX_ClassModel_EXPORT void DestroyDocument();
	CAEX_ClassModel_EXPORT void SetDTDLocation(const string_type& dtdLocation);
	CAEX_ClassModel_EXPORT void SetSchemaLocation(const string_type& schemaLocation);
protected:
	XercesTreeOperations::DocumentType GetDocumentNode() { return (XercesTreeOperations::DocumentType)m_node; }
};


}	// namespace CAEX_ClassModel

#endif // _ALTOVA_INCLUDED_CAEX_ClassModel_ALTOVA__ALTOVA_CAEX_ClassModel
