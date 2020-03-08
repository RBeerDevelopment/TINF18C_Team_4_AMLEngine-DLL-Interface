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
    // create a new empty document
        auto  caexDocument =  CAEXDocument::LoadFromFile("BSM_Project_210219_V3.1.aml");
       CAEXDocument^ doc = CAEXDocument::New_CAEXDocument();
  
    for each(auto instanceHierachy in caexDocument->CAEXFile->InstanceHierarchy){
        for each(auto element in instanceHierachy->InternalElement){
              System::Console::WriteLine( element->Name) ;
               System::Console::WriteLine( "----------------------------------------------------------") ;
              for each(auto ielement in element->InternalElement){  
                    System::Console::WriteLine( ielement->Name) ;

                }
                
        }  

    }
}