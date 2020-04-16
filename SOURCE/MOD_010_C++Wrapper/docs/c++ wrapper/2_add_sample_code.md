# Add sample code
copy the following code in the main.cpp
````
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
#using <AML.Engine.dll>
#using <System.dll>
#using <System.Xml.dll>
#using <System.Xml.Linq.dll>

using namespace Aml::Engine::CAEX;


int main()
{
    std::cout << "Hello World!\n";
	
	auto caexDoc = CAEXDocument::New_CAEXDocument();
	System::Console::WriteLine(caexDoc->CAEXFile->InstanceHierarchy->ToString());
	/*for each (CAEXFileType::InstanceHierarchy ih in caexDoc->CAEXFile->InstanceHierarchy)
	{
		System::Console::WriteLine(string(ih))
	}*/

}
````