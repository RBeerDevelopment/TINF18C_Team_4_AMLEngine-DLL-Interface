# Add sample code
For coding with the AML.Engine.dll, we have to first download the AML library and later import the DLL in our project.


### Downloading the AML.Engine.dll
The AML.Engine.dll library can be downloaded over the integrated downlaod manager called ``NuGet Package Manager``.
In the Visual Stduio Editor open "" [PICTURE]
And search for ``AML.Engine.dll``. Select the version "". And hit install [PICTURE]

### Add C# Code
copy the following code in the main.cpp
````
// include common libraries
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//import AML-Engine
#using <AML.Engine.dll>
#using <System.dll>
#using <System.Xml.dll>
#using <System.Xml.Linq.dll>

using namespace Aml::Engine::CAEX;


int main()
{
    // print "Hello World!" to the console
    std::cout << "Hello World!\n";
	
    // create a new CAEX Document
	auto caexDoc = CAEXDocument::New_CAEXDocument();

    // print the InstanceHierarchy which should be empty
	System::Console::WriteLine(caexDoc->CAEXFile->InstanceHierarchy->ToString());

    //save to an AML-file
    
}
````