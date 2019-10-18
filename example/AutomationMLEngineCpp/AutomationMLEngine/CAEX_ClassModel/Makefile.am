INCLUDES = -I$(top_srcdir)/Altova -I$(top_srcdir)/AltovaXML \
	-I../../xerces-c-src_2_8_0/include
METASOURCES = AUTO
bin_PROGRAMS = libCAEX_ClassModel.so
libCAEX_ClassModel_so_SOURCES = AttributeType.cpp \
	AttributeValueRequirementType.cpp CAEXBasicObject.cpp CAEXDocument.cpp CAEXDocument.h CAEXFileType.cpp \
	CAEX_ClassModel-typeinfo.cpp CAEX_ClassModel-typeinfo.h CAEX_ClassModel.cpp CAEX_ClassModel.h \
	CAEX_ClassModel_common.h COLLADAReferenceAttributeType.cpp ClassInstantiationException.cpp \
	ClassInstantiationException.h FrameAttributeType.cpp FrameValues.cpp GlobalUID.cpp \
	InstanceHierarchyType.cpp InterfaceClassLibType.cpp InterfaceClassType.cpp \
	InterfaceFamilyType.cpp InternalElementType.cpp InternalLinkType.cpp LinkedObjects.cpp \
	MappingType.cpp NominalScaledTypeType.cpp OrdinalScaledTypeType.cpp Property.h \
	RevisionType.cpp RoleClassLibType.cpp RoleClassType.cpp RoleFamilyType.cpp \
	RoleRequirementsType.cpp SchemaConformanceException.cpp SchemaConformanceException.h StdAfx.cpp \
	StdAfx.h SupportedRoleClassType.cpp SystemUnitClassLibType.cpp \
	SystemUnitClassType.cpp SystemUnitFamilyType.cpp TypeBase.cpp TypeBase.h UnknownTypeType.cpp \
	XMLTools.cpp type_.CAttributeDataTypeType.h type_.CAttributeNameMappingType.h \
	type_.CAttributeType.h type_.CAttributeValueRequirementType.h type_.CCAEXBasicObject.h \
	type_.CCAEXFileType.h type_.CCAEXObject.h type_.CCAEX_ClassModel.h type_.CChangeMode.h \
	type_.CCopyrightType.h type_.CDescriptionType.h type_.CExternalInterfaceType.h \
	type_.CExternalReferenceType.h type_.CInstanceHierarchyType.h type_.CInterfaceClassLibType.h \
	type_.CInterfaceClassType.h type_.CInterfaceFamilyType.h type_.CInterfaceNameMappingType.h \
	type_.CInternalElementType.h type_.CInternalLinkType.h type_.CMappingType.h \
	type_.CNominalScaledTypeType.h type_.COrdinalScaledTypeType.h type_.CRefSemanticType.h \
	type_.CRevisionType.h type_.CRoleClassLibType.h type_.CRoleClassType.h \
	type_.CRoleFamilyType.h type_.CRoleRequirementsType.h type_.CSupportedRoleClassType.h \
	type_.CSystemUnitClassLibType.h type_.CSystemUnitClassType.h type_.CSystemUnitFamilyType.h \
	type_.CUnknownTypeType.h type_.CVersionType.h type_xs.CENTITIES.h type_xs.CENTITY.h \
	type_xs.CID.h type_xs.CIDREF.h type_xs.CIDREFS.h type_xs.CNCName.h type_xs.CNMTOKEN.h \
	type_xs.CNMTOKENS.h type_xs.CNOTATION.h type_xs.CName.h type_xs.CQName.h \
	type_xs.CanySimpleType.h type_xs.CanyType.h type_xs.CanyURI.h type_xs.Cbase64Binary.h \
	type_xs.Cboolean.h type_xs.Cbyte.h type_xs.Cdate.h type_xs.CdateTime.h \
	type_xs.CdateTimeType.h type_xs.Cdecimal.h type_xs.Cdouble.h type_xs.Cduration.h \
	type_xs.Cfloat.h type_xs.CgDay.h type_xs.CgMonth.h type_xs.CgMonthDay.h type_xs.CgYear.h \
	type_xs.CgYearMonth.h type_xs.ChexBinary.h type_xs.Cint.h type_xs.Cinteger.h \
	type_xs.Clanguage.h type_xs.Clong.h type_xs.CnegativeInteger.h \
	type_xs.CnonNegativeInteger.h type_xs.CnonPositiveInteger.h type_xs.CnormalizedString.h \
	type_xs.CpositiveInteger.h type_xs.Cshort.h type_xs.Cstring.h type_xs.CstringType.h \
	type_xs.Ctime.h type_xs.Ctoken.h type_xs.CunsignedByte.h type_xs.CunsignedInt.h \
	type_xs.CunsignedLong.h type_xs.CunsignedShort.h
AM_CXXFLAGS = -fPIC
libCAEX_ClassModel_so_LDFLAGS = -shared
libCAEX_ClassModel_so_LDADD = -L../../xerces-c-src_2_8_0/lib/ -L../Altova \
	-L../AltovaXML -lAltova -lAltovaXML -lxerces-c
noinst_HEADERS = COLLADAReferenceAttributeType.h FrameAttributeType.h \
	FrameValues.h GlobalUID.h LinkedObjects.h LogicReferenceAttributeType.h XMLTools.h

#.cpp.o:
#	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o ./obj/$(@) $<
