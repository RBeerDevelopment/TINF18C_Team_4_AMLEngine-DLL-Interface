# Add sample code
Copy the following code in the main code file.
 This source file is usually opened, and named like the project.  
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
After this we can start compiling the project.

[NEXT PAGE](4_compiling.md)